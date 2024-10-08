#include <cstdio>
#include <iostream>

using namespace std;

// the BST node
struct node
{
    int data;
    node* left;
    node* right;
};


node* get_new_node(const int value)
{
    const auto temp = new node();
    temp->data = value;
    temp->left = nullptr;
    temp->right = nullptr;
    return temp;
}

node* insert(node* root, const int value)
{
    if (root == nullptr)
    {
        root = get_new_node(value);
    }
    else if (value <= root->data)
    {
        root->left = insert(root->left, value);
    }
    else
    {
        root->right = insert(root->right, value);
    }
    return root;
}

bool search(const node* root, const int value)
{
    if (root == nullptr) return false;
    if (root->data == value) return true;
    if (value <= root->data) return search(root->left, value);
    return search(root->right, value);
}

int find_height(node* root)
{
    // 空树
    if(!root) return -1;
    
    return max(find_height(root->left),find_height(root->right)) + 1;
}

int main()
{
    node* root = nullptr;
    root = insert(root, 13);
    root = insert(root, 15);
    root = insert(root, 8);
    root = insert(root, 20);
    root = insert(root, 6);
    root = insert(root, 9);
    root = insert(root, 2);
    root = insert(root, 34);
    root = insert(root, 7);
    root = insert(root, 10);
    root = insert(root, 14);
    root = insert(root, 16);
    root = insert(root, 32);
    cout << "当前树最高度: \n";
    const int h = find_height(root);
    cout << h;
    return 0;
}
