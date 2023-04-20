//
// Created by Никита Пеканов on 11.04.2023.
//

#ifndef TASK3NUMBER3_BINARYTREE_H
#define TASK3NUMBER3_BINARYTREE_H
#include "iostream"
#include "TreeNode.h"

template <typename T>

class BinaryTree {

private:
    TreeNode<T> root;
    void print(TreeNode<T>* current){
        if (!current) {
            return;
        }
        print(current->left);
        std::cout << current->val << " ";
        print(current->right);
    }

public:
    BinaryTree(){
        root = nullptr;
    }

    void insert(T value){
        TreeNode<T>* newNode = new TreeNode<T>(value);
        if (!root) {
            root = newNode;
            return;
        }

        TreeNode<T>* current = root;
        while (true) {
            if (value < current->value) {
                if (!current->left) {
                    current->left = newNode;
                    break;
                }
                current = current->left;
            } else {
                if (!current->right) {
                    current->right = newNode;
                    break;
                }
                current = current->right;
            }
        }
    }
    TreeNode<T>* search(T value){
        TreeNode<T>* current = root;
        while (current) {
            if (value == current->value) {
                return current;
            } else if (value < current->value) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
        return nullptr;
    }
    bool remove(T value){
        TreeNode<T>* current = root;
        TreeNode<T>* prev = nullptr;
        while (current) {
            if (value == current->value) {
                if (!current->left && !current->right) { // Если узел не имеет детей
                    if (!prev) {
                        root = nullptr;
                    } else if (prev->left == current) {
                        prev->left = nullptr;
                    } else {
                        prev->right = nullptr;
                    }
                } else if (!current->left || !current->right) { // Если узел имеет только одного ребенка
                    if (!prev) {
                        root = current->left ? current->left : current->right;
                    } else if (prev->left == current) {
                        prev->left = current->left ? current->left : current->right;
                    } else {
                        prev->right = current->left ? current->left : current->right;
                    }
                } else { // Если узел имеет двух детей
                    TreeNode<T>* next = current->right;
                    while (next->left) {
                        next = next->left;
                    }
                    current->value = next->value;
                    value = next->value;
                    prev = current;
                    current = current->right;
                    continue;
                }
                delete current;
                return true;
            } else if (value < current->value) {
                prev = current;
                current = current->left;
            } else {
                prev = current;
                current = current->right;
            }
        }
        return false;
    }
    void print(){
        print(root);
    }


};

//template<typename T>
//BinaryTree<T>::BinaryTree() {
//    root = nullptr;
//}



//template<typename T>
//TreeNode<T> *BinaryTree<T>::search(T value) {
//
//    TreeNode<T>* current = root;
//    while (current) {
//        if (value == current->value) {
//            return current;
//        } else if (value < current->value) {
//            current = current->left;
//        } else {
//            current = current->right;
//        }
//    }
//    return nullptr;
//
//}

//template<typename T>
//bool BinaryTree<T>::remove(T value) {
//    TreeNode<T>* current = root;
//    TreeNode<T>* prev = nullptr;
//    while (current) {
//        if (value == current->value) {
//            if (!current->left && !current->right) { // Если узел не имеет детей
//                if (!prev) {
//                    root = nullptr;
//                } else if (prev->left == current) {
//                    prev->left = nullptr;
//                } else {
//                    prev->right = nullptr;
//                }
//            } else if (!current->left || !current->right) { // Если узел имеет только одного ребенка
//                if (!prev) {
//                    root = current->left ? current->left : current->right;
//                } else if (prev->left == current) {
//                    prev->left = current->left ? current->left : current->right;
//                } else {
//                    prev->right = current->left ? current->left : current->right;
//                }
//            } else { // Если узел имеет двух детей
//                TreeNode<T>* next = current->right;
//                while (next->left) {
//                    next = next->left;
//                }
//                current->value = next->value;
//                value = next->value;
//                prev = current;
//                current = current->right;
//                continue;
//            }
//            delete current;
//            return true;
//        } else if (value < current->value) {
//            prev = current;
//            current = current->left;
//        } else {
//            prev = current;
//            current = current->right;
//        }
//    }
//    return false;
//}

//template<typename T>
//void BinaryTree<T>::print() {
//    print(root);
//}

//template<typename T>
//void BinaryTree<T>::print(TreeNode<T> *current) {
//    if (!current) {
//        return;
//    }
//    print(current->left);
//    std::cout << current->val << " ";
//    print(current->right);
//}


#endif //TASK3NUMBER3_BINARYTREE_H
