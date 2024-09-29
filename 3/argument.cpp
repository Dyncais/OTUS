#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "high_scores.h"

int main() {
    std::srand(std::time(nullptr));

    std::string user_name;
    std::cout << "Hi! Enter your name, please:" << std::endl;
    std::cin >> user_name;

    const int max_value = 100;
    const int random_value = std::rand() % max_value;

    int attempts_count = 0;
    int current_value = 0;

    std::cout << "Enter your guess:" << std::endl;
    
    do {
        std::cin >> current_value;
        attempts_count++;  

        if (current_value > random_value) {
            std::cout << "less than " << current_value << std::endl;
        } else if (current_value < random_value) {
            std::cout << "greater than " << current_value << std::endl;
        } else {
            std::cout << "you win! attempts = " << attempts_count << std::endl;
            break;
        }

    } while (true);

    write_records(user_name, attempts_count);
    
    read_records();

    return 0;
}
