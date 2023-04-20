#include <iostream>
#include "BinaryTree.h"

int main() {
//    BinaryTree<int> tree; // Создание дерева
//    tree.insert(5); // Вставка элементов
//    tree.insert(3);
//    tree.insert(7);
//    tree.insert(1);
//    tree.insert(4);
//    tree.insert(6);
//    tree.insert(8);
//    tree.print();
//
//    std::cout << std::endl;
//
//    TreeNode<int>* node = tree.search(7); // Поиск элемента
//    if (node) {
//        std::cout << "Found " << node->val << std::endl;
//    } else {
//        std::cout << "Not found" << std::endl;
//    }
//
//    tree.remove(3); // Удаление элемента
//    tree.print(); // Печать элементов после удаления
//    std::cout << std::endl;

    BinaryTree<std::string> tree; // Создание дерева
    tree.insert("a"); // Вставка элементов
    tree.insert("f");
    tree.insert("p");
    tree.insert("c");
    tree.insert("x");
    tree.insert("z");
    tree.insert("m");
    tree.print();

    std::cout << std::endl;

    TreeNode<std::string>* node = tree.search("m"); // Поиск элемента
    if (node) {
        std::cout << "Found " << node->val << std::endl;
    } else {
        std::cout << "Not found" << std::endl;
    }

    tree.remove("z"); // Удаление элемента
    tree.print(); // Печать элементов после удаления
    std::cout << std::endl;

    return 0;
}
