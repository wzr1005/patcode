#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn = 50;
int post[maxn], in[maxn];
int n;
struct BTnode {
	int data;
	BTnode* lchild;
	BTnode* rchild;
};
BTnode* create(int postL, int postR, int inL, int inR) {
	if (postL > postR)	return NULL;
	BTnode* root = new BTnode;
	root->data = post[postR];
	int k;
	for (k = inL; k < inR; k++) {
		if (in[k] == post[postR])	break;
	}
	int numleft = k - inL;
	root->lchild = create(postL, postL + numleft - 1, inL, k - 1);
	root->rchild = create(postL + numleft, postR - 1, k + 1, inR);
	return root;
}
int num = 0;
void BFS(BTnode* root) {
	queue<BTnode*> q;
	q.push(root);
	while (!q.empty()) {
		BTnode* now = q.front();
		q.pop();
		printf("%d", now->data);
		num++;
		if (num < n)	printf(" ");
		if (now->lchild != NULL)	q.push(now->lchild);
		if (now->rchild != NULL)	q.push(now->rchild);
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &post[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &in[i]);
	}
	BTnode* root = create(0, n - 1, 0, n - 1);
	BFS(root);
	return 0;
}