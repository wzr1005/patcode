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
vector<int> arr;
struct node {
	int val;
	struct node *left, *right;
};
node* build(node *root, int v) {
	if (root == NULL) {
		root = new node();
		root->val = v;
		root->left = root->right = NULL;
	}
	else if (abs(v) <= abs(root->val)) {//绝对值别落了
		root->left = build(root->right, v);//往左子树插入
	}
	else {
		root->right = build(root->right, v);//插入到右子树
	}
	return root;
}
bool judge1(node *root) {
	if (root == NULL)	return true;
	if (root->val < 0) {
		if (root->left != NULL && root->left->val < 0)	return false;
		//红结点的孩子不能是红结点
		if (root->right != NULL && root->left->val < 0)	return false;
	}
	return judge1(root->left) && judge1(root->right);
}
int getNum(node* root) {
	if (root == NULL)	return 0;
	int l = getNum(root->left);
	int r = getNum(root->right);
	if (root->val > 0) {
		return max(l, r) + 1;//如果是黑结点，则后序加1
	}
	else return max(l, r);

}
bool judge2(node* root) {
	if (root == NULL)	return true;
	//
	int l = getNum(root->left);
	int r = getNum(root->right);
	if (l != r)	return 0;
	//每个叶子的黑高度都是一样的
	return judge2(root->left) && judge2(root->right);
}
int main() {
	int k, n;
	scanf("%d", &k);//查询个数
	for (int i = 0; i < k; i++) {
		scanf("%d", &n);
		arr.resize(n);
		node *root = NULL;
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[j]);
			root = build(root, arr[j]);//负数代表红节点
		}
		//建完树之后
		if(arr[0] < 0||judge1(root))
	}
	return 0;
}