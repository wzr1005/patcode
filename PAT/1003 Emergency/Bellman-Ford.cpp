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
struct node {
	int v, dis;
	node(int _v, int _dis) : v(_v), dis(_dis){}
};
vector<node> Adj[maxn];
int n, m, st, ed, rescue[maxn];
int d[maxn], numres[maxn], roadnum[maxn];
set<int> pre[maxn];
void Bellman(int s) {
	fill(d, d + maxn, INF);
	memset(roadnum, 0, sizeof(roadnum));
	memset(numres, 0, sizeof(numres));
	d[s] = 0;
	numres[s] = rescue[s];
	roadnum[s] = 1;
	for (int i = 0; i < n - 1; i++) {
		for (int u = 0; u < n; u++) {
			for (int j = 0; j < Adj[u].size(); j++) {
				int v = Adj[u][j].v;//邻接边的顶点
				int dis = Adj[u][j].dis;//邻接边的边权
				if (d[u] + dis < d[v]) {
					d[v] = d[u] + dis;
					numres[v] = numres[u] + rescue[v];
					roadnum[v] = roadnum[u];
					pre[v].clear();
					pre[v].insert(u);
				}
				else if (d[u] + dis == d[v]) {
					if (numres[u] + rescue[v] > numres[v]) {
						numres[v] = numres[u] + rescue[v];
					}
					pre[v].insert(u);
					numres[v] = 0;
					for (auto it = pre[v].begin(); it != pre[v].end(); it++) {
						roadnum[v] += roadnum[*it];
					}
				}
			}
		}
	}
}
int main() {
	scanf("%d%d", &n, &m, &st, &ed);
	for (int i = 0; i < n; i++) {
		scanf("%d", &rescue[i]);
	}
	int u, v, wt;
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &u, &v, &wt);
		Adj[u].push_back(node(v, wt));
		Adj[v].push_back(node(u, wt));
	}
	return 0;
}