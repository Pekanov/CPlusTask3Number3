//
// Created by Никита Пеканов on 12.04.2023.
//

#ifndef TEST222_BINARYTREE_H
#define TEST222_BINARYTREE_H


#include <iostream>

template <typename T>
// Определение структуры узла дерева
struct TreeNode {
    T val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(T x) : val(x), left(nullptr), right(nullptr) {}
};

template <typename T>
// Определение класса дерева
class BinaryTree {
public:
    BinaryTree() : root(nullptr) {}

    // Вставка нового узла в дерево
    void insert(T val) {
        TreeNode<T> *newNode = new TreeNode<T>(val);
        if (!root) {
            root = newNode;
            return;
        }
        TreeNode<T> *cur = root;
        while (true) {
            if (val < cur->val) {
                if (!cur->left) {
                    cur->left = newNode;
                    break;
                }
                cur = cur->left;
            } else {
                if (!cur->right) {
                    cur->right = newNode;
                    break;
                }
                cur = cur->right;
            }
        }
    }

    // Поиск узла в дереве
    TreeNode<T> *search(T val) {
        TreeNode<T> *cur = root;
        while (cur) {
            if (val == cur->val) {
                return cur;
            } else if (val < cur->val) {
                cur = cur->left;
            } else {
                cur = cur->right;
            }
        }
        return nullptr;
    }

    // Удаление узла из дерева
    bool remove(T val) {
        TreeNode<T> *cur = root;
        TreeNode<T> *prev = nullptr;
        while (cur) {
            if (val == cur->val) {
                if (!cur->left && !cur->right) { // Если узел не имеет детей
                    if (!prev) {
                        root = nullptr;
                    } else if (prev->left == cur) {
                        prev->left = nullptr;
                    } else {
                        prev->right = nullptr;
                    }
                } else if (!cur->left || !cur->right) { // Если узел имеет только одного ребенка
                    if (!prev) {
                        root = cur->left ? cur->left : cur->right;
                    } else if (prev->left == cur) {
                        prev->left = cur->left ? cur->left : cur->right;
                    } else {
                        prev->right = cur->left ? cur->left : cur->right;
                    }
                } else { // Если узел имеет двух детей
                    TreeNode<T> *next = cur->right;
                    while (next->left) {
                        next = next->left;
                    }
                    cur->val = next->val;
                    val = next->val;
                    prev = cur;
                    cur = cur->right;
                    continue;
                }
                delete cur;
                return true;
            } else if (val < cur->val) {
                prev = cur;
                cur = cur->left;
            } else {
                prev = cur;
                cur = cur->right;
            }
        }
        return false;
    }

    // Печать всех элементов дерева
    void print() {
        print(root);
    }

private:

    void print(TreeNode<T> *cur) {
        if (!cur) {
            return;
        }
        print(cur->left);
        std::cout << cur->val << " ";
        print(cur->right);
    }

    TreeNode<T> *root; // Корень дерева
};

#endif //TEST222_BINARYTREE_H
