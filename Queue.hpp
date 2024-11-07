#pragma once
#define MaxQueueSize 10

#include<iostream>
#include<string>
//顺序存储结构的队列
typedef struct {
	int data[MaxQueueSize];
	int front, rear;
}SqQueue;
//初始化
void InitQueue(SqQueue& Q) {
	Q.rear = Q.rear;
}
//判队空
bool isEmpty(SqQueue& Q) {
	if (Q.rear == Q.front) return true;
	return false;
}
//入队
bool EnQueue(SqQueue& Q, int x) {
	//队满则报错
	if ((Q.rear + 1) % MaxQueueSize == Q.front) return false;

	Q.data[Q.rear] = x;//入队
	Q.rear = (Q.rear + 1) % MaxQueueSize;//队尾指针加一
	return true;
}
//出队
bool DeQueue(SqQueue& Q,int& x) {
	if (Q.rear == Q.front) return false;
	x = Q.data[Q.front];//出栈
	Q.front = (Q.front + 1) % MaxQueueSize;//队头指针加一
	return true;
}

//队列的链式存储结构
typedef struct LinkQNode {//链式队列结点
	int data;
	struct LinkQNode* next;
}LinkQNode;
typedef struct {//链式队列
	LinkQNode* front, * rear;
}LinkQueue;
//初始化
bool Link_InitQueue(LinkQueue& Q) {
	Q.front = Q.rear = new LinkQNode();//建立头结点
	if (Q.front != NULL) {
		Q.front->next = NULL;//初始为空
		return true;
	}
	return false;
}
//判断队空
bool Link_IsEmpty(LinkQueue Q) {
	if (Q.front == Q.rear) return true;
	else return false;
}
//入队 带头结点
bool Link_EnQueue(LinkQueue& Q, int x) {
	LinkQNode* s = new LinkQNode();
	if (s == NULL) {
		return false;
	}
	else {
		s->data = x;
		s->next = NULL;//创建新结点
		Q.rear->next = s;
		Q.rear = s;//插入到链尾
		return true;
	}
}
//出队
bool Link_DeQueue(LinkQueue& Q, int& x) {
	if (Q.front == Q.rear) return false;//队空则报错

	LinkQNode* p = Q.front->next;//p用于指向删除结点
	x = p->data;
	Q.front->next = p->next;
	if (Q.rear == p)//若原队列只有一个结点，删除后变空
		Q.rear = Q.front;
	free(p);
	return true;
}
