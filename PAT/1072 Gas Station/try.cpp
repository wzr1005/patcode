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
const int maxn = 1020;
const int INF = 1000000000;
int n, m, k, ds;
int G[maxn][maxn], visit[maxn];
int d[maxn];
int getID(char str[]) {
	int ID = 0;
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] != 'G') {
			ID = ID * 10 + str[i] - '0';
		}
	}
	if (str[0] == 'G')	return ID + n;
	return ID;
}
void Dijkstra(int s) {
	memset(visit, 0, sizeof(visit));
	fill(d, d + maxn, INF);
	d[s] = 0;
	for (int i = 0; i < n + m; i++) {
		int u = -1, MIN = INF;
		for (int j = 1; j <= n + m; j++) {
			if (visit[j] == 0 && d[j] < MIN) {
				u = j; 
				MIN = d[j];
			}
		}
		if (u == -1)	return;
		visit[u] = 1;
		for (int v = 1; v <= n + m; v++) {
			if (visit[v] == 0 && G[u][v] != INF) {
				if (d[v] > d[u] + G[u][v]) {
					d[v] = d[u] + G[u][v];
				}
			}
		}
	}

}
int main() {
	scanf("%d%d%d%d", &n, &m, &k, &ds);
	char s1[10], s2[10];
	int u, v, w;
	fill(G[0], G[0] + maxn * maxn, INF);
	for (int i = 0; i < k; i++) {
		scanf("%s %s %d", s1, s2, &w);
		u = getID(s1);
		v = getID(s2);
		G[u][v] = G[v][u] = w;
	}//构建邻接矩阵
	int minstation = -1;
	double mindistance = -1, avgans;
	for (int i = n + 1; i <= n + m; i++) {
		double avgtemp = 0, tempmindis = INF;
		Dijkstra(i);
		for (int j = 1; j <= n; j++) {
			if (d[j] > ds) {//枚举每个加油站到房屋的最短距离
				tempmindis = -1;
				break;
			}
			if (tempmindis > d[j]) {
				tempmindis = d[j];
			}
			avgtemp += 1.0 * d[j] / n;
		}
		if (tempmindis == -1)	continue;
		if (mindistance < tempmindis) {
			mindistance = tempmindis;
			avgans = avgtemp;
			minstation = i;
		}
		else if (tempmindis == mindistance && avgans > avgtemp) {
			avgans = avgtemp;
			minstation = i;
		}
	}
	if (minstation == -1) {
		printf("No Solution\n");
		return 0;
	}
	printf("G%d\n", minstation - n);
	printf("%.1f %.1f", mindistance, avgans);
	return 0;
}