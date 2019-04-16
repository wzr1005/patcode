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
struct BTnode {
	int v, height;
	BTnode *lchild, *rchild;
}*root;
int getHeight(BTnode* root) {
	if (root == NULL)	return 0;
	return root->height;
}
void updataHeight(BTnode* root) {
	root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
}
int getBalance(BTnode* root) {
	return getHeight(root->lchild) - getHeight(root->rchild);
}
void L(BTnode* &root) {
	BTnode* temp = root->rchild;
	root->rchild = temp->lchild;
	temp->lchild = root;
	updataHeight(root);
	updataHeight(temp);
	root = temp;
}
void R(BTnode* &root) {
	BTnode *temp = root->lchild;
	root->lchild = temp->rchild;
	temp->rchild = root;
	updataHeight(root);
	updataHeight(temp);
	root = temp;
}
void insert(BTnode* &root, int v) {
	if (root == NULL) {
		root = new BTnode;
		root->v = v;
		root->height = 1;
		root->lchild = root->rchild = NULL;
		return;
	}
	if (v < root->v) {
		insert(root->lchild, v);
		updataHeight(root);
		if (getBalance(root) == 2) {//左高
			if (getBalance(root->lchild) == 1) {//LL型
				//右旋
				R(root);
			}
			else if (getBalance(root->lchild) == -1) {
				//LR型 先L变成LL 再R
				L(root->lchild);
				R(root);
			}
		}
	}
	else {
		insert(root->rchild, v);
		updataHeight(root);
		if (getBalance(root) == -2) {//右高
			if (getBalance(root->rchild) == -1) {
				//RR型
				L(root);
			}
			else if (getBalance(root->rchild) == 1) {
				//RL型
				R(root->rchild);//R旋转变成RR型
				L(root);//RR左旋
			}
		}
	}
}
int main() {
	int n, v;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &v);
		insert(root, v);
	}
	printf("%d\n", root->v);
	return 0;
}