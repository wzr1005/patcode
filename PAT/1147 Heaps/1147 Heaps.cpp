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
	int date;
	struct node *left, *right;
};
int m, n, x, num = 0;
int c[1010];
void init(node* root) {
	int k = n - 1;
	cin >> x;
	root->date = x;
	root->left = root->right = NULL;
	queue<node*> q;
	q.push(root);
	while (!q.empty()&&k > 0) {
		node *tmp = q.front();
		q.pop();
		if (k > 0) {
			cin >> x;
			k--;
			node* t = new node;
			t->date = x;
			t->left = t->right = NULL;
			tmp->left = t;
			q.push(t);
		}
		if (k > 0) {
			cin >> x;
			node* t = new node;
			k--;
			t->date = x;
			t->left = t->right = NULL;
			tmp->right = t;
			q.push(t);
		}
	}
	return;
}
void judge(node* root) {
	//queue<int> q;
	int big = 0, small = 0;
	queue<node*> q;
	q.push(root);
	while (!q.empty()) {
		node* tmp = q.front();
		q.pop();
		if (tmp->left != NULL) {
			if (tmp->date > tmp->left->date) {
				big = 1;
			}
			else {
				small = 1;
			}
			q.push(tmp->left);
		}
		if (tmp->right != NULL) {
			if (tmp->date > tmp->right->date) {
				big = 1;
			}
			else {
				small = 1;
			}
			q.push(tmp->right);
		}
		if (big&&small) {
			printf("Not Heap\n");
			return;
		}
	}
	if (big) printf("Max Heap\n");
	else printf("Min Heap\n");
}
void postorder(node* root) {
	if (root == NULL) return;
	postorder(root->left);
	postorder(root->right);
	if (num++ != 0) cout << " ";
	printf("%d", root->date);
}
int main() {
	cin >> m >> n;
	while (m--) {
		node* root = new node;
		init(root);
		num = 0;
		judge(root);
		postorder(root);
		printf("\n");
	}
	return 0;
}