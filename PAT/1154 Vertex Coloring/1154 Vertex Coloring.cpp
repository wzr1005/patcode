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
const int maxn = 10010;
struct edge {
	int v1, v2;
	edge(int _v1, int _v2) {
		v1 = _v1;
		v2 = _v2;
	}
};
int n, m;
vector<edge> edges;
int main() {
	cin >> n >> m;
	int v1, v2;
	for (int i = 0; i < m; i++) {
		cin >> v1 >> v2;
		edges.push_back(edge(v1, v2));
	}
	int k; cin >> k;
	int color[maxn];
	for (int i = 0; i < k; i++) {
		set<int>cset;
		for (int j = 0; j < n; j++) {
			cin >> color[j];
			cset.insert(color[j]);
		}
		int flag = 1;
		for (int j = 0; j < edges.size(); j++) {
			if (color[edges[j].v1] == color[edges[j].v2]) {
				printf("No\n");
				flag = 0;
				break;
			}
		}
		if (flag)	printf("%d-coloring\n", cset.size());
	}
	return 0;
}