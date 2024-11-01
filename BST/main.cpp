#include <iostream>
#include "BinarySearchTree.h"

int main(){
    BinarySearchTree<int> bst1;
    bst1.insert(6);
    bst1.insert(8);
    bst1.insert(2);
    bst1.insert(1);
    bst1.insert(5);
    bst1.insert(3);
    bst1.insert(4);
    bst1.insert(9);
    bst1.insert(10);
    std::cout << "build a three" << std::endl;
    bst1.printTree();
    bst1.remove(8);
    std::cout << "remove 8 - a specific case" << std::endl;
    bst1.printTree();
    std::cout << "output to check" << std::endl;
    bst1.remove(2);
    std::cout << "remove 2 - a normal case" << std::endl;
    bst1.printTree();
    std::cout << "output to check" << std::endl;
    bst1.remove(6);
    std::cout << "remove 6(root) - a specific case" << std::endl;
    bst1.printTree();
    std::cout << "output to check" << std::endl;
    return 0;

}