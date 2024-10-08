#include <cstdio>
#include <iostream>
#include <queue>

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
    // 递归形式
    if(!root) return -1;
    if(!root->left) return root->data;
    return find_min(root->left);
}

int find_max(node* root)
{
    // 递归形式
    if(!root) return -1;
    if(!root->right) return root->data;
    return find_max(root->right);
}

// 遍历输出节点数据，一层一层的输出，使用队列实现
void level_order(node* root)
{
    if(!root) return;
    queue<node*> Q;
    Q.push(root);
    while (!Q.empty())
    {
        node* current = Q.front();
        // 输出节点数据
        cout << current->data<<" ";
        // 左节点入队
        if(current->left) Q.push(current->left);
        // 右节点入队
        if(current->right) Q.push(current->right);
        // 弹出当前节点
        Q.pop();
    }
}

// 前序 D(data) L(left) R(right)
// 先输出当前节点内容，然后递归遍历左子树，然后递归右子树
void preorder(node* root)
{
    if(!root) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

// 中序 L(left) D(data) R(right)
// 先递归左子树，如果没有子树了就输出当前节点，然后在遍历右子树
void inorder(node* root)
{
    if(!root) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

// 后序 L(left) R(right) D(data)
// 先递归左子树，然后在遍历右子树, 如果没有子树了就输出当前节点
void epilogue(node* root)
{
    if(!root) return;
    epilogue(root->left);
    epilogue(root->right);
    cout<<root->data<<" ";
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
    cout << "当前树: \n";
    epilogue(root);
    return 0;
}
