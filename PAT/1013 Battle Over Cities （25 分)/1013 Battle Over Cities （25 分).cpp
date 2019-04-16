#include <cstdio>
#include <vector>
using namespace std;
const int N = 1010;
vector<int> G[N];//аз╫с╠М
int father[N];
int visit[N];
int n, m, k;
int findFather(int x) {
	int a = x;
	while (x != father[x])
		x = father[x];
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
void init() {
	for (int i = 1; i < N; i++) {
		father[i] = i;
		visit[i] = 0;
	}
}
int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		G[a].push_back(b);
		G[b].push_back(a);
	}
	int currentpoint;
	for (int query = 0; query < k; query++) {
		scanf("%d", &currentpoint);
		init();
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < G[i].size(); j++) {
				int u = i, v = G[i][j];
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
				visit[fa_i] = 1;
				block++;
			}
		}
		printf("%d\n", block - 1);
	}
}