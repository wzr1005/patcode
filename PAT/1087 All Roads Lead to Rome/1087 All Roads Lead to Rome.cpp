#include <cstdio>
#include <iostream>
#include <string>	
#include <map>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 210;
const int INF = 1000000000;
int n, m, start,h, G[maxn][maxn], weight[maxn];
int d[maxn], w[maxn], num[maxn], pn[maxn], pre[maxn];
int visit[maxn] = { 0 };
map<string, int> stringToint;
map<int, string> intTostring;
void Dijkstra(int s) {
	fill(d, d + maxn, INF);
	memset(visit, 0, sizeof(visit));
	d[s] = 0;
	w[s] = weight[s];
	num[s] = 1, pn[s] = 0, pre[s] = s;
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
					w[v] = w[u] + weight[v];
					pre[v] = u;
					pn[v] = pn[u] + 1;
					num[v] = num[u];
				}
				else if (d[v] == d[u] + G[u][v]) {
					num[v] += num[u];
					if (w[v] < w[u] + weight[v]) {//happyÈ¡´óµÄ
						w[v] = w[u] + weight[v];
						pre[v] = u;
						pn[v] = pn[u] + 1;
					}
					else if (w[v] == w[u] + weight[v]) {
						double vavg = 1.0 * (w[v]) / pn[v];
						double uavg = 1.0 * w[v] / (pn[u] + 1);
						if (uavg > vavg) {
							pre[v] = u;
							pn[v] = pn[u] + 1;
						}
					}
				}
			}
		}
	}
}
int main() {
	string stcity, city1, city2;
	cin >> n >> m >> stcity;
	stringToint[stcity] = 0;
	intTostring[0] = stcity;
	for (int i = 1; i < n; i++) {
		cin >> city1 >> weight[i];
		stringToint[city1] = i;
		intTostring[i] = city1;
	}
	fill(G[0], G[0] + maxn * maxn, INF);
	for (int i = 0; i < m; i++) {
		cin >> city1 >> city2 >> h;
		int u = stringToint[city1];
		int v = stringToint[city2];
		G[u][v] = G[v][u] = h;
	}
	Dijkstra(0);
	int a = stringToint["ROM"];
	printf("%d %d %d %d\n", num[a], d[a], w[a], w[a] / pn[a]);
	int ans[maxn], num = 0;
	while (a != pre[a]) {
		ans[num++] = a;
		a = pre[a];
	}
	ans[num++] = a;
	for (int i = num - 1; i >= 0; i--) {
		cout << intTostring[ans[i]];
		if (i != 0)	printf("->");
	}
	return 0;
}