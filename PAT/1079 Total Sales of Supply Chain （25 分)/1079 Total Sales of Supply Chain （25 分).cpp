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
const int maxn = 100010;
int n;
struct BTnode {
	double data;
	vector<int> child;
}node[maxn];
double p, r, ans = 0;
void DFS(int index, int depth) {
	if (node[index].child.size() == 0) {
		ans += node[index].data * pow(1 + r, depth);
		return;
	}
	for (int i = 0; i < node[index].child.size(); i++) {
		DFS(node[index].child[i], depth + 1);
	}
}
int main() {
	scanf("%d%lf%lf", &n, &p, &r);
	int k, child;
	r /= 100;
	for (int i = 0; i < n; i++) {
		scanf("%d", &k);
		if (k == 0)
			scanf("%lf", &node[i].data);
		else {
			for (int j = 0; j < k; j++) {
				scanf("%d", &child);
				node[i].child.push_back(child);
			}
		}
	}
	DFS(0, 0);
	printf("%.1lf", p * ans);
	return 0;
}