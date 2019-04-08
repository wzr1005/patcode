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
int G[210][210];
int main() {
	int n, m, u, v;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		G[u][v] = G[v][u] = 1;
	}
	int query, k;
	scanf("%d", &query);
	for (int i = 0; i < query; i++) {
		int isclique = 1, isMaximal = 1;
		int hash[210] = { 0 };
		scanf("%d", &k);
		vector<int> v(k);
		for (int j = 0; j < k; j++) {
			cin >> v[j];
			hash[v[j]] = 1;
		}
		for (int p = 0; p < k; p++) {
			if (!isclique)	break;
			for (int q = p + 1; q < k; q++) {
				if (G[v[p]][v[q]] == 0) {
					isclique = 0;
					printf("Not a Clique\n");
					break;
				}
			}
		}
		if (!isclique)	continue;
		for (int j = 1; j <= n; j++) {
			if (hash[j] == 0) {//j结点没有出现过
				int flag = 1;
				for (int p = 0; p < k; p++) {
					if (G[j][v[p]] == 0) {
						flag = 0;
						break;
					}
				}
				if (flag) {
					isMaximal = 0;
					printf("Not Maximal\n");
					break;
				}
			}
		}
		if (isMaximal)	printf("Yes\n");
	}
	return 0;
}