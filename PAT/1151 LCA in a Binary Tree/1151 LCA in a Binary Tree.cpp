#include <cstdio>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <cstring>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <ctype.h>
using namespace std;
int m, n;//m是测试的顶点对，n是总结点数
vector<int> In, Pre;
map<int, int> pos;
void LCA(int inl, int inr, int preRoot, int a, int b) {
	if (inl > inr)	return;
	int inRoot = pos[Pre[preRoot]], aIn = pos[a], bIn = pos[b];//根结点的中序序号，u结点的中序序号，v结点的中序序号
	if (aIn < inRoot&&bIn < inRoot) {//u 和 v 都在根的左边
		LCA(inl, inRoot - 1, preRoot + 1, a, b);//根节点的左子树，即preRoot + 1
		//即递归左子树
	}
	else if ((aIn < inRoot&&bIn > inRoot)||(aIn > inRoot&&bIn < inRoot)) {
		printf("LCA of %d and %d is %d.\n", a, b, In[inRoot]);
	}
	else if (aIn > inRoot&&bIn > inRoot) {//都在根的右边，则递归右子树
		LCA(inRoot + 1, inr, preRoot + inRoot - inl + 1, a, b);//
	}
	else if (aIn == inRoot) {
		printf("%d is an ancestor of %d.\n", a, b);
	}
	else if (bIn == inRoot) {
		printf("%d is an ancestor of %d.\n", b, a);
	}
}
int main() {
	cin >> m >> n;
	In.resize(n + 1), Pre.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> In[i];
		pos[In[i]] = i;//结点的中序顺序存储起来
	}
	for (int i = 1; i <= n; i++) {
		cin >> Pre[i];
	}
	int u, v;
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		if (pos[u] == 0 || pos[v] == 0) {
			if (pos[u] == 0 && pos[v] == 0)	printf("ERROR: %d and %d are not found.\n", u, v);
			else if(pos[u] == 0)	printf("ERROR: %d is not found.\n", u);
			else if(pos[v] == 0)	printf("ERROR: %d is not found.\n", v);
		}
		else {
			LCA(1, n, 1, u, v);//preRoot是1，即先序序列第一个开始，一般也是根节点
		}
	}
	return 0;
}