#include <iostream>
#include <fstream>
#include <string>

const std::string high_scores_filename = "high_scores.txt";

void write_records(const std::string& user_name, int attempts_count) {
    std::ofstream out_file{high_scores_filename, std::ios_base::app};
    if (!out_file.is_open()) {
        std::cout << "Failed to open file for write: " << high_scores_filename << "!" << std::endl;
        return;
    }
    out_file << user_name << ' ' << attempts_count << std::endl;
}

void read_records() {
    std::ifstream in_file{high_scores_filename};
    if (!in_file.is_open()) {
        std::cout << "Failed to open file for read: " << high_scores_filename << "!" << std::endl;
        return;
    }

    std::cout << "High scores table:" << std::endl;

    std::string username;
    int high_score;
    while (in_file >> username >> high_score) {
        std::cout << username << '\t' << high_score << std::endl;
    }
}
