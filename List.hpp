#pragma once
#define ListMaxSize 100

#include<iostream>
#include<string>
using namespace std;

//线性表
typedef struct List{
	int length;
	int maxsize;

	//初始化
	virtual void InitList() = 0;
	//求表长
	virtual int Length() = 0;
	//按值查找操作
	virtual int LocateElem(int e) = 0;
	//按位查找操作
	virtual int GetElem(int i) = 0;
	//插入操作：在第i个位置插入元素e
	virtual bool ListInsert(int i, int e) = 0;
	//删除操作：删除第i个位置，并返回结果
	virtual bool ListDelete(int i) = 0;
	//输出操作：按前后顺序输出线性表的所有元素
	virtual void PrintList() = 0;
	//判空操作
	virtual bool Empty() = 0;
	//销毁操作
	virtual bool DestroyList() = 0;
};

//顺序表 SequenceList 动态分配
typedef struct seqList : List{
	int *data;
	int MaxSize,length;

	//初始化
	void InitList() {
		this->length = 0;
		this->MaxSize = ListMaxSize;
		this->data = new int[MaxSize];
	}
	//求表长
	int Length() {
		return this->length;
	}
	//按值查找操作
	int LocateElem(int e) {
		for (int i = 0; i < length; i++)
		{
			if(this->data[i] = e){
				return i + 1;
			}
		}
		return 0;
	}
	//按位查找操作
	int GetElem(int i) {
		return this->data[i];
	}
	//插入操作：在第i个位置插入元素e
	bool ListInsert(int i, int e) {
		if ((i <= 0 || i > this->length) || (this->length >= MaxSize)) {
			return false;
		}
		//将第i个元素后元素全部后移
		for (int j = length; j >=i ; j--)
		{
			this->data[j] = this->data[j - 1];
		}
		this->data[i - 1] = e;
		this->length++;
		return true;
	}
	//删除操作：删除第i个位置，并返回该元素
	bool ListDelete(int i) {
		if (i <= 0 || i > this->length)
			return false;
		for (int j = i; j < length; j++)
		{
			this->data[i - 1] = this->data[i];
		}
		this->length--;
		return true;
	}
	//输出操作：按前后顺序输出线性表的所有元素
	void PrintList() {
		for (int i = 0; i < length; i++)
		{
			cout << this->data[0] << " ";
		}
		cout << endl;
	}
	//判空操作
	bool Empty() {
		return this->length == 0;
	}
	//销毁操作
	bool DestroyList() {
		if (this->data != NULL) {
			delete data;
			data = NULL;
		}
		return true;
	}
};

//单链表
typedef struct LNode {//结点类型,同时也是单链表
	int data;
	struct LNode* next;
}*LinkList;
//带头节点的初始化链表
bool List_InitList(LinkList& L) {
	L = new LNode;
	if (L == NULL) 
		return false;
	else 
	{
		L->data = 0;//头结点数据域用于记录表长
		L->next = NULL;
		return true;
	}
}
//用头插法建立链表,输入9999表示结束
LinkList List_HeadInsert(LinkList& L) {
	LNode* s;//插入结点
	int x;
	List_InitList(L);
	cin >> x;
	while (x != 9999) {//输入9999表示结束
		s = new LNode;
		s->data = x;
		s->next = L->next;
		L->next = s;
		cin >> x;
		L->data++;
	}
	return L;
}
//用尾插法建立链表，输入9999表示结束
LinkList List_TailInsert(LinkList& L) {
	int x;
	List_InitList(L);
	LNode* s, * r = L;//r为表尾指针，s为插入结点
	cin >> x;
	while (x != 9999) {
		s = new LNode;
		s->data = x;
		r->next = s;
		r = s;
		cin >> x;
		L->data++;
	}
	r->next = NULL;
	return L;
}
//单链表按序号查找结点
LNode* List_GetElem(LinkList L, int i) {
	if (i < 1) return NULL;
	int j = 1;
	LNode* p = L->next;//第一个结点的指针赋值给p
	while (p != NULL && j < i) {
		p = p->next;
		j++;
	}
	return p;
}
//单链表按值查找结点
LNode* List_LocateElem(LinkList L, int e) {
	LNode* p = L->next;
	while (p != NULL && p->data != e) {
		p = p->next;
	}
	return p;
}
//单链表插入结点，后插法 将x插入到第i个位置上(通常)
bool List_InsertNode_B(LinkList L, int x,int i) {
	LNode* s = new LNode;
	if (s != NULL) s->data = x;
	else return false;

	LNode* p = List_GetElem(L, i - 1);//找插入位置的前驱结点
	if (p == NULL) return false;//若未找到则插入失败
	s->next = p->next;
	p->next = s;

	L->data++;
	return true;
}
//单链表插入结点，前插法
bool List_InsertNode_P(LinkList L, int x, int i) {
	LNode* s = new LNode;
	if (s != NULL)s->data = x;
	else return false;
	//先进行前插操作
	LNode* p = List_GetElem(L, i);//找插入位置的结点
	if (p == NULL) return false;//若未找到则插入失败
	s->next = p->next;
	p->next = s;
	//交换结点的数据
	int temp = s->data;
	s->data = p->data;
	p->data = temp;

	L->data++;
	return true;
}
//删除结点操作
bool List_DeleteNode(LinkList L, int i) {
	//判断合法性
	if (i<1 || i>L->data) return false;

	LNode* p = List_GetElem(L,i - 1);//找到删除结点前一个结点
	LNode* q = p->next;//q为要删除的结点
	p->next = q->next;
	free(q);

	return true;
}
//求表长操作
int List_Length(LinkList& L) {
	return L->data;
}