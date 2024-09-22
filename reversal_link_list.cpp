#include <cstddef>
#include <cstdio>
#include <cstdlib>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* Reverse(struct Node* head, struct Node* p)
{
    if(p->next == NULL)
    {
        // 如果是最后一个节点，将 head 指向 p
        // p 是最后一个节点
        head = p;
        return head;
    }
    head = Reverse(head, p->next);
    // 获取下一个节点
    struct Node* temp = p->next;
    // 下一个节点指向上一个节点，反转链接
    temp->next = p;
    // 上一个节点的 下一个 属性设置为 NULL 断开链接
    p->next = NULL;
    return head;
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

void Print(struct Node* head)
{
    if(head == NULL) return;
    printf("%d ", head->data);
    Print(head->next);
    printf("\n");
}

int main(){
    struct Node* head = NULL;
    head = Insert(head, 2);
    head = Insert(head, 1);
    head = Insert(head, 4);
    head = Insert(head, 6);
    Print(head);
    head = Reverse(head, head);
    Print(head);
}