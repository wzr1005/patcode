#include <cstdio>
const int maxn = 10010;
int a[maxn], dp[maxn], s[maxn];
int main() {
	int n, flag = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		if (a[i] >= 0) {
			flag = 1;
		}
	}
	if (flag == 0) {
		printf("0 %d %d\n", a[0], a[n - 1]);
		return 0;
	}
	dp[0] = a[0], s[0] = 0;
	for (int i = 1; i < n; i++) {
		if (a[i] < dp[i - 1] + a[i]) {
			dp[i] = dp[i - 1] + a[i];
			s[i] = s[i-1];
		}
		else {
			dp[i] = a[i];
			s[i] = i;
		}
	}
	int k = 0;
	for (int i = 0; i < n; i++) {
		if (dp[k] < dp[i]) {
			k = i;
		}
	}
	printf("%d %d %d", dp[k], a[s[k]], a[k]);
	return 0;
}