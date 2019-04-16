#include <cstdio>
#include <cmath>
struct factor {
	int x, cnt;
}fac[10];
int judge(int n) {
	for (int i = 2; i <= (int)sqrt(n*1.0); i++) {
		if (n % i == 0) return 0;
	}
	return 1;
}
int prime[1000010];
int main() {
	int n;
	int num = 0;
	scanf("%d", &n);
	int k = 0, i;
	printf("%d=", n);
	//getchar();
	//getchar();
	if (n == 1) { printf("1"); return 0; }
	if (judge(n)) {
		printf("%d", n);
		return 0;
	}
	for (int j = 2; j <= n; j++) {
		if (judge(j)) {
			prime[num++] = j;	//printf("%d ", prime[num - 1]);
			for (i = 0; i < num; i++) {
				if (n % prime[i] == 0) {
					fac[k].x = prime[i];
					fac[k].cnt = 0;
					while (n % prime[i] == 0) {
						fac[k].cnt++;
						n /= prime[i];
					}
					k++;
				}
			}
		}
	}
	for (int i = 0; i < k; i++) {
		if (i > 0)	printf("*");
		printf("%d", fac[i].x);
		if (fac[i].cnt > 1)	printf("^%d", fac[i].cnt);
	}
	return 0;
}