#include <cstddef>
#include <cstdio>
#include <cstdlib>

struct Node
{
    int data;
    struct Node* link;
};

struct Node* top = NULL;

void Push(int x)
{
    Node* temp = new Node();
    temp->data = x;
    temp->link = top;
    top = temp;
}

void Pop(){
    Node* temp = new Node();
    if(top == NULL) return;
    temp = top;
    top = top->link;
    delete temp;
}

void Print(){
    Node* p = top;
    printf("栈：");
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->link;
    }
    printf("\n");
}

int main(){
    Push(1); Print();  // 1
    Push(6); Print();  // 6 1
    Push(2); Print();  // 2 6 1
    Push(7); Print();  // 7 2 6 1
    Pop(); Print();    // 2 6 1
    Pop(); Print();    // 6 1
    Push(10); Print(); // 10 6 1
}