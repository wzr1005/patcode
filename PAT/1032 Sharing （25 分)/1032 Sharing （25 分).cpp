#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100010;
struct node {
	int address, nextAdd;
	char c;
	int flag;
	node() {
		flag = 0;
	}
}s[maxn];
int main() {
	int firstAdd1, firstAdd2, n;
	scanf("%d%d%d", &firstAdd1, &firstAdd2, &n);
	for (int i = 0; i < n; i++) {
		int address;
		scanf("%d", &address);
		scanf(" %c%d", &s[address].c, &s[address].nextAdd);
	}
	int p = firstAdd1;
	while (p != -1) {
		s[p].flag = 1;
		p = s[p].nextAdd;
	}
	p = firstAdd2;
	while (p != -1) {
		if (s[p].flag == 1) break;
		p = s[p].nextAdd;
	}
	if (p != -1) {
		printf("%05d", p);
	}
	else {
		printf("-1");
	}
}