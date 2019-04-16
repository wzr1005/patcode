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
const int N = 1010;
int father[N];
int isroot[N] = { 0 };
int course[N] = { 0 };
using namespace std;
void init(int n) {
	for (int i = 1; i <= n; i++) {
		father[i] = i;
	}
}
int findFather(int x) {
	int a = x;
	while (x != father[x]) {
		x = father[x];
	}
	while (a != father[a]) {
		int z = a;
		a = father[a];
		father[z] = x;
	}
	return x;
}
bool cmp(int a, int b) {
	return a > b;
}
void Union(int a, int b) {
	int faA = findFather(a);
	int faB = findFather(b);
	if (faA != faB) {
		father[faA] = faB;
	}
}
int main() {
	int n, k, h, ans = 0;
	scanf("%d", &n);
	init(n);
	for (int i = 1; i <= n; i++) {
		scanf("%d:", &k);
		for (int j = 0; j < k; j++) {
			scanf("%d", &h);
			if (course[h] == 0) {
				course[h] = i;
			}
			Union(i, findFather(course[h]));
		}
	}
	for (int i = 1; i <= n; i++) {
		isroot[findFather(i)]++;
	}
	for (int i = 1; i <= n; i++) {
		if (isroot[i])
			ans++;
	}
	printf("%d\n", ans);
	sort(isroot + 1, isroot + n + 1, cmp);
	for (int i = 1; i <= ans; i++) {
		printf("%d", isroot[i]);
		if (i != ans)	printf(" ");
	}
	return 0;
}