#include <cstdio>
int main() {
	int n, k, A[40], num = 0;
	scanf("%d%d", &n, &k);
	//考虑初始n = 0的情况
	do {
		A[num++] = n % k;
		n /= k;
	} while (n);
	int flag = 1;
	for (int i = 0; i < num / 2; i++) {
		if (A[i] != A[num - i - 1]) flag = 0;
	}
	if (flag) printf("Yes\n");
	else printf("No\n");
	for (int i = num - 1; i >= 0; i--) {
		printf("%d", A[i]);
		if (i != 0)	printf(" ");
	}
	return 0;
}