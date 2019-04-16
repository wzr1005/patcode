#include <cstdio>
#include <algorithm>
using namespace std;
int n, p, a[100010];
long long binarySearch(int i, long long x) {
	if (a[n - 1] <= x) return n;
	int l = i + 1, r = n - 1, mid;
	while (l < r) {
		mid = (l + r) / 2;
		if (a[mid] <= x) {
			l = mid + 1;
		}
		else r = mid;
	}
	return l;
}
int main() {
	scanf("%d%d", &n, &p);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	int ans = 1;//至少有一个 因为p是整数
	for (int i = 0; i < n; i++) {
		//在a[i+1]~a[n-1]中查找第一个超过a[i]*p的数，返回其位置给j
		int j = binarySearch(i, (long long)a[i] * p);
		ans = max(ans, j - i);
	}
	printf("%d", ans);
}