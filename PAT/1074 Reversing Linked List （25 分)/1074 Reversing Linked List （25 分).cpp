#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100010;
struct Node {
	int address, data, next;
	int order;
	Node() {
		order = maxn;
	}
}node[maxn];
bool cmp(Node a, Node b) {
	return a.order < b.order;
}
int main() {
	int firstAdd, n, k, address;
	scanf("%d%d%d", &firstAdd, &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &address);
		scanf("%d%d", &node[address].data, &node[address].next);
		node[address].address = address;
	}
	int p = firstAdd, count = 0;
	while (p != -1) {
		node[p].order = count++;
		p = node[p].next;
	}
	n = count;
	sort(node, node + maxn, cmp);
	for (int i = 0; i < n / k; i++) {
		for (int j = (i + 1) * k - 1; j > i * k; j--) {
			printf("%05d %d %05d\n", node[j].address, node[j].data, node[j - 1].address);
		}
		printf("%05d %d ", node[i * k].address, node[i * k].data);
		if (i < n / k - 1) {//如果不是最后一块
			printf("%05d\n", node[(i + 2) * k - 1].address);
		}
		else {//是最后一块,但是有两种可能,一种是刚好整除,一种是还有不需要反转的链表元素
			if (n % k == 0) {
				printf("-1");
			}
			else {
				printf("%05d\n", node[(i + 1) * k].address);
				for (int j = n / k * k; j < n - 1; j++) {
					printf("%05d %d %05d\n", node[j].address, node[j].data, node[j + 1].address);
				}
				printf("%05d %d -1", node[n - 1].address, node[n - 1].data);
			}
		}
	}
	return 0;
}