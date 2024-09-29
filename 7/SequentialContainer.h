
#include <iostream>
#include <vector>

class SequentialContainer {
private:
    std::vector<int> data;
    
public:
    void push_back(int value) {
        data.push_back(value);
    }

    void insert(int index, int value) {
        if (index >= 0 && index <= data.size()) {
            data.insert(data.begin() + index, value);
        }
    }

    void erase(int index) {
        if (index >= 0 && index < data.size()) {
            data.erase(data.begin() + index);
        }
    }

    int size() const {
        return data.size();
    }

    int& operator[](int index) {
        return data[index];
    }

    void print() const {
        for (int val : data) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
};