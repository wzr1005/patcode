#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100010;
struct node {
	int address, key, next;
	int flag;
	node() {
		flag = 0;
	}
}list[maxn];
bool cmp(node a, node b) {
	if (a.flag != b.flag)	return a.flag > b.flag;
	else return a.key < b.key;
}
int main() {
	int firstAdd, n;
	scanf("%d%d", &n, &firstAdd);
	for (int i = 0; i < n; i++) {
		int address;
		scanf("%d", &address);
		scanf("%d%d", &list[address].key, &list[address].next);
		list[address].address = address;
	}
	int count = 0, p = firstAdd;
	while (p != -1) {
		list[p].flag = 1;
		count++;
		p = list[p].next;
	}
	if (count == 0) printf("0 -1");
	else {
		//筛选出有效结点
		sort(list, list + maxn, cmp);
		printf("%d %05d\n", count, list[0].address);
		for (int i = 0; i < count - 1; i++) {
			printf("%05d %d %05d\n", list[i].address, list[i].key, list[i + 1].address);
		}
		printf("%05d %d -1", list[count - 1].address, list[count - 1].key);
	}
}