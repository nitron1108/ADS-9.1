// Copyright 2022 NNTU-CS
#include <iostream>
#include <fstream>
#include <locale>
#include <cstdlib>
#include "tree.h"
#include <algorithm>

PMTree::PMTree(const std::vector<char>& symbols) {
    root = new Node('\0');
    size = symbols.size();

    std::vector<char> sorted = symbols;
    std::sort(sorted.begin(), sorted.end());

    build(root, sorted);
}

PMTree::~PMTree() {
    clear(root);
}

Node* PMTree::getRoot() const {
    return root;
}

int PMTree::getSize() const {
    return size;
}

void PMTree::build(Node* node, std::vector<char> symbols) {
    for (size_t i = 0; i < symbols.size(); i++) {
        Node* child = new Node(symbols[i]);
        std::vector<char> rest = symbols;
        rest.erase(rest.begin() + i);

        build(child, rest);
        node->children.push_back(child);
    }
}

void PMTree::clear(Node* node) {
    if (!node) {
        return;
    }

    for (size_t i = 0; i < node->children.size(); i++) {
        clear(node->children[i]);
    }
    delete node;
}

static void collect(Node* node, std::vector<char>& current,std::vector<std::vector<char>>& result) {
    if (!node) {
        return;
    }

    if (node->value != '\0') {
        current.push_back(node->value);
    }

    if (node->children.empty()) {
        result.push_back(current);
    } else {
        for (size_t i = 0; i < node->children.size(); i++) {
            collect(node->children[i], current, result);
        }
    }

    if (node->value != '\0') {
        current.pop_back();
    }
}

std::vector<std::vector<char>> getAllPerms(PMTree& tree) {
  std::vector<std::vector<char>> result;
  std::vector<char> current;
  collect(tree.getRoot(), current, result);
  return result;
}

std::vector<char> getPerm1(PMTree& tree, int num) {
  std::vector<std::vector<char>> all = getAllPerms(tree);

  if (num <= 0 || num > static_cast<int>(all.size())) {
    return std::vector<char>();
  }

  return all[num - 1];
}

static int factorial(int n) {
  int result = 1;

  for (int i = 2; i <= n; i++) {
    result *= i;
  }

  return result;
}

std::vector<char> getPerm2(PMTree& tree, int num) {
  if (num <= 0) {
    return std::vector<char>();
  }

  Node* root = tree.getRoot();
  if (!root) {
    return std::vector<char>();
  }

  int n = tree.getSize();
  int total = factorial(n);

  if (num > total) {
    return std::vector<char>();
  }

  std::vector<char> available;
  for (size_t i = 0; i < root->children.size(); i++) {
    available.push_back(root->children[i]->value);
  }

  std::vector<char> result;
  int index = num - 1;

  for (int i = n; i >= 1; i--) {
    int block = factorial(i - 1);
    int pos = index / block;

    result.push_back(available[pos]);
    available.erase(available.begin() + pos);

    index %= block;
  }

  return result;
}
