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
const int INF = 1 << 31 - 1;
int ans = INF, ansId;
int n, m, G[210][210];
void check(int index) {
	int cnt, sum = 0, flag = 1;
	cin >> cnt;
	vector<int> v(cnt);
	set<int> s;
	for (int i = 0; i < cnt; i++) {
		cin >> v[i];
		s.insert(v[i]);
	}
	for (int i = 0; i < cnt - 1; i++) {
		if (!G[v[i]][v[i + 1]])	flag = 0;
		sum += G[v[i]][v[i + 1]];
	}
	if (flag == 0) {
		printf("Path %d: NA (Not a TS cycle)\n", index);
	}
	else if (v[0] != v[cnt - 1] || s.size() != n) {
		printf("Path %d: %d (Not a TS cycle)\n", index, sum);
	}
	else if (cnt != n + 1) {
		printf("Path %d: %d (TS cycle)\n", index, sum);
		if (ans > sum) {
			ans = sum;
			ansId = index;
		}
	}
	else {
		printf("Path %d: %d (TS simple cycle)\n", index, sum);
		if (ans > sum) {
			ans = sum;
			ansId = index;
		}
	}
}
int main() {
	cin >> n >> m;
	int u, v, t;
	memset(G, 0, sizeof(G));
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> t;
		G[u][v] = G[v][u] = t;
	}
	int k; cin >> k;
	for (int i = 1; i <= k; i++) {
		check(i);
	}
	printf("Shortest Dist(%d) = %d\n", ansId, ans);
	return 0;
}