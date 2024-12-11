#include <iostream>
#include <vector>
#include <stdexcept>
#include "List.h"
#include "Sequential.h"

int main() {
    try {
        // Последовательный контейнер
        SequentialContainer<int> seqCont;
        for (int i = 0; i < 10; ++i) {
            seqCont.push_back(i);
        }
        seqCont.print();
        std::cout << "Size: " << seqCont.size() << std::endl;

        seqCont.erase(2);
        seqCont.erase(3);
        seqCont.erase(4);
        seqCont.print();

        seqCont.insert(0, 10);
        seqCont.print();

        seqCont.insert(4, 20);
        seqCont.print();

        seqCont.push_back(30);
        seqCont.print();

        // Списковой контейнер
        ListContainer<int> listCont;
        for (int i = 0; i < 10; ++i) {
            listCont.push_back(i);
        }
        listCont.print();
        std::cout << "Size: " << listCont.size() << std::endl;

        listCont.erase(2);
        listCont.erase(3);
        listCont.erase(4);
        listCont.print();

        listCont.insert(0, 10);
        listCont.print();

        listCont.insert(4, 20);
        listCont.print();

        listCont.push_back(30);
        listCont.print();

    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}
