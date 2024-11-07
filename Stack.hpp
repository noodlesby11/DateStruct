#pragma once
#define MaxStackSize 50

#include<iostream>
#include<string>

template <class T> struct SqStack {
	T data[MaxStackSize];
	int top;//栈顶指针，栈空时为-1，表示栈顶在栈的位置
};
//初始化一个空栈
template<class T>
void InitStack(SqStack<T>& S) {
	S.top = -1;
}
//判断栈空
template<class T>
bool StackEmpty(SqStack<T> S) {
	if (S.top == -1)
		return true;
	else
		return false;
}
//进栈
template<class T1,class T2>
bool Push(SqStack<T1>& S, T2 x) {
	if (S.top == MaxStackSize - 1) {
		return false;
	}
	S.data[++S.top] = x;
	return true;
}
//出栈
template<class T1,class T2>
bool Pop(SqStack<T1>& S, T2& x) {
	if (S.top == -1)
		return false;
	x = S.data[S.top--];
	return true;
}
//读栈顶元素 不出栈
template<class T1,class T2>
bool GetTop(SqStack<T1>& S,T2 &x) {
	if (S.top == -1) return false;
	x = S.data[S.top];
	return true;
}
//销毁栈