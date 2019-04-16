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
#include <stack>
#include <ctype.h>
using namespace std;
const int maxn = 506;
const int INF = 0xfffffff;
int n, m, start, destiny;
int G[maxn][maxn], cost[maxn][maxn];
int d[maxn], mincost[maxn];
int pre[maxn];
int visit[maxn] = { 0 };
void Dijkstra(int s) {
	fill(d, d + maxn, INF);
	d[s] = 0;
	mincost[s] = 0;
	pre[s] = s;
	for (int i = 0; i < n; i++) {
		int u = -1, MIN = INF;
		for (int j = 0; j < n; j++) {
			if (visit[j] == 0 && d[j] < MIN) {
				u = j;
				MIN = d[j];
			}
		}
		if (u == -1)	return;
		visit[u] = 1;
		for (int v = 0; v < n; v++) {
			if (visit[v] == 0 && G[u][v] != INF) {
				if (d[v] > d[u] + G[u][v]) {
					d[v] = d[u] + G[u][v];
					mincost[v] = mincost[u] + cost[u][v];
					pre[v] = u;
				}
				else if (d[v] == d[u] + G[u][v]) {
					if (mincost[v] > mincost[u] + cost[u][v]) {
						pre[v] = u;
						mincost[v] = mincost[u] + cost[u][v];
					}
				}
			}
		}
	}
}
void DFS(int v) {
	if (v == start) {
		printf("%d ", v);
		return;
	}
	DFS(pre[v]);
	printf("%d ", v);
}
int main() {
	scanf("%d%d%d%d", &n, &m, &start, &destiny);
	fill(G[0], G[0] + maxn * maxn, INF);
	for (int i = 0; i < m; i++) {
		int u, v, distance, tmpcost;
		scanf("%d%d", &u, &v);
		scanf("%d%d", &G[v][u], &cost[v][u]);
		G[u][v] = G[v][u];;
		cost[u][v] = cost[v][u];;
	}
	Dijkstra(start);
	//DFS(destiny);
	int ans[maxn], num = 0, a = destiny;
	while (1) {
		ans[num++] = a;
		if (a == pre[a])	break;
		a = pre[a];
	}
	for (int i = num - 1; i >= 0; i--) {
		printf("%d ", ans[i]);
	}
	printf("%d %d\n", d[destiny], mincost[destiny]);
	return 0;
}