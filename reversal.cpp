#include <cstddef>
#include <cstdio>
#include <cstdlib>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* Reverse(struct Node* head)
{
    struct Node *current, *prev, *next;
    current = head;
    prev = NULL;
    while (current != NULL) {
        // 获取链表下一个元素
        next = current->next;
        // 当前节点链接的下一个节点置空
        current->next = prev;
        // 将当前节点作为上一个节点，下次循环时作为下一个节点使用
        prev = current;
        // 当前节点前移
        current = next;
    }
    // 将上一个节点的指针赋值给head
    head = prev;
    // 返回 head
    return head;
}

struct Node* Insert(struct Node* head, int data)
{
    // Node* temp = new Node();
    // temp->data = data;
    // temp->next = head;
    // head = temp;
    // return head;
    Node* temp = new Node();
    temp->data = data;
    temp->next = NULL;
    if(head == NULL)
    {
        head = temp;
    }
    else
    {
        Node* temp1 = head;
        while(temp1->next != NULL)
        {
            temp1 = temp1->next;
        }
        temp1->next = temp;
    }
    return head;
}

void Print(struct Node* head)
{
    while(head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main()
{
    struct Node* head;

    head = NULL; // empty list
    head = Insert(head, 2);
    head = Insert(head, 4);
    head = Insert(head, 6);
    head = Insert(head, 5);
    Print(head);
    head = Reverse(head);
    Print(head);
}
