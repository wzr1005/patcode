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
double p, r;
vector<int> child[maxn];
int num = 0, ans = 0, maxdepth = 0;
void DFS(int index, int depth) {
	if (child[index].size() == 0) {
		if (depth > maxdepth) {
			maxdepth = depth;
			num = 1;
		}
		else if (depth == maxdepth) {
			num++;
		}
		return;
	}
	for (int i = 0; i < child[index].size(); i++) {
		DFS(child[index][i], depth + 1);
	}
}
int main() {
	int root, father;
	scanf("%d%lf%lf", &n, &p, &r);
	r /= 100;
	for (int i = 0; i < n; i++) {
		scanf("%d", &father);
		if (father != -1) {
			child[father].push_back(i);
		}
		if (father == -1) {
			root = i;
		}
	}
	DFS(root, 0);
	printf("%.2f %d", p * pow(1 + r, maxdepth), num);
	return 0;
}