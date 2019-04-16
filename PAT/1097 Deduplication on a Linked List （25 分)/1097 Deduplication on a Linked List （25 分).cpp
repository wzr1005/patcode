#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 100005;
struct Node {
	int address, data, next;
	int order;
	Node() {
		order = 2 * maxn;
	}
}node[maxn];
bool cmp(Node a, Node b) {
	return a.order < b.order;
}
bool exist[maxn] = { 0 };
int main() {
	int firstAdd, n, add;
	scanf("%d%d", &firstAdd, &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &add);
		scanf("%d%d", &node[add].data, &node[add].next);
		node[add].address = add;
	}
	int p = firstAdd, countvalid = 0, countmove = 0;
	while (p != -1) {
		if (exist[abs(node[p].data)] == 0) {
			exist[abs(node[p].data)] = 1;
			node[p].order = countvalid++;
		}
		else {
			node[p].order = maxn + countmove++;
		}
		p = node[p].next;
	}
	int count = countvalid + countmove;
	sort(node, node + maxn, cmp);
	for (int i = 0; i < count; i++) {
		if ((i != countvalid - 1) && (i != count - 1)) {
			printf("%05d %d %05d\n", node[i].address, node[i].data, node[i + 1].address);
		}
		else {
			printf("%05d %d -1\n", node[i].address, node[i].data);
		}
	}
	return 0;
}