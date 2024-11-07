#pragma once

#include<iostream>
#include<string>
#include"Stack.hpp"
using namespace std;

typedef struct BiTNode {
	int data;
	struct BiTNode* lchild, * rchild;
}BiTNode,*BiTree;
//访问函数
void visit(BiTree T){
	cout << T->data << " " << endl;
}
//先序遍历
void PreOrder(BiTree T) {
	if (T != NULL) {
		visit(T);
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}
void PreOrder2(BiTree T) {//相较与中序遍历只需把访问结点放在入栈操作前
	SqStack<BiTree> S{};
	InitStack(S);
	BiTree p = T;
	while (p || !StackEmpty(S)) {
		if (p) {
			visit(p);
			Push(S, p);
			p = p->lchild;
		}
		else {
			Pop(S, p);
			p->rchild;
		}
	}
}
//中序遍历
void InOrder(BiTree T) {
	if (T != NULL) {
		InOrder(T->lchild);
		visit(T);
		InOrder(T->rchild);
	}
}
void InOrder2(BiTree T) {
	SqStack<BiTree> S{};
	InitStack(S);
	BiTree p = T;//p是遍历指针
	while (p || !StackEmpty(S)) {
		if (p) {
			Push(S, p);//一路向左
			p = p->lchild;
		}
		else {//出栈并访问，若有右孩子则右孩子入栈,然后继续出栈
			Pop(S, p);
			visit(p);
			p->rchild;
		}
	}
}
//后序遍历
void PostOrder(BiTree T) {
	if (T != NULL) {
		PostOrder(T->lchild);
		PostOrder(T->rchild);
		visit(T);
	}
}
void PostOrder2(BiTree T) {//比较复杂
	SqStack<BiTree> S{};
	BiTNode* p = T;
	BiTNode* r = NULL;
	while (p || !StackEmpty(S)) {
		if (p) {//走到最左
			Push(S, p);
			p = p->lchild;
		}
		else {									//向右
			GetTop(S, p);						//读栈顶结点
			if (p->rchild && p->rchild != r) {	//若右子树存在且未被访问过
				p = p->rchild;					//转向右
			}									
			else {								//否则弹出结点并访问
				Pop(S, p);						//将结点弹出
				visit(p);						//访问结点
				r = p;							//记录最近访问过的结点
				p = NULL;						//结点访问完后，重置p指针
			}
		}
	}
}
