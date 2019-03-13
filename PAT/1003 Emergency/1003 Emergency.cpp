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
const int INF = 0xfffffff;
int n, m, st, ed, G[maxn][maxn], weight[maxn];
int d[maxn], w[maxn], num[maxn], visit[maxn] = { 0 };
void Dijkstra(int s) {
	for (int i = 0; i < maxn; i++)	d[i] = INF;
	memset(num, 0, sizeof(num));
	memset(w, 0, sizeof(w));
	d[s] = 0;
	w[s] = weight[s];
	num[s] = 1;//s的编号是1
	for (int i = 0; i < n; i++) {
		int u = -1, MIN = INF;
		for (int j = 0; j < n; j++) {//找到未访问的顶点中d[]最小的
			if (visit[j] == 0 && d[j] < MIN) {
				u = j;
				MIN = d[j];
			}
		}
		if (u == -1)  return;
		visit[u] = 1;
		for (int v = 0; v < n; v++) {
			if (visit[v] == false && G[u][v] != INF) {//
				//d[u]存储的就是一个单源最短路径
				if (d[u] + G[u][v] < d[v]) {
					d[v] = d[u] + G[u][v];//
					w[v] = w[u] + weight[v];//？救援队数量？
					num[v] = num[u];//编号相同
				}
				else if (d[u] + G[u][v] == d[v]) {//找到一条相同长度的路径
					if (w[u] + weight[v] > w[v]) {//同样路径 路径城市救援队的总和更大
						w[v] = w[u] + weight[v];
					}
					num[v] += num[u];//最短路径数目
				}
			}
		}
	}
}
int main() {
	scanf("%d%d%d%d", &n, &m, &st, &ed);
	for (int i = 0; i < n; i++) {
		scanf("%d", &weight[i]);//第二行是点权
		//点权是指每个城市的救援队数量
	}
	int u, v;
	fill(G[0], G[0] + maxn * maxn, INF);
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &u, &v);
		scanf("%d", &G[v][u]);
		G[u][v] = G[v][u];
	}
	Dijkstra(st);
	printf("%d %d\n", num[ed], w[ed]);
	return 0;

}