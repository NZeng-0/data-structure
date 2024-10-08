#include <cstdio>
#include <iostream>

using namespace std;

struct node
{
    int data;
    node* next;
};

// 指向前端的节点
node* front = nullptr;

// 指向后端的节点
node* rear = nullptr;

void en_queue(const int x)
{
    const auto temp = new node();
    temp->data = x;
    temp->next = nullptr;
    // 如果 front 和 rear 都是 null 代表当前队列为空
    if (front == nullptr && rear == nullptr)
    {
        // 前 后 节点都指向 temp，因为现在 temp 是第一个节点
        front = rear = temp;
        return;
    }
    // 后端节点的下一个节点指向新添加的节点
    rear->next = temp;

    // 将新添加的节点作为后端节点
    rear = temp;
}

void de_queue()
{
    // 如果前端节点等于 null
    if (front == nullptr) return;
    // 如果前端节点等于后端节点 代表当前队列只有一个元素
    if (front == rear)
    {
        front = rear = nullptr;
    }
    else
    {
        // front 指向 front 的下一个节点
        front = front->next;
    }
}

void print()
{
    const node* temp = front;
    printf("队列：");
    while (temp)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    en_queue(3); print();
    en_queue(6); print();
    en_queue(9); print();
    en_queue(2); print();

    de_queue();  print();
    en_queue(5); print();
    de_queue();  print();
    return 0;
}
