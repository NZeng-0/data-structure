#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <stack>
#include <string>
#include <iostream>

using namespace std;

int arr[10];

// 指向头部
int front = -1;

// 指向尾部
int rear = -1;

// 判断队列是否为空
bool IsEmpty() {
	if (front == -1 && rear == -1)
		return true;
	else
		return false;
}

// 判断队列是否已满
bool IsFull() {
	if (rear == size(arr))
		return true;
	else
		return false;
}

void Enqueue(int x) {
	// 如果队列已满
	if (IsFull()) {
		printf("队列已满");
		return;
	}
	else if (IsEmpty()) {
		front = rear = 0;
	}
	else {
		rear = (rear + 1) % size(arr);
	}
	arr[rear] = x;
}

void Qequeue() {
	if (IsEmpty()) {
		return;
	}
	else if (front == rear) {
		front = rear = -1;
	}
	else {
		front = (front + 1) % size(arr);
	}
}

int Front() {
	if (IsEmpty())
		return -1;
	else
		return arr[front];
}

void Point() {
	printf("队列：");
	for (int i = front; i < rear + 1; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main() {
	Enqueue(1);  Point();
	Enqueue(8);	 Point();
	Enqueue(2);	 Point();
	Enqueue(7);	 Point();
	Enqueue(4);	 Point();
	printf("第一次出队：1");
	Qequeue(); Point();
	printf("第一次出队：8");
	Qequeue(); Point();
	Enqueue(3);	 Point();
	return 0;
}
