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
const int maxn = 10010;
const int INF = (1<< 32) - 1;
int G[maxn][maxn] = { 0 };
int n, m, num;
int visit[maxn], color[maxn];
void DFS(int v) {
	visit[v] = 1;
	num++;
	for (int i = 0; i < n; i++) {
		if (G[v][i] && !visit[i] && color[v] != color[i]) {
			DFS(i);
		}
	}
}
int main() {
	//fill(G[0], G[0] + maxn * maxn, INF);
	cin >> n >> m;
	int u, v;
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		G[u][v] = G[v][u] = 1;
	}
	int k; cin >> k;
	for (int i = 0; i < k; i++) {
		memset(visit, 0, sizeof(visit));
		num = 0;
		int maxcolor = -1;
		for (int j = 0; j < n; j++) {
			cin >> color[j];
			maxcolor = max(color[j], maxcolor);
		}
		DFS(0);
		if (num < n) {
			printf("No\n");
		}
		else printf("%d-coloring\n", maxcolor);
	}
	return 0;
}