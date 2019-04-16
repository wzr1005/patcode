#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 110;
int n, num = 0;
int isroot[maxn] = { 0 };
struct BTnode {
	int lchild, rchild;
}node[maxn];
void print(int id) {
	printf("%d", id);
	++num;
	if (num < n)	printf(" ");
	else	printf("\n");
}
int strTonum(char c) {
	if (c == '-')	return -1;
	else {
		isroot[c - '0'] = 1;
		return c - '0';
	}
}
int findroot() {
	for (int i = 0; i < n; i++) {
		if (isroot[i] == 0)	return i;//返回根结点
	}
}
void postorder(int root) {
	if (root == -1)	return;
	postorder(node[root].lchild);
	postorder(node[root].rchild);
	swap(node[root].lchild, node[root].rchild);
}
void inorder(int root) {
	if (root == -1)	return;
	inorder(node[root].lchild);
	print(root);
	inorder(node[root].rchild);
}
void BFS(int root) {
	queue<int> q;
	q.push(root);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		print(now);
		if (node[now].lchild != -1)	q.push(node[now].lchild);
		if (node[now].rchild != -1)	q.push(node[now].rchild);
	}
}
int main() {
	scanf("%d", &n);
	char lchild, rchild;
	for (int i = 0; i < n; i++) {
		scanf("%*c%c %c", &lchild, &rchild);
		node[i].lchild = strTonum(lchild);
		node[i].rchild = strTonum(rchild);
	}
	int root = findroot();
	postorder(root);
	BFS(root);
	num = 0;
	inorder(root);
	return 0;
}