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
const int INF = (1 << 31) - 1;
int n, m, G[250][250];
int ans = INF, ansId;
vector<int> v;
void check(int index) {
	int sum = 0, cnt, flag = 1;
	scanf("%d", &cnt);
	set<int> s;
	vector<int> v(cnt);
	for (int i = 0; i < cnt; i++) {
		scanf("%d", &v[i]);
		s.insert(v[i]);//?
	}
	for (int i = 0; i < cnt - 1; i++) {
		if (G[v[i]][v[i + 1]] == 0)	flag = 0;
		sum += G[v[i]][v[i + 1]];
	}
	if (flag == 0) {
		printf("Path %d: NA (Not a TS cycle)\n", index);
	}
	else if (v[0] != v[cnt - 1] || s.size() != n) {
		printf("Path %d: %d (Not a TS cycle)\n", index, sum);
	}
	else if (cnt != n + 1) {//访问了所有城市，但是不是简单回路，简单回路应该是n+1;
		printf("Path %d: %d (TS cycle)\n", index, sum);
		if (sum < ans) {
			ans = sum;
			ansId = index;
		}
	}
	else {
		printf("Path %d: %d (TS simple cycle)\n", index, sum);
		if (sum < ans) {
			ans = sum;
			ansId = index;
		}
	}
}
int main() {
	cin >> n >> m;
	int u, v, dis;
	memset(G, 0, sizeof(G));
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> dis;
		G[u][v] = G[v][u] = dis;
	}
	int k;
	cin >> k;
	for (int i = 1; i <= k; i++) {
		check(i);
	}
	printf("Shortest Dist(%d) = %d\n", ansId, ans);
	return 0;
}