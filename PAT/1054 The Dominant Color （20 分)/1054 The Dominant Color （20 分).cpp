#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;
int main() {
	int m, n;
	scanf("%d%d", &m, &n);
	map<int, int> mp;
	int temp;
	for (int i = 0; i < n; i++) {
		for (int i = 0; i < m; i++) {
			scanf("%d", &temp);
			mp[temp]++;
		}
	}
	int max = 0, d;
	for (auto it = mp.begin(); it != mp.end(); it++) {
		if (max < it->second) {
			max = it->second;
			d = it->first;
		}
	}
	printf("%d", d);
}