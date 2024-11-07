#pragma once
#define UnionSize 100
#define ufset int
//���鼯
ufset UFSets[UnionSize];

#include<iostream>
#include<string>
using namespace std;

//������S�е�ÿ��Ԫ�ض���ʼ��Ϊֻ��һ��Ԫ�ص��Ӽ���
void Initial(ufset S[]) {
	for (ufset i = 0; i < UnionSize; i++)
	{
		S[i] = -1;
	}
}
//�Ѽ���S�е��Ӽ���root2�����Ӽ���root1
void Union(ufset S[], int root1, int root2) {
	if (root1 == root2) return;
	S[root2] = root1;
}
//���Ҽ���S�е�Ԫ��x���ڵļ���
int Find(ufset S[], int x) {
	while (S[x] >= 0) {
		x = S[x];
	}
	return x;
}