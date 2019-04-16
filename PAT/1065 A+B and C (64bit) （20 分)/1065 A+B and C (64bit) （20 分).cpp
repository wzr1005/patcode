#include <cstdio>
int main() {
	int T, tcase = 1;
	scanf("%d", &T);
	long long a, b, c, res;
	while (T--) {
		int flag = 0;
		scanf("%lld%lld%lld", &a, &b, &c);
		res = a + b;
		if (a > 0 && b > 0 && res < 0) flag = 1;
		else if (a < 0 && b < 0 && res >= 0) flag = 0;
		else if (a + b > c) flag = 1;
		if (flag) printf("Case #%d: true\n", tcase++);
		else  printf("Case #%d: false\n", tcase++);
	}
	return 0;
}