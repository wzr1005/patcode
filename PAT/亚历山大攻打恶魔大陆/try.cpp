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
const int maxn = 1000;
const int INF = 1000000000;
int n, m, G[maxn][maxn];
int d[maxn], visit[maxn] = { 0 };
int prim() {
	fill(d, d + maxn, INF);
	d[0] = 0;//默认从0出发
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int u = -1, MIN = INF;
		for (int j = 0; j < n; j++) {
			if (visit[j] == 0 && d[j] < MIN) {
				u = j;
				MIN = d[j];
			}
		}
		if (u == -1)	return -1;
		visit[u] = 1;
		ans += d[u];//n次dijkstra
		printf("%d\n", ans);
		for (int v = 0; v < n; v++) {
			if (visit[v] == 0 && G[u][v] != INF && d[v] > d[u] + G[u][v]) {
				d[v] = d[u] + G[u][v];
			}
		}
	}
	return ans;
}
int main() {
	int u, v, w;
	scanf("%d%d", &n, &m);
	fill(G[0], G[0] + maxn * maxn, INF);
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &u, &v, &w);
		G[u][v] = G[v][u] = w;
	}
	int ans = prim();
	printf("%d", ans);
	return 0;
}
/*
6 10
0 1 4
0 4 1
0 5 2
1 2 6
1 5 3
2 3 6
2 5 5
3 4 4
3 5 5
4 5 3
*/