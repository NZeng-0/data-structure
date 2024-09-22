#include <cstddef>
#include <cstdio>
#include <cstdlib>

struct Node
{
    int data;
    struct Node* next;
};

void Print(struct Node* p)
{
    if(p == NULL)
    {
        return;
    }
    Print(p->next);
    printf("%d ", p->data);
}

struct Node* Insert(struct Node* head, int data)
{
    Node* temp = new Node();
    temp->data = data;
    temp->next = NULL;
    if(head == NULL) head = temp;
    else {
        Node* temp1 = head;
        while (temp1->next != NULL) {
            temp1 = temp1->next;
        }
        temp1->next = temp;
    }
    return head;
}

int main(){
    struct Node* head = NULL;
    head = Insert(head, 2);
    head = Insert(head, 5);
    head = Insert(head, 4);
    head = Insert(head, 6);
    Print(head);
}