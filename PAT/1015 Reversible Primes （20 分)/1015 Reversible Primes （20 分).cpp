#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int isprime(int a) {
	int d = (int)sqrt(1.0*a);
	if (a == 0 || a == 1)	return 0;
	for (int i = 2; i <= d; i++) {
		if (a % i == 0)	return 0;
	}
	return 1;
}
int change(int a, int b) {
	int sum = 0;
	int c[110], num = 0;
	do {
		c[num++] = a % b;
		a /= b;
	} while (a);
	for (int i = 0; i < num; i++) {
		sum = sum * b + c[i];
	}
	//printf("%d\n", sum);
	return sum;
}
int main() {
	int n, d;
	while (~scanf("%d", &n)) {
		if (n < 0) break;
		scanf("%d", &d);
		if (isprime(n) == 0) {
			printf("No\n");
		}
		else {
			if (isprime(change(n, d))) {
				printf("Yes\n");
			}
			else {
				printf("No\n");
			}
		}

	}
	return 0;
}