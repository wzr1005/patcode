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
vector<int> In, Pre;
map<int, int> pos;//存储每个结点对应的中序顺序
void LCA(int inl, int inr, int PreRoot, int u, int v) {
	if (inl > inr)	return;
	int inRoot = pos[Pre[PreRoot]];
	int uIn = pos[u], vIn = pos[v];
	if (pos[u] < inRoot&&pos[v] < inRoot) {
		LCA(inl, inRoot - 1, PreRoot + 1, u, v);
	}
	else if ((pos[u] < inRoot&&pos[v] > inRoot)||(pos[u] > inRoot&&pos[v] < inRoot)) {
		printf("LCA of %d and %d is %d.\n", u, v, In[inRoot]);
	}
	else if (pos[u] > inRoot&&pos[v] > inRoot) {
		LCA(inRoot + 1, inr, PreRoot + inRoot - inl + 1, u, v);//InRoot - inl 是此时根preRoot左子树的个数，
		//于是PreRoot + inRoot - inl + 1 就是根PreRoot的右子树
	}
	else if (pos[u] == inRoot)	printf("%d is an ancestor of %d.\n", u, v);
	else if (pos[v] == inRoot)	printf("%d is an ancestor of %d.\n", v, u);
}
int main() {
	int m, n;
	cin >> m >> n;
	In.resize(n + 1), Pre.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> In[i];
		pos[In[i]] = i;
	}
	for (int i = 1; i <= n; i++) {
		cin >> Pre[i];
	}
	int u, v;
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		if (pos[u] == 0 || pos[v] == 0) {
			if (pos[u] == 0&& pos[v] == 0) {
				printf("ERROR: %d and %d are not found.\n", u, v);
			}
			else if (pos[u] == 0) {
				printf("ERROR: %d is not found.\n", u);
			}
			else if (pos[v] == 0) {
				printf("ERROR: %d is not found.\n", v);
			}
		}
		else {
			LCA(1, n, 1, u, v);
		}
	}
	return 0;
}