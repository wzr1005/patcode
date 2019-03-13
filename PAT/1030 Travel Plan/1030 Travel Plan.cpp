#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 510;
const int INF = 0xfffffff;
int G[maxn][maxn], cost[maxn][maxn];
int mincost[maxn], d[maxn], pre[maxn];
int n, m, st, ed;
void Dijkstra(int s) {
	int visit[maxn] = { 0 };
	fill(d, d + maxn, INF);
	//fill(mincost, mincost + maxn, INF);
	pre[s] = s;
	d[s] = 0, mincost[s] = 0;
	for (int i = 0; i < n; i++) {
		int u = -1, MIN = INF;
		for (int j = 0; j < n; j++) {
			if (visit[j] == 0 && d[j] < MIN) {
				u = j; 
				MIN = d[u];
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
					if (mincost[v] > mincost[u] + cost[v][u]) {
						mincost[v] = mincost[u] + cost[u][v];
						pre[v] = u;
					}
					
				}
			}
		}
	}
	
}
void DFS(int v) {
	if (v == st) {
		printf("%d ", st);
		return;
	}
	DFS(pre[v]);
	printf("%d ", v);
}
int main() {
	scanf("%d%d%d%d", &n, &m, &st, &ed);
	int u, v;
	fill(G[0], G[0] + maxn * maxn, INF);
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &u, &v);
		scanf("%d%d", &G[u][v], &cost[u][v]);
		G[v][u] = G[u][v];
		cost[v][u] = cost[u][v];
	}
	Dijkstra(st);
	DFS(ed);
	printf("%d %d", d[ed], mincost[ed]);
}