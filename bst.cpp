#include <iostream>
#include <memory>
#include <c++/10/concepts>

#include "bst.h"

// https://github.com/rcpsilva/DesignAndAnalysisofAlgorithms/blob/main/BinarySearchTree.cpp

template <std::totally_ordered T>
class BST
{
    class BSTNode
    {
    public:
        T value;
        std::unique_ptr<BSTNode> left;
        std::unique_ptr<BSTNode> right;

        BSTNode(T v) { value = v; }
    };

public:
    BST() {}

    InsertionInfo insert(T v)
    {
        return insert(v, root);
    }

    SearchInfo search(T v)
    {
        return search(v, root);
    }

    void print()
    {
        print(root);
        std::cout << std::endl;
    }

    void inorder()
    {
        inorder(root);
        std::cout << std::endl;
    }

    void preorder()
    {
        preorder(root);
        std::cout << std::endl;
    }

    void postorder()
    {
        postorder(root);
        std::cout << std::endl;
    }

    int size()
    {
        return size(root);
    }

    void reverse()
    {
        reverse(root);
    }

private:
    std::unique_ptr<BSTNode> root;

    InsertionInfo insert(T v, std::unique_ptr<BSTNode> &node)
    {
        if (!node)
        {
            node = std::make_unique<BSTNode>(v);
            return InsertionInfo::Inserted;
        }

        if (v == node->value)
        {
            return InsertionInfo::AlreadyIn;
        }

        return (v < node->value ? insert(v, node->left) : insert(v, node->right));
    }

    SearchInfo search(T v, std::unique_ptr<BSTNode> &node)
    {
        if (!node)
            return SearchInfo::NotFound;

        if (v == node->value)
            return SearchInfo::Found;

        return (v < node->value ? search(v, node->left) : search(v, node->right));
    }

    void print(std::unique_ptr<BSTNode> &node)
    {
        if (!node)
            return;
        else
        {
            print(node->left);
            std::cout << node->value << "\t";
            print(node->right);
        }
    }

    void inorder(std::unique_ptr<BSTNode> &node)
    {
        if (!node)
            return;
        else
        {
            inorder(node->left);
            std::cout << node->value << " ";
            inorder(node->right);
        }
    }

    void preorder(std::unique_ptr<BSTNode> &node)
    {
        if (!node)
            return;
        else
        {
            std::cout << node->value << " ";
            preorder(node->left);
            preorder(node->right);
        }
    }

    void postorder(std::unique_ptr<BSTNode> &node)
    {
        if (!node)
            return;
        else
        {
            postorder(node->left);
            postorder(node->right);
            std::cout << node->value << " ";
        }
    }

    int size(std::unique_ptr<BSTNode> &node)
    {
        if (!node)
            return 0;
        else
        {
            int left = size(node->left);
            int right = size(node->right);
            return (left > right ? left : right) + 1;
        }
    }

    void reverse(std::unique_ptr<BSTNode> &node)
    {
        if (!node)
            return;
        else
        {
            std::swap(node->left, node->right);

            reverse(node->left);
            reverse(node->right);
        }
    }
};

// int main()
// {
//     BST<int> tree;

//     for (auto i : {5, 3, 7, 1, 4, 6, 10})
//     {
//         std::cout << "insert " << i << ": " << (tree.insert(i) == InsertionInfo::Inserted ? "Inserted" : "AlreadyIn") << std::endl;
//     }

//     // tree.print();
//     tree.inorder();
//     tree.preorder();
//     tree.postorder();

//     // for (auto i : {3, 29, 8, 3, 2, 11, 2})
//     // {
//     //     std::cout << "insert " << i << ": " << (tree.insert(i) == InsertionInfo::Inserted ? "Inserted" : "AlreadyIn") << std::endl;
//     // }

//     // tree.print();

//     // for (auto i : {7, 2, 27})
//     // {
//     //     std::cout << "search " << i << ": " << (tree.search(i) == SearchInfo::Found ? "Found" : "Not Found") << std::endl;
//     // }

//     // std::cout << std::endl << "--------- BST WITH CHARS ----------" << std::endl << std::endl;

//     // BST<char> bst;

//     // for (auto i : {'a', '8', 'd', '!', 'G', '2'})
//     // {
//     //     std::cout << "insert " << i << ": " << (bst.insert(i) == InsertionInfo::Inserted ? "Inserted" : "AlreadyIn") << std::endl;
//     // }

//     // bst.print();

//     // for (auto i : {'7', '!'})
//     // {
//     //     std::cout << "search " << i << ": " << (bst.search(i) == SearchInfo::Found ? "Found" : "Not Found") << std::endl;
//     // }
// }