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

int find_min(node* root)
{
    // if (root == nullptr) return -1;
    // while (root->left)
    // {
    //     root = root->left;
    // }
    // return root->data;

    // 递归形式
    if(!root) return -1;
    if(!root->left) return root->data;
    return find_min(root->left);
}

int find_max(node* root)
{
    // if(!root) return -1;
    // while (root->right)
    // {
    //     root = root->right;
    // }
    // return root->data;

    // 递归形式
    if(!root) return -1;
    if(!root->right) return root->data;
    return find_max(root->right);
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
    cout << "当前树最大值: \n";
    const int max = find_min(root);
    cout << max;
    return 0;
}
