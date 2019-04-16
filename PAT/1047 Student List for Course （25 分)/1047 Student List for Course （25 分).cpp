#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 40010;
const int maxc = 2501;
char name[maxn][6];
vector<int> course[maxc];
bool cmp(int a, int b) {
	return strcmp(name[a], name[b]) < 0;
}
int main() {
	int n, k, x, courseID;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%s%d", name[i], &x);
		for (int j = 0; j < x; j++) {
			scanf("%d", &courseID);
			course[courseID].push_back(i);
		}
	}
	for (int i = 1; i <= k; i++) {
		printf("%d %d\n", i, course[i].size());
		sort(course[i].begin(), course[i].end(), cmp);
		for (int j = 0; j < course[i].size(); j++) {
			printf("%s\n", name[course[i][j]]);
		}
	}
	return 0;
}