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
const int maxn = 110;
vector<int> node[maxn];
int hashTable[maxn] = { 0 };
void DFS(int index, int level) {
	hashTable[level]++;
	for (int i = 0; i < node[index].size(); i++)
		DFS(node[index][i], level + 1);
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	int father, child, k;
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &father, &k);
		for (int j = 0; j < k; j++) {
			scanf("%d", &child);
			node[father].push_back(child);
		}
	}
	DFS(1, 1);
	int maxlevel = 0, maxvalue = 0;
	for (int i = 1; i < maxn; i++) {
		if (hashTable[i] > maxvalue) {
			maxvalue = hashTable[i];
			maxlevel = i;
		}
	}
	printf("%d %d", maxvalue, maxlevel);
	return 0;
}