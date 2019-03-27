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
vector<int> pre, in;
int n;
struct node {
	int data;
	node* left;
	node* right;
};
node* CreatTree(vector<int> &pre, vector<int> &in, int pl, int pr, int il, int ir) {
	if (pl > pr)	return NULL;
	node* root = new node;
	root->data = pre[pl];//¸ù½Úµã
	root->left = root->right = NULL;
	int pos = 0;
	while (pre[pl] != in[pos]) pos++;
	root->left = CreatTree(pre, in, pl + 1, pl + pos - il, il, pos - 1);
	root->right = CreatTree(pre, in, pl + pos - il + 1, pr, pos + 1, ir);
	return root;
}
int flag = 1;
void postOrder(node* root) {
	if (root == NULL)	return;
	postOrder(root->left);
	postOrder(root->right);
	if (flag) {
		printf("%d", root->data);
		flag = 0;
	}
}
int main() {
	cin >> n;
	pre.resize(n), in.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> pre[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> in[i];
	}
	node* root = CreatTree(pre, in, 0, n - 1, 0, n - 1);
	postOrder(root);
	return 0;
}