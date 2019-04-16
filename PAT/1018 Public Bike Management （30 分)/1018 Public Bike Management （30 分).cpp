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
const int maxn = 510;
const int INF = 1000000000;
int cmax, n, des, m;
int vex[maxn] = { 0 }, G[maxn][maxn], d[maxn];
int visit[maxn] = { 0 };
vector<int> tempPath, path;
vector<int> pre[maxn];
int minneed = INF, minremain = INF;
void DFS(int v) {
	if (v == 0) {
		tempPath.push_back(v);
		int need = 0, remain = 0;//need表示需要从基地带的， remain表示中途多余的车俩
		for (int i = tempPath.size() - 1; i >= 0; i--) {
			int id = tempPath[i];
			if (vex[id] > 0) {
				remain += vex[id];
			}
			else {
				if (remain > abs(vex[id])) {
					remain -= abs(vex[id]);
				}
				else {
					need += abs(vex[id]) - remain;
					remain = 0;
				}
			}
		}
		if (need < minneed) {
			minneed = need;
			path = tempPath;
			minremain = remain;
		}
		else if (need == minneed && remain < minremain) {
			path = tempPath;
			minremain = remain;
		}
		tempPath.pop_back();
		return;
	}
	tempPath.push_back(v);
	for (int i = 0; i < pre[v].size(); i++) {
		DFS(pre[v][i]);//其中一个前驱
	}
	tempPath.pop_back();
}
void Dijkstra(int s) {
	fill(d, d + maxn, INF);
	d[s] = 0;
	for (int i = 0; i <= n; i++) {
		int u = -1, MIN = INF;
		for (int j = 0; j <= n; j++) {
			if (visit[j] == 0 && d[j] < MIN) {
				u = j;
				MIN = d[j];
			}
		}
		if (u == -1)	return;
		visit[u] = 1;
		for (int v = 0; v <= n; v++) {
			if (visit[v] == 0 && G[u][v] != INF) {
				if (d[v] > d[u] + G[u][v]) {
					d[v] = d[u] + G[u][v];
					pre[v].clear();
					pre[v].push_back(u);
				}
				else if (d[v] == d[u] + G[u][v]) {
					pre[v].push_back(u);
				}
			}
		}
	}
}
int main() {
	scanf("%d%d%d%d", &cmax, &n, &des, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &vex[i]);
		vex[i] -= cmax / 2;
	}
	fill(G[0], G[0] + maxn * maxn, INF);
	for (int i = 0; i < m; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		G[u][v] = G[v][u] = w;
	}
	Dijkstra(0);
	DFS(des);
	printf("%d ", minneed);
	for (int i = path.size() - 1; i >= 0; i--) {
		printf("%d", path[i]);
		if (i != 0)	printf("->");
	}
	printf(" %d", minremain);
	return 0;
}