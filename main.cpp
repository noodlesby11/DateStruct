#include<iostream>
#include<string>
#include"List.hpp"
#include"Stack.hpp"
#include"Queue.hpp"
using namespace std;

int main() {
	LinkList L;
	if (List_InitList(L))
		cout << "创建成功" << L->data << endl;
	else
		cout << "创建失败" << endl;
	return 0;
}

