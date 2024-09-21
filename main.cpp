#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <iostream>

struct Node{
    int data;
    struct Node* next;
};

// 全局变量
struct Node* head;

void Insert(int x){
    Node* temp = (Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = head;
    head = temp;
}
void Print(){
    struct Node * temp = head;
    printf("链表是: ");
    while(temp != NULL){
        printf(" %d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    // 指针不指向任何变量 链表是空的
    head = NULL;
    printf("你想要多少个数字\n");
    int n,i,x;
    scanf("%d", &n);
    for(i = 0;i<n;i++){
        printf("输入一个数字\n");
        scanf("%d",&x);
        Insert(x);
        Print();
    }
}
