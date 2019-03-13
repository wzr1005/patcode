#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxc = 210;
const int maxn = 10010;
int n, m, l, x;
int colororder[maxc], dp[maxn], A[maxn];
int main() {
	scanf("%d%d", &n, &m);
	memset(colororder, -1, sizeof(colororder));
	for (int i = 0; i < m; i++) {
		scanf("%d", &x);
		colororder[x] = i;
	}
	int l, num = 0;
	scanf("%d", &l);
	for (int i = 0; i < l; i++) {
		scanf("%d", &x);
		if (colororder[x] >= 0) {
			A[num++] = colororder[x];
		}
	}
	int ans = -1;
	for (int i = 0; i < num; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (A[j] <= A[i] && dp[i] < dp[j] + 1) {//dp[i] < dp[j] + 1意思是找d[i]在前面序列的状态最大值 + 1，因为a[i] >= a[j]
				//通俗来说就是，在dp[i]位置时，从j属于0~i-1里面找到A[j] <= A[i]的，即满足颜色序列比他小的，且dp[j]里最大的一个位置
				//dp[i] = dp[j] + 1
				dp[i] = dp[j] + 1;
			}
		}
		ans = max(ans, dp[i]);
	}
	printf("%d\n", ans);
	return 0;
}