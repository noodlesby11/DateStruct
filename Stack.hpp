#pragma once
#define MaxStackSize 50

#include<iostream>
#include<string>

template <class T> struct SqStack {
	T data[MaxStackSize];
	int top;//ջ��ָ�룬ջ��ʱΪ-1����ʾջ����ջ��λ��
};
//��ʼ��һ����ջ
template<class T>
void InitStack(SqStack<T>& S) {
	S.top = -1;
}
//�ж�ջ��
template<class T>
bool StackEmpty(SqStack<T> S) {
	if (S.top == -1)
		return true;
	else
		return false;
}
//��ջ
template<class T1,class T2>
bool Push(SqStack<T1>& S, T2 x) {
	if (S.top == MaxStackSize - 1) {
		return false;
	}
	S.data[++S.top] = x;
	return true;
}
//��ջ
template<class T1,class T2>
bool Pop(SqStack<T1>& S, T2& x) {
	if (S.top == -1)
		return false;
	x = S.data[S.top--];
	return true;
}
//��ջ��Ԫ�� ����ջ
template<class T1,class T2>
bool GetTop(SqStack<T1>& S,T2 &x) {
	if (S.top == -1) return false;
	x = S.data[S.top];
	return true;
}
//����ջ