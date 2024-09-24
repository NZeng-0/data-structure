#include <cstddef>
#include <cstdio>
#include <cstdlib>

#define MAX_SIZE 101

int arr[MAX_SIZE];

int top = -1;

void push(int x) {
    if(top == MAX_SIZE - 1){
        printf("索引超出界线\n");
        return;
    }
    arr[++top] = x;
}

void pop(){
    if(top == -1){
        printf("栈中没有任何元素");
        return;
    }
    top--;
}

int Top(){
    return arr[top];
}

void Print(){
    int i;
    printf("栈：");
    for(i = 0;i<=top;i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    push(2); Print();
    push(5); Print();
    push(10); Print();
    pop(); Print();
    push(12); Print();
}