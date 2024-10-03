#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <stack>
#include <string>
#include <iostream>

using namespace std;

// 后缀表达式计算
// 字符数组 ab * cd * + e -
// 计算步骤 a*b + c*d - e

bool isOperationSymbol(char symbol) {
	if (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/')  return true;
	return false;
}

int computed(char operation, int num1, int num2) {
	switch (operation) {
	case '+':
		return num2 + num1;
	case '-':
		return num2 - num1;
	case '*':
		return num2 * num1;
	case '/':
		// 注意：这里没有处理除数为0的情况
		if (num1 != 0) {
			return num2 / num1;
		}
		else {
			// 可以返回一个错误码或者抛出异常
			return -1;
		}
	default:
		// 如果传入的不是 +, -, * 或 / 中的一个，返回-1
		return -1;
	}
}

void parse(string str) {
	stack<int> S;
	for (int i = 0; i < str.length(); i++) {
		char temp = str[i];
		if (!isOperationSymbol(str[i])) {
			// 如果不是运算符 将字符压入栈中
			S.push(str[i] - '0');
		}
		else {
			// 第二个操作数 获取最后压入的第一个操作数
			int op1 = S.top();
			// 弹出栈的首位
			S.pop();
			// 获取第一个操作数
			int  op2 = S.top();
			S.pop();
			int res = computed(str[i], op1, op2);
			S.push(res);
		}
	}
	while (!S.empty())
	{
		cout << S.top() << ' ';
		S.pop();
	}
}

int main() {
	//string str = "56*24*+6-" ;
	string str = "42+24*+6-";
	parse(str);
	return 0;
}
