#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
struct BTnode {
	int data;
	BTnode* lchild, *rchild;
};
void insert(BTnode* &root, int data) {
	if (root == NULL) {
		root = new BTnode;
		root->data = data;
		root->lchild = root->rchild = NULL;
		return;
	}
	if (data < root->data)	insert(root->lchild, data);
	else insert(root->rchild, data);
}
void preOrder(BTnode *root, vector<int>& vi) {
	if (root == NULL)	return;
	vi.push_back(root->data);
	preOrder(root->lchild, vi);
	preOrder(root->rchild, vi);
}
void preOrderMirror(BTnode* root, vector<int>& vi) {
	if (root == NULL)	return;
	vi.push_back(root->data);
	preOrderMirror(root->rchild, vi);
	preOrderMirror(root->lchild, vi);
}
void postOrder(BTnode *root, vector<int>& vi) {
	if (root == NULL)	return;
	postOrder(root->lchild, vi);
	postOrder(root->rchild, vi);
	vi.push_back(root->data);
}
void postOrderMirror(BTnode *root, vector<int>& vi) {
	if (root == NULL)	return;
	postOrderMirror(root->rchild, vi);
	postOrderMirror(root->lchild, vi);
	vi.push_back(root->data);
}
vector<int> origin, pre, preM, post, postM;
int main() {
	int n, data;
	scanf("%d", &n);
	BTnode *root = NULL;
	for (int i = 0; i < n; i++) {
		scanf("%d", &data);
		origin.push_back(data);
		insert(root, data);
	}
	preOrder(root, pre);
	preOrderMirror(root, preM);
	postOrder(root, post);
	postOrderMirror(root, postM);
	if (origin == pre) {
		printf("YES\n");
		for (int i = 0; i < post.size(); i++) {
			printf("%d", post[i]);
			if (i < post.size() - 1)	printf(" ");
			else printf("\n");
		}
	}
	else if (origin == preM) {
		printf("YES\n");
		for (int i = 0; i < postM.size(); i++) {
			printf("%d", postM[i]);
			if (i < postM.size() - 1)	printf(" ");
			else printf("\n");
		}
	}
	else printf("NO\n");
	return 0;
}