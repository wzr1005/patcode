#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100010;
int main() {
	int coupon[maxn], product[maxn];
	int n, m;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &coupon[i]);
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &product[i]);
	}
	sort(coupon, coupon + n);
	sort(product, product + m);
	int i = 0, j = 0, ans = 0;
	while (i < n&&i < m&&coupon[i] < 0 && product[i] < 0) {
		ans += coupon[i] * product[i];
		i++;
	}
	i = n - 1;
	j = m - 1;
	while (i >= 0 && j >= 0 && coupon[i] > 0 && product[j] > 0) {
		ans += coupon[i] * product[j];
		i--, j--;
	}
	printf("%d\n", ans);
}