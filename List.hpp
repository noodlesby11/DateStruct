#pragma once
#define ListMaxSize 100

#include<iostream>
#include<string>
using namespace std;

//���Ա�
typedef struct List{
	int length;
	int maxsize;

	//��ʼ��
	virtual void InitList() = 0;
	//���
	virtual int Length() = 0;
	//��ֵ���Ҳ���
	virtual int LocateElem(int e) = 0;
	//��λ���Ҳ���
	virtual int GetElem(int i) = 0;
	//����������ڵ�i��λ�ò���Ԫ��e
	virtual bool ListInsert(int i, int e) = 0;
	//ɾ��������ɾ����i��λ�ã������ؽ��
	virtual bool ListDelete(int i) = 0;
	//�����������ǰ��˳��������Ա������Ԫ��
	virtual void PrintList() = 0;
	//�пղ���
	virtual bool Empty() = 0;
	//���ٲ���
	virtual bool DestroyList() = 0;
};

//˳��� SequenceList ��̬����
typedef struct seqList : List{
	int *data;
	int MaxSize,length;

	//��ʼ��
	void InitList() {
		this->length = 0;
		this->MaxSize = ListMaxSize;
		this->data = new int[MaxSize];
	}
	//���
	int Length() {
		return this->length;
	}
	//��ֵ���Ҳ���
	int LocateElem(int e) {
		for (int i = 0; i < length; i++)
		{
			if(this->data[i] = e){
				return i + 1;
			}
		}
		return 0;
	}
	//��λ���Ҳ���
	int GetElem(int i) {
		return this->data[i];
	}
	//����������ڵ�i��λ�ò���Ԫ��e
	bool ListInsert(int i, int e) {
		if ((i <= 0 || i > this->length) || (this->length >= MaxSize)) {
			return false;
		}
		//����i��Ԫ�غ�Ԫ��ȫ������
		for (int j = length; j >=i ; j--)
		{
			this->data[j] = this->data[j - 1];
		}
		this->data[i - 1] = e;
		this->length++;
		return true;
	}
	//ɾ��������ɾ����i��λ�ã������ظ�Ԫ��
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
	//�����������ǰ��˳��������Ա������Ԫ��
	void PrintList() {
		for (int i = 0; i < length; i++)
		{
			cout << this->data[0] << " ";
		}
		cout << endl;
	}
	//�пղ���
	bool Empty() {
		return this->length == 0;
	}
	//���ٲ���
	bool DestroyList() {
		if (this->data != NULL) {
			delete data;
			data = NULL;
		}
		return true;
	}
};

//������
typedef struct LNode {//�������,ͬʱҲ�ǵ�����
	int data;
	struct LNode* next;
}*LinkList;
//��ͷ�ڵ�ĳ�ʼ������
bool List_InitList(LinkList& L) {
	L = new LNode;
	if (L == NULL) 
		return false;
	else 
	{
		L->data = 0;//ͷ������������ڼ�¼��
		L->next = NULL;
		return true;
	}
}
//��ͷ�巨��������,����9999��ʾ����
LinkList List_HeadInsert(LinkList& L) {
	LNode* s;//������
	int x;
	List_InitList(L);
	cin >> x;
	while (x != 9999) {//����9999��ʾ����
		s = new LNode;
		s->data = x;
		s->next = L->next;
		L->next = s;
		cin >> x;
		L->data++;
	}
	return L;
}
//��β�巨������������9999��ʾ����
LinkList List_TailInsert(LinkList& L) {
	int x;
	List_InitList(L);
	LNode* s, * r = L;//rΪ��βָ�룬sΪ������
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
//��������Ų��ҽ��
LNode* List_GetElem(LinkList L, int i) {
	if (i < 1) return NULL;
	int j = 1;
	LNode* p = L->next;//��һ������ָ�븳ֵ��p
	while (p != NULL && j < i) {
		p = p->next;
		j++;
	}
	return p;
}
//������ֵ���ҽ��
LNode* List_LocateElem(LinkList L, int e) {
	LNode* p = L->next;
	while (p != NULL && p->data != e) {
		p = p->next;
	}
	return p;
}
//����������㣬��巨 ��x���뵽��i��λ����(ͨ��)
bool List_InsertNode_B(LinkList L, int x,int i) {
	LNode* s = new LNode;
	if (s != NULL) s->data = x;
	else return false;

	LNode* p = List_GetElem(L, i - 1);//�Ҳ���λ�õ�ǰ�����
	if (p == NULL) return false;//��δ�ҵ������ʧ��
	s->next = p->next;
	p->next = s;

	L->data++;
	return true;
}
//����������㣬ǰ�巨
bool List_InsertNode_P(LinkList L, int x, int i) {
	LNode* s = new LNode;
	if (s != NULL)s->data = x;
	else return false;
	//�Ƚ���ǰ�����
	LNode* p = List_GetElem(L, i);//�Ҳ���λ�õĽ��
	if (p == NULL) return false;//��δ�ҵ������ʧ��
	s->next = p->next;
	p->next = s;
	//������������
	int temp = s->data;
	s->data = p->data;
	p->data = temp;

	L->data++;
	return true;
}
//ɾ��������
bool List_DeleteNode(LinkList L, int i) {
	//�жϺϷ���
	if (i<1 || i>L->data) return false;

	LNode* p = List_GetElem(L,i - 1);//�ҵ�ɾ�����ǰһ�����
	LNode* q = p->next;//qΪҪɾ���Ľ��
	p->next = q->next;
	free(q);

	return true;
}
//�������
int List_Length(LinkList& L) {
	return L->data;
}