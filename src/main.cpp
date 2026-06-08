// Copyright 2022 NNTU-CS
#include <iostream>
#include <vector>

#include "tree.h"


int main() {
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

    return 0;
}
