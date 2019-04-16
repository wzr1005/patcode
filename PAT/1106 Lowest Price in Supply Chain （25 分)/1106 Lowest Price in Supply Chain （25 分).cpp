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
const int INF = 1e12;
vector<int> child[maxn];
int n, num = 0;
double p, r, ans = INF;
void BFS(int index, int depth) {
	if (child[index].size() == 0) {
		double price = p * pow(1 + r, depth);
		if (ans > price) {
			ans = price;
			num = 1;
		}
		else if (ans == price)
			num++;
	}
	for (int i = 0; i < child[index].size(); i++) {
		BFS(child[index][i], depth + 1);
	}
}
int main() {
	scanf("%d%lf%lf", &n, &p, &r);
	int k, tmp;
	r /= 100;
	for (int i = 0; i < n; i++) {
		scanf("%d", &k);
		for (int j = 0; j < k; j++) {
			scanf("%d", &tmp);
			child[i].push_back(tmp);
		}
	}
	BFS(0, 0);
	printf("%.4f %d", ans, num);
	return 0;
}