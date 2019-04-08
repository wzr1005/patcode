#include <cstdio>
#include <map>
#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main() {
	int n, m;
	map<int, vector<int>> mp;
	cin >> n >> m;
	int u, v;
	for (int i = 0; i < n; i++) {
		cin >> u >> v;
		mp[u].push_back(v);
		mp[v].push_back(u);
	}
	while (m--) {
		int k; cin >> k;
		int a[100010] = { 0 };
		vector<int> v(k);
		int flag = 1;
		for (int i = 0; i < k; i++) {
			cin >> v[i];
			a[v[i]] = 1;
		}
		for (int i = 0; i < k; i++) {
			if (!flag)	break;
			for (int j = 0; j < mp[v[i]].size(); j++) {
				if (a[mp[v[i]][j]] == 1) {
					flag = 0;
					printf("No\n");
					break;
				}
			}
		}
		if (flag)	printf("Yes\n");
	}
	return 0;
}