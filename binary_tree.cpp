#include "bst.cpp"
#include <iostream>

int main()
{
    BST<int> tree;

    for (auto i : {5, 3, 7, 1, 4, 6, 10})
    {
        std::cout << "insert " << i << ": " << (tree.insert(i) == InsertionInfo::Inserted ? "Inserted" : "AlreadyIn") << std::endl;
    }

    // tree.print();
    tree.inorder();
    tree.preorder();
    tree.postorder();

    std::cout << "size: " << tree.size() << std::endl;

    tree.reverse();
    tree.inorder();

    // for (auto i : {3, 29, 8, 3, 2, 11, 2})
    // {
    //     std::cout << "insert " << i << ": " << (tree.insert(i) == InsertionInfo::Inserted ? "Inserted" : "AlreadyIn") << std::endl;
    // }

    // tree.print();

    // for (auto i : {7, 2, 27})
    // {
    //     std::cout << "search " << i << ": " << (tree.search(i) == SearchInfo::Found ? "Found" : "Not Found") << std::endl;
    // }

    // std::cout << std::endl << "--------- BST WITH CHARS ----------" << std::endl << std::endl;

    // BST<char> bst;

    // for (auto i : {'a', '8', 'd', '!', 'G', '2'})
    // {
    //     std::cout << "insert " << i << ": " << (bst.insert(i) == InsertionInfo::Inserted ? "Inserted" : "AlreadyIn") << std::endl;
    // }

    // bst.print();

    // for (auto i : {'7', '!'})
    // {
    //     std::cout << "search " << i << ": " << (bst.search(i) == SearchInfo::Found ? "Found" : "Not Found") << std::endl;
    // }
}