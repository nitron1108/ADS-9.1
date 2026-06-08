// Copyright 2022 NNTU-CS
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

#include "tree.h"


int main() {
    srand(time(nullptr));
    std::vector<char> symbols = {'1', '2', '3'};

    PMTree tree(symbols);
    std::vector<std::vector<char>> allPerms = getAllPerms(tree);
    std::cout << "все перестановки:\n";

    for (size_t i = 0; i < allPerms.size(); i++) {
        std::cout << i + 1 << ":";

        for (size_t j = 0; j < allPerms[i].size(); j++) {
            std::cout << allPerms[i][j];
        }

        std::cout << "\n";
    }

    int num = 2;

    std::vector<char> perm1 = getPerm1(tree, num);
    std::vector<char> perm2 = getPerm2(tree, num);
    std::cout << "\nперестановка №" << num << "\n";

    std::cout << "способ 1: ";
    for (char c : perm1) {
        std::cout << c;
    }

    std::cout << "\nспособ 2: ";
    for (char c : perm2) {
        std::cout << c;
    }

    std::cout << "\n";

    std::cout << "\n\nэксперимент:\n";

    for (int n = 2; n <= 8; n++) {
        std::vector<char> testSymbols;

        for (int i = 0; i < n; i++) {
            testSymbols.push_back('A' + i);
        }

        PMTree testTree(testSymbols);

        clock_t start1 = clock();
        getAllPerms(testTree);
        clock_t end1 = clock();
        int totalPerms = 1;
        for (int i = 2; i <= n; i++) {
            totalPerms *= i;
        }

        int randomNum = rand() % totalPerms + 1;
        clock_t start2 = clock();
        getPerm1(testTree, randomNum);
        clock_t end2 = clock();

        clock_t start3 = clock();
        getPerm2(testTree, randomNum);
        clock_t end3 = clock();

        std::cout
        << "n = " << n
        << "  getAllPerms = " << (end1 - start1)
        << "  getPerm1 = " << (end2 - start2)
        << "  getPerm2 = " << (end3 - start3)
        << "\n";


    }
    return 0;

}
