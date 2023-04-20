//
// Created by Никита Пеканов on 11.04.2023.
//

#ifndef TASK3NUMBER3_TREENODE_H
#define TASK3NUMBER3_TREENODE_H
#include "iostream"

template<typename T>

class TreeNode {
public:
    T value;
    TreeNode* left;
    TreeNode* right;

    explicit TreeNode(T value){
        this->value = value;
        left = nullptr;
        right = nullptr;
    }


};





#endif //TASK3NUMBER3_TREENODE_H
