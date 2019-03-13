#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 1010;
int father[maxn];
vector<int> G[maxn];
int n, m, k, visit[maxn];
int currentpoint;
int findFather(int x) {
	int a = x;
	while (x != father[x]) {
		x = father[x];
	}
	while (a != father[a]) {
		int z = a;
		a = father[a];
		father[z] = x;
	}
	return x;
}
void Union(int a, int b) {
	int faA = findFather(a);
	int faB = findFather(b);
	if (faA != faB) {
		father[faA] = faB;
	}
}
int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for (int query = 0; query < k; query++) {
		scanf("%d", &currentpoint);
		for (int i = 1; i <= n; i++) {
			father[i] = i;
			visit[i] = 0;
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < G[i].size(); j++) {
				int u = i, v = G[i][j];//u,v肯定是联通的
				if (u == currentpoint || v == currentpoint)
					continue;
				Union(u, v);
			}
		}
		int block = 0;
		for (int i = 1; i <= n; i++) {
			if (i == currentpoint)	continue;
			int fa_i = findFather(i);
			if (visit[fa_i] == 0) {
				block++;
				visit[fa_i] = 1;
			}
		}
		printf("%d\n", block - 1);
	}
	return 0;
}