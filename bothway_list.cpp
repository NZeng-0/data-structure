#include <cstddef>
#include <cstdio>
#include <cstdlib>


struct Node
{
    int data;
    // 指向下一个节点
    struct Node* next;
    // 指向上一个节点
    struct Node* prev;
};

// 全局变量，始终指向头节点
struct Node* head;

struct Node* CreateNode(int x)
{
    Node* newNode = new Node();
    newNode->data = x;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}


/**
 * 插入到头节点
 */
void Insert(int x)
{
  
    Node* newNode = CreateNode(x);
    if(head == NULL) head = newNode;
    else
    {
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }
}
/* 
插入到尾节点

    // 链表的头节点
    struct Node* head = NULL;
    // 链表的尾节点
    struct Node* tail = NULL;

    void Insert(int x) {

        Node* newNode = CreateNode(x);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
 */

void Print()
{
    Node* temp = head;
    printf("forward: ");
    while(temp != NULL )
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void ReversePrint()
{
    Node* temp = head;
    if(temp == NULL) return;
    while(temp->next != NULL){
        temp = temp->next;
    }


    printf("reverse: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

int main()
{
    head = NULL;
    Insert(2);
    Insert(5);
    Insert(4);
    Insert(6);
    Print();
}