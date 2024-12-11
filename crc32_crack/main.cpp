#include <algorithm>
#include <iostream>
#include <limits>
#include <thread>
#include <vector>
#include <atomic>
#include <mutex>

#include "CRC32.hpp"
#include "IO.hpp"

void replaceLastFourBytes(std::vector<char> &data, uint32_t value) {
    std::copy_n(reinterpret_cast<const char *>(&value), 4, data.end() - 4);
}

void safePrint(const std::string &message) {
    static std::mutex mtx;
    std::lock_guard<std::mutex> lock(mtx);
    std::cout << message << std::endl;
}

uint32_t maxVal;

bool findMatchingCrc32InRange(const std::vector<char> &original, const std::vector<char> &baseResult,uint32_t originalCrc32,uint32_t start, uint32_t end,std::vector<char> &result, std::atomic<bool> &found) {
    std::vector<char> localResult = baseResult; 

    for (uint32_t i = start; i < end && !found.load(); ++i) {
        replaceLastFourBytes(localResult, i);
        auto currentCrc32 = crc32(localResult.data(), localResult.size());

        if (currentCrc32 == originalCrc32) {
            result = localResult;
            found.store(true);
            safePrint("Success");
            return true;
        }

        if (i == start + (end - start) / 2) { //вероятно проскочит и не вызовется, но не придумал как выводить без кучи сообщений
            safePrint("Progress: " + std::to_string(i));
        }
    }

    return false;
}

std::vector<char> hack(const std::vector<char> &original, const std::string &injection) {
    const uint32_t originalCrc32 = crc32(original.data(), original.size());

    std::vector<char> result(original.size() + injection.size() + 4);
    auto it = std::copy(original.begin(), original.end(), result.begin());
    std::copy(injection.begin(), injection.end(), it);

    const uint32_t maxVal = std::numeric_limits<uint32_t>::max();
    const unsigned t = std::thread::hardware_concurrency();
    const uint32_t range = maxVal / t;

    std::atomic<bool> found(false);
    std::vector<std::thread> threads;
    std::vector<char> finalResult;

    for (unsigned i = 0; i < t; ++i) {
        uint32_t start = i * range;
        uint32_t end = (i == t - 1) ? maxVal : start + range;

        threads.emplace_back([&, start, end]() {
            findMatchingCrc32InRange(original, result, originalCrc32, start, end, finalResult, found);
        });
    }

    for (auto &thread : threads) {
        thread.join();
    }

    if (!found) {
        throw std::logic_error("Can't hack");
    }

    return finalResult;
}

int main(int argc, char **argv) {
    if (argc != 3) {
        std::cerr << "Call with two args: " << argv[0] << " <input file> <output file>\n";
        return 1;
    }

    try {
        const std::vector<char> data = readFromFile(argv[1]);
        const std::vector<char> badData = hack(data, "He-he-he");
        writeToFile(argv[2], badData);
    } catch (std::exception &ex) {
        std::cerr << ex.what() << '\n';
        return 2;
    }

    return 0;
}
