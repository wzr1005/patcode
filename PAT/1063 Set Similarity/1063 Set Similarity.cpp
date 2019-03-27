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
int main() {
	//ios::sync_with_stdio(false);
	int m, x, n;//set数量
	cin >> n;
	vector<set<int>> v(n+1);
	for (int i = 1; i <= n; i++) {
		cin >> m;
		set<int> s;
		for (int j = 0; j < m; j++) {
			cin >> x;
			s.insert(x);
		}
		v[i] = s;
	}
	int k;
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		int k1, k2;
		cin >> k1 >> k2;
		int nc = 0, nt = v[k2].size();
		for (auto it = v[k1].begin(); it != v[k1].end(); it++) {
			if (v[k2].find(*it) == v[k2].end())	nt++;//不同的数量
			else nc++;//相同的数量
		}
		double ans = (double)nc / nt * 100;
		printf("%.1f%%\n", ans);
	}
	return 0;
}