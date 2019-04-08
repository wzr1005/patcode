#include <cstdio>
#include <vector>
#include <map>
#include <iostream>
using namespace std;
vector<int> Pre;
map<int, int> mp;
int main() {
	int m, n;
	cin >> m >> n;
	Pre.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> Pre[i];
		mp[Pre[i]] = 1;
	}
	int u, v;
	int x;
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &u, &v);
		for (int j = 0; j < n; j++) {
			x = Pre[j];
			if ((x >= u && x <= v) || (x <= u && x >= v)) {
				break;
			}
		}
		if (!mp[u] && !mp[v]) {
			printf("ERROR: %d and %d are not found.\n", u, v);
		}
		else if (!mp[u]) {
			printf("ERROR: %d is not found.\n", u);
		}
		else if (!mp[v]) {
			printf("ERROR: %d is not found.\n", v);
		}
		else if (x == u || x == v) {
			printf("%d is an ancestor of %d.\n", x, x == u ? v : u);
		}
		else {
			printf("LCA of %d and %d is %d.\n", u, v, x);
		}
	}
	return 0;
}