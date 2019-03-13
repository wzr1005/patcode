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
const int maxn = 210;
const int INF = 1000000000;
int G[maxn][maxn], Happy[maxn], pre[maxn], pn[maxn];
int n, m, weight[maxn];
string stcity;
string city1, city2;
int visit[maxn], d[maxn], num[maxn];
map<string, int> stringToint;
map<int, string> intTostring;
void Dijkstra(int s) {
	fill(d, d + maxn, INF);
	memset(visit, 0, sizeof(visit));
	pn[s] = 0, num[s] = 1;
	Happy[s] = weight[s];
	d[s] = 0;
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
					Happy[v] = Happy[u] + weight[v];
					num[v] = num[u];
					pre[v] = u;
					pn[v] = pn[u] + 1;
				}
				else if (d[v] == d[u] + G[u][v]) {
					num[v] += num[u];
					if (Happy[v] < Happy[u] + weight[v]) {
						Happy[v] = Happy[u] + weight[v];
						pn[v] = num[u] + 1;
						pre[v] = u;
					}
					else if (Happy[v] == Happy[u] + weight[v]) {
						double vavg = 1.0 * Happy[v] / pn[v];
						double uavg = 1.0 * (Happy[u] + weight[v]) / (pn[u] + 1);
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
void printpath(int v) {
	if (v == 0) {
		cout << intTostring[v];
		return;
	}
	printpath(pre[v]);
	cout << "->" << intTostring[v];
}
int main() {
	cin >> n >> m >> stcity;
	stringToint[stcity] = 0;
	intTostring[0] = stcity;
	weight[0] = 0;
	int h;
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
	printf("%d %d %d %d\n", num[a], d[a], Happy[a], Happy[a] / pn[a]);
	printpath(a);
	return 0;
}