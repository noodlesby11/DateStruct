#pragma once
#define MaxQueueSize 10

#include<iostream>
#include<string>
//˳��洢�ṹ�Ķ���
typedef struct {
	int data[MaxQueueSize];
	int front, rear;
}SqQueue;
//��ʼ��
void InitQueue(SqQueue& Q) {
	Q.rear = Q.rear;
}
//�жӿ�
bool isEmpty(SqQueue& Q) {
	if (Q.rear == Q.front) return true;
	return false;
}
//���
bool EnQueue(SqQueue& Q, int x) {
	//�����򱨴�
	if ((Q.rear + 1) % MaxQueueSize == Q.front) return false;

	Q.data[Q.rear] = x;//���
	Q.rear = (Q.rear + 1) % MaxQueueSize;//��βָ���һ
	return true;
}
//����
bool DeQueue(SqQueue& Q,int& x) {
	if (Q.rear == Q.front) return false;
	x = Q.data[Q.front];//��ջ
	Q.front = (Q.front + 1) % MaxQueueSize;//��ͷָ���һ
	return true;
}

//���е���ʽ�洢�ṹ
typedef struct LinkQNode {//��ʽ���н��
	int data;
	struct LinkQNode* next;
}LinkQNode;
typedef struct {//��ʽ����
	LinkQNode* front, * rear;
}LinkQueue;
//��ʼ��
bool Link_InitQueue(LinkQueue& Q) {
	Q.front = Q.rear = new LinkQNode();//����ͷ���
	if (Q.front != NULL) {
		Q.front->next = NULL;//��ʼΪ��
		return true;
	}
	return false;
}
//�ж϶ӿ�
bool Link_IsEmpty(LinkQueue Q) {
	if (Q.front == Q.rear) return true;
	else return false;
}
//��� ��ͷ���
bool Link_EnQueue(LinkQueue& Q, int x) {
	LinkQNode* s = new LinkQNode();
	if (s == NULL) {
		return false;
	}
	else {
		s->data = x;
		s->next = NULL;//�����½��
		Q.rear->next = s;
		Q.rear = s;//���뵽��β
		return true;
	}
}
//����
bool Link_DeQueue(LinkQueue& Q, int& x) {
	if (Q.front == Q.rear) return false;//�ӿ��򱨴�

	LinkQNode* p = Q.front->next;//p����ָ��ɾ�����
	x = p->data;
	Q.front->next = p->next;
	if (Q.rear == p)//��ԭ����ֻ��һ����㣬ɾ������
		Q.rear = Q.front;
	free(p);
	return true;
}
