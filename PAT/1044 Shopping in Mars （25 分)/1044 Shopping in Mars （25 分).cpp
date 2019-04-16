#include <cstdio>
const int N = 100010;
const int INF = 10000010;
int s, nears = INF;
int sum[N];
int upper_bound(int left, int right, int x) {
	int mid;
	while (left < right) {
		mid = (left + right) / 2;
		if (sum[mid] > x)	right = mid;
		else left = mid + 1;
	}
	return left;
}
int main() {
	int n;
	scanf("%d%d", &n, &s);
	sum[0] = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &sum[i]);
		sum[i] += sum[i - 1];
	}
	for (int i = 1; i <= n; i++) {
		int j = upper_bound(i, n + 1, sum[i - 1] + s);//¼Ç×¡×ó±ÕÓÒ¿ª
		if (sum[j - 1] - sum[i - 1] == s) {
			nears = s;
			break;
		}
		else {
			if (j <= n && sum[j] - sum[i - 1] < nears) {
				nears = sum[j] - sum[i - 1];
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		int j = upper_bound(i, n + 1, sum[i - 1] + nears);
		if (sum[j - 1] - sum[i - 1] == nears) {
			printf("%d-%d\n", i, j - 1);
		}
	}
	return 0;
}