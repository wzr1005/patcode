#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <cstring>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <ctype.h>
using namespace std;
const int maxn = 510;
const int INF = 0xfffffff;
int n, m, st, ed;
int G[maxn][maxn], r[maxn], num[maxn];
int d[maxn], rm[maxn];
void Dijkstra(int s) {
	int visit[maxn] = { 0 };
	fill(d, d + maxn, INF);
	memset(rm, 0, sizeof(rm));
	memset(num, 0, sizeof(num));
	d[s] = 0;
	rm[s] = r[s];
	num[s] = 1;
	for (int i = 0; i < n; i++) {
		int u = -1, MIN = INF;
		for (int j = 0; j < n; j++) {
			if (visit[j] == 0 && d[j] < MIN) {
				u = j;
				MIN = d[j];
			}
		}
		if (u == -1)	 return;
		visit[u] = 1;
		for (int v = 0; v < n; v++) {
			if (G[u][v] != INF && visit[v] == 0) {
				if (d[v] > d[u] + G[u][v]) {
					d[v] = d[u] + G[u][v];
					rm[v] = rm[u] + r[v];
					num[v] = num[u];
				}
				else if (d[v] == d[u] + G[u][v]) {
					if (rm[v] < rm[u] + r[v]) {
						rm[v] = rm[u] + r[v];
					}
					num[v] += num[u];
				}
			}
		}
	}
}
int main() {
	scanf("%d%d%d%d", &n, &m, &st, &ed);
	for (int i = 0; i < n; i++) {
		scanf("%d", &r[i]);
	}
	for (int i = 0; i < maxn; i++) {
		for (int j = 0; j < maxn; j++) {
			G[i][j] = INF;
		}
	}
	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		scanf("%d", &G[u][v]);
		G[v][u] = G[u][v];
	}
	Dijkstra(st);
	printf("%d %d", num[ed], rm[ed]);
}