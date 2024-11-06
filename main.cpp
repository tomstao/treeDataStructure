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

void preorder(Node* node)
{
    if (node == nullptr)
        return;
    std::cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
}

void inorder(Node* node)
{
    if (node == nullptr)
        return;
    inorder(node->left);
    std::cout << node->data << " ";
    inorder(node->right);
}

void postorder(Node* node)
{
    if (node == nullptr)
        return;
    postorder(node->left);
    postorder(node->right);
    std::cout << node->data << " ";
}

int main()
{
    Node* root = newNode(1);
    // level 1
    root -> left = newNode(2);
    root -> right = newNode(3);
    // level 2
    root -> left -> left = newNode(4);
    root -> left -> right = newNode(5);
    root -> right -> left = newNode(6);
    root -> right -> right = newNode(7);
    // level 3
    root -> left -> right -> left = newNode(9);
    root -> right -> right -> left = newNode(15);

    std::cout << "Preorder:" <<std::endl;
    preorder(root);
    std::cout << std::endl;
    std::cout << "Inorder:" <<std::endl;
    inorder(root);
    std::cout << std::endl;
    std::cout << "Postorder:" <<std::endl;
    postorder(root);
    std::cout << std::endl;

    deleteTree(root);
    return 0;
}
