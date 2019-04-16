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
int n, m, s;
struct BTnode {
	int weight;
	vector<int> child;
}node[maxn];
bool cmp(int a, int b) {
	return node[a].weight > node[b].weight;
}
int path[maxn];//记录路径
void DFS(int index, int numNode, int sum) {
	if (sum > s)	return;
	if (sum == s) {
		if (node[index].child.size() != 0)	return;//到达叶子结点直接返回
		//到达叶子节点,此时path[]中存放了一条完整的路径,输出它
		for (int i = 0; i < numNode; i++) {
			printf("%d", node[path[i]].weight);
			if (i < numNode - 1)	printf(" ");
			else printf("\n");
		}
	}
	for (int i = 0; i < node[index].child.size(); i++) {
		int child = node[index].child[i];
		path[numNode] = child;
		DFS(child, numNode + 1, sum + node[child].weight);
	}
}
int main() {
	scanf("%d%d%d", &n, &m, &s);
	for (int i = 0; i < n; i++) {
		scanf("%d", &node[i].weight);
	}
	int parent, k, tmp;
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &parent, &k);
		for (int j = 0; j < k; j++) {
			scanf("%d", &tmp);
			node[parent].child.push_back(tmp);
		}
		sort(node[parent].child.begin(), node[parent].child.end(), cmp);
	}
	path[0] = 0;
	DFS(0, 1, node[0].weight);
	return 0;
}