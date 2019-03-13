#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 10010;
const int maxm = 110;
int dp[maxn] = { 0 }, w[maxn];
int choice[maxn][maxm], flag[maxn], ans[maxn];
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &w[i]);
	}
	sort(w + 1, w + n + 1, cmp);
	for (int i = 1; i <= n; i++) {
		for (int v = m; v >= w[i]; v--) {
			if (dp[v] <= dp[v - w[i]] + w[i]) {
				dp[v] = dp[v - w[i]] + w[i];
				choice[i][v] = 1;
			}
			else {
				choice[i][v] = 0;//之所以要逆序，就体现在这里，
				//因为动态规划数组更新总是后面的答案覆盖前面的结果，
				//这样符合要求的小硬币只要相等也会取代
				//然后choice的k从n开始逆序遍历找采纳的硬币
				//代码41行保证了刚刚好取走m的总值。
			}
		}
	}
	if (dp[m] != m) {
		printf("No Solution");
	}
	else {
		int k = n, v = m, num = 0;
		while (k > 0) {
			if (choice[k][v]) {
				ans[num++] = w[k];
				v -= w[k];//刚好拿走硬币最小的几个 总和为v
			}
			k--;
		}
		for (int i = 0; i < num; i++) {
			printf("%d", ans[i]);
			if (i != num-1)	printf(" ");
		}
	}
	return 0;
}