#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 10010;
vector<int> G[maxn];
vector<int> temp, ans;
int n, father[maxn], isroot[maxn];
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
int calblock() {
	int block = 0;
	for (int i = 1; i <= n; i++) {
		if (isroot[findFather(i)] == 0) {
			block++;
			isroot[findFather(i)] = 1;
		}
	}
	return block;
}
void Union(int a, int b) {
	int faA = findFather(a);
	int faB = findFather(b);
	if (faA != faB) {
		father[faA] = faB;
	}
}
int visit[maxn] = { 0 }, maxH = 0;
void DFS(int v, int Height, int pre) {
	if (maxH < Height) {
		maxH = Height;
		temp.clear();
		temp.push_back(v);
	}
	else if (maxH == Height) {
		temp.push_back(v);
	}
	for (int i = 0; i < G[v].size(); i++) {
		if (G[v][i] == pre)	continue;
		DFS(G[v][i], Height + 1, v);
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		father[i] = i;
		isroot[i] = 0;
	}
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
		Union(u, v);//一条边的两点结合
	}
	int block = calblock();
	if (block != 1) {
		printf("Error: %d components", block);
	}
	else {
		DFS(1, 1, -1);
		ans = temp;
		DFS(ans[0], 1, -1);
		for (int i = 0; i < temp.size(); i++) {
			ans.push_back(temp[i]);
		}
		sort(ans.begin(), ans.end());
		printf("%d", ans[0]);
		for (int i = 1; i < ans.size(); i++) {
			if (ans[i] == ans[i - 1])	continue;
			printf("\n%d", ans[i]);
		}
	}
	return 0;
}