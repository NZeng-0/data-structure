#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <iostream>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head;

void Insert(int data) {
    Node* temp1 = new Node();
    temp1->data = data;
    temp1->next = NULL;

    // 链表为空时执行
    /*
        链表为空时，将 head
       指向添加的第一个节点，这样后面添加节点时，才能添加到最后
    */
    if (head == NULL) {
        head = temp1;
        return;
    }

    Node* temp2 = head;
    // 逻辑依然是通过temp2=temp2->next进行遍历，但是判断条件改了，当temp2->next!=NULL，就说明到了尾节点

    while (temp2->next != NULL) {
        temp2 = temp2->next;
    }

    temp2->next = temp1;
}

void Print() {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void Delete(int n) {
    Node* temp1 = head;

    if (n == 1) {
        head = temp1->next;
        delete temp1;
        return;
    }

    int i;
    for (i = 0; i < n - 2; i++) {
        temp1 = temp1->next;
    }
      
    Node* temp2 = temp1->next;

    temp1->next = temp2->next;

    delete temp2;
}

int main() {
    head = NULL; // empty list

    Insert(2);
    Insert(4);
    Insert(6);
    Insert(5); // List: 2, 4, 6, 5
    Print();
    int n;
    printf("输入删除的位置\n");
    scanf("%d", &n);
    Delete(n);
    Print();
}