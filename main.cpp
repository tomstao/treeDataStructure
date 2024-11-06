#include <iostream>

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int data)
{
    Node* newnode = new Node();
    newnode->data = data;
    newnode->left = newnode->right  = nullptr;
    return newnode;
}

void deleteTree(Node* node)
{
    if (node == nullptr)
        return;
    // Return when it reached the leaf node.

    deleteTree(node->left);
    deleteTree(node->right);
    // Recursively access the left and right node.

    delete node;
    // delete the current node.
}

int main()
{
    Node* root = newNode(1);
    root -> left = newNode(2);
    root -> right = newNode(3);
    root -> left -> left = newNode(4);
    root -> right -> right = newNode(5);
    root -> left -> left -> left = newNode(6);
    root -> right -> right -> right = newNode(7);
    deleteTree(root);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
