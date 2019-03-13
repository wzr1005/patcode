#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 510;
const int INF = 0xfffffff;
int n, m, st, ed;
int rescue[maxn], G[maxn][maxn];
int numres[maxn], d[maxn], roadnum[maxn];
void Dijkstra(int s) {
	int visit[maxn] = { 0 };
	memset(roadnum, 0, sizeof(roadnum));
	fill(d, d + maxn, INF);
	memset(numres, 0, sizeof(numres));
	numres[s] = rescue[s], d[s] = 0, roadnum[s] = 1;
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
					numres[v] = numres[u] + rescue[v];
					roadnum[v] = roadnum[u];
				}
				else if (d[v] == d[u] + G[u][v]) {
					if (numres[v] < numres[u] + rescue[v]) {
						numres[v] = numres[u] + rescue[v];
					}
					roadnum[v] += roadnum[u];
				}
			}
		}
	}
	

}
int main() {
	scanf("%d%d%d%d", &n, &m, &st, &ed);
	for (int i = 0; i < n; i++) {
		scanf("%d", &rescue[i]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			G[i][j] = INF;
		}
	}
	int u, v;
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &u, &v);
		scanf("%d", &G[u][v]);
		G[v][u] = G[u][v];
	}
	Dijkstra(st);
	printf("%d %d", roadnum[ed], numres[ed]);
}