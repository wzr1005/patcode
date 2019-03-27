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
#include <queue>
#include <ctype.h>
using namespace std;
struct node {
	int data;
	struct node *left, *right;
};
int n, x;
node* root = new node;//新建根结点
vector<int> v;
void init() {//层序遍历建树
	int m = n - 1;//n-1次，
	scanf("%d", &x);
	root->data = x;
	root->left = root->right = NULL;
	queue<node*> q;
	q.push(root);
	while (!q.empty() && m > 0) {
		node* tmp = q.front();
		q.pop();
		if (m > 0) {
			scanf("%d", &x);
			node* k = new node;
			k->data = x;
			k->left = k->right = NULL;
			tmp->left = k;
			m--;
			q.push(k);
		}
		if (m > 0) {
			scanf("%d", &x);
			node* k = new node;
			k->data = x;
			k->left = k->right = NULL;
			tmp->right = k;
			q.push(k);
			m--;
		}
	}
	return;
}
void DFS(node* tree) {
	if (tree->left == NULL && tree->right == NULL) {//到达叶子结点
		for (int i = 0; i < v.size(); i++) {//输出路径
			cout << v[i];
			if (i != v.size() - 1)	cout << " ";
			else cout << "\n";
		}
	}
	if (tree->right != NULL) {
		v.push_back(tree->right->data);//路径中的结点全部进入数组
		DFS(tree->right);
		v.pop_back();
	}
	if (tree->left != NULL) {
		v.push_back(tree->left->data);
		DFS(tree->left);
		v.pop_back();//弹出
	}
}
int check(node* tree) {
	queue<node*> q;
	q.push(tree);
	int big = 0, small = 0;
	while (!q.empty()) {
		node* tmp = q.front();
		q.pop();
		if (tmp->left != NULL) {
			q.push(tmp->left);
			if (tmp->data > tmp->left->data) {
				if (small) {
					return 0;//与之前的矛盾，不是堆结构
				}
				big = 1;//大顶堆的标志
			}
			else {
				if (big)	return 0;
				small = 1;
			}
		}
		if (tmp->right != NULL) {
			q.push(tmp->right);
			if (tmp->data > tmp->right->data) {
				if (small) {//同上
					return 0;
				}
				big = 1;
			}
			else {
				if (big)	return 0;
				small = 1;
			}
		}
	}
	if (big == 1)	return 1;//大顶堆
	if (small == 1)	return 2;//小顶堆
}
int main() {
	scanf("%d", &n);
	init();//层序建树
	v.push_back(root->data);
	DFS(root);
	int k = check(root);
	if (k == 0)	cout << "Not Heap";
	else if (k == 1)	cout << "Max Heap";
	else if (k == 2)	cout << "Min Heap";
	return 0;
}