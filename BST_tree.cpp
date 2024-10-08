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
    else if(value <= root->data)
    {
        root->left = insert(root->left, value);
    }
    else
    {
        root->right = insert(root->right, value);
    }
    return root;
}

bool search(node* root, int data)
{
    if (root == nullptr) return false;
    if (root->data == data) return true;
    if (data <= root->data) return search(root->left, data);
    return search(root->right, data);
}

int main()
{
    // the root node
    node* root = nullptr;
    root = insert(root, 13);
    root = insert(root, 15);
    root = insert(root, 8);
    root = insert(root, 20);
    root = insert(root,6);
    root = insert(root,9);
    int number;
    cout << "请输入\n";
    cin >> number;
    if(search(root, number) == true) cout << "找到\n";
    else cout << "未找到";
    return 0;
}
