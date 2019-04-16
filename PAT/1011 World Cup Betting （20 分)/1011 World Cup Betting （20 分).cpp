#include <cstdio>
#include <cmath>
char s[3] = { 'W', 'T', 'L' };
int main() {
	double ans = 1.0, temp, a;
	int idx;
	for (int i = 0; i < 3; i++) {
		temp = 0.0;
		for (int j = 0; j < 3; j++) {
			scanf("%lf", &a);
			if (temp < a) {
				temp = a;
				idx = j;
			}
		}
		ans *= temp;
		printf("%c ", s[idx]);
	}
	ans = (ans * 0.65 - 1) * 2;
	ans = floor(ans * 100 + 0.5) / 100.0;
	printf("%.2f", ans);
	return 0;
}