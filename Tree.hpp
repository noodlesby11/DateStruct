#pragma once

#include<iostream>
#include<string>
#include"Stack.hpp"
using namespace std;

typedef struct BiTNode {
	int data;
	struct BiTNode* lchild, * rchild;
}BiTNode,*BiTree;
//���ʺ���
void visit(BiTree T){
	cout << T->data << " " << endl;
}
//�������
void PreOrder(BiTree T) {
	if (T != NULL) {
		visit(T);
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}
void PreOrder2(BiTree T) {//������������ֻ��ѷ��ʽ�������ջ����ǰ
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
//�������
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
	BiTree p = T;//p�Ǳ���ָ��
	while (p || !StackEmpty(S)) {
		if (p) {
			Push(S, p);//һ·����
			p = p->lchild;
		}
		else {//��ջ�����ʣ������Һ������Һ�����ջ,Ȼ�������ջ
			Pop(S, p);
			visit(p);
			p->rchild;
		}
	}
}
//�������
void PostOrder(BiTree T) {
	if (T != NULL) {
		PostOrder(T->lchild);
		PostOrder(T->rchild);
		visit(T);
	}
}
void PostOrder2(BiTree T) {//�Ƚϸ���
	SqStack<BiTree> S{};
	BiTNode* p = T;
	BiTNode* r = NULL;
	while (p || !StackEmpty(S)) {
		if (p) {//�ߵ�����
			Push(S, p);
			p = p->lchild;
		}
		else {									//����
			GetTop(S, p);						//��ջ�����
			if (p->rchild && p->rchild != r) {	//��������������δ�����ʹ�
				p = p->rchild;					//ת����
			}									
			else {								//���򵯳���㲢����
				Pop(S, p);						//����㵯��
				visit(p);						//���ʽ��
				r = p;							//��¼������ʹ��Ľ��
				p = NULL;						//�������������pָ��
			}
		}
	}
}
