#include<iostream>
#include<string>
#include"List.hpp"
#include"Stack.hpp"
#include"Queue.hpp"
using namespace std;

int main() {
	LinkList L;
	if (List_InitList(L))
		cout << "�����ɹ�" << L->data << endl;
	else
		cout << "����ʧ��" << endl;
	return 0;
}

