#pragma once
#define UnionSize 100
#define ufset int
//并查集
ufset UFSets[UnionSize];

#include<iostream>
#include<string>
using namespace std;

//将集合S中的每个元素都初始化为只有一个元素的子集合
void Initial(ufset S[]) {
	for (ufset i = 0; i < UnionSize; i++)
	{
		S[i] = -1;
	}
}
//把集合S中的子集合root2并入子集合root1
void Union(ufset S[], int root1, int root2) {
	if (root1 == root2) return;
	S[root2] = root1;
}
//查找集合S中单元素x所在的集合
int Find(ufset S[], int x) {
	while (S[x] >= 0) {
		x = S[x];
	}
	return x;
}