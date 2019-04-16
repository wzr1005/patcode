#include <cstdio>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <cstring>
#include <vector>
#include <sstream>
#include <queue>
#include <algorithm>
#include <cmath>
#include <ctype.h>
using namespace std;
const int maxn = 110;
int n, in[maxn], num = 0;
struct BTnode {
	int data;
	int lchild, rchild;
}node[maxn];
void inOrder(int root) {
	if (root == -1)	return;
	inOrder(node[root].lchild);
	node[root].data = in[num++];
	inOrder(node[root].rchild);
}
void BFS(int root) {
	queue<int> q;
	q.push(root);
	num = 0;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		printf("%d", node[now].data);
		if (++num < n)	printf(" ");
		if (node[now].lchild != -1)	q.push(node[now].lchild);
		if (node[now].rchild != -1)	q.push(node[now].rchild);
	}
}
int main() {
	scanf("%d", &n);
	int lchild, rchild;
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &lchild, &rchild);
		node[i].lchild = lchild;
		node[i].rchild = rchild;
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &in[i]);
	}
	sort(in, in + n);
	inOrder(0);
	BFS(0);
	return 0;
}