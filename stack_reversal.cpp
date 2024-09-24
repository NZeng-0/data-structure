#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

// n 字符数量
void Reverse(char C[], int n){
    stack<char> S;
    for (int i=0; i<n; i++) {
        S.push(C[i]);
    }
    for (int i = 0; i<n; i++) {
        C[i] = S.top();
        S.pop();
    }
}

int main(){
    char C[51];
    printf("输入字符串: ");
    scanf("%s", C);
    Reverse(C, strlen(C));
    printf("输出 = %s", C);
}

struct Node{
    int data;
    struct Node* next;
};

struct Node* head;

/*
    使用栈使用 链表反转
*/
void Reverse(){
    // 如果头节点为null，代表这是一个空链表
    if(head == NULL) return;
    // 使用 cpp 实现的栈
    stack<struct Node*> S;
    // 创建一个临时节点
    Node* temp = head;
    // 如果临时节点不为null，则执行循环
    while(temp != NULL){
        // 向栈中压入一个节点
        S.push(temp);
        // 临时节点地址前移
        temp = temp->next;
    }
    // 循环后将temp指向栈的顶部
    // cpp 会自动解引用
    temp = S.top();
    // head 指向 temp 也指向了栈的顶部
    head = temp;
    // 从栈中弹出一个元素
    S.pop();
    // 如果栈不会空，则执行循环
    while(!S.empty()){
        // temp 下一个指向修改为 栈的顶部
        temp->next = S.top();
        // 从栈顶弹出一个元素
        S.pop();
        // 临时节点前移一位，因为栈弹出了一个顶部节点
        temp = temp->next;
    }
    // 循环后将 next 赋值为 NULL 代表将最后一个节点指向的下一个节点改为 NULL ，表示它是最后一个节点
    temp->next = NULL;
}