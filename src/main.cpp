// Copyright 2022 NNTU-CS
#include <iostream>
#include <vector>

#include "tree.h"

using namespace std;

int main() {
    vector<char> symbols = {'1', '2', '3'};

    PMTree tree(symbols);
    vector<vector<char>> allPerms = getAllPerms(tree);
    cout << "все перестановки:\n";

    for (size_t i = 0; i < allPerms.size(), i++) {
        cout << i + 1 << ":";

        for (size_t j = 0; j < allPerms[i].size(); j++) {
            cout << allPerms[i][j];
        }

        cout << "\n";
    }

    int num = 2;

    vector<char> perm1 = getPerm1(tree, num);
    vector<char> perm2 = getPerm2(tree, num);
    cout << "\nперестановка №" << num << "\n";

    cout << "способ 1: ";
    for (char c : perm1) {
        cout << c;
    }

    cout << "\nспособ 2: ";
    for (char c : perm2) {
        cout << c;
    }

    cout << "\n";

    return 0;  
}
