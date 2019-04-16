#include <cstdio>
int main() {
	int e, k, count = 0;
	double c;
	double A[1010] = { 0 }, B[1010] = { 0 };
	scanf("%d", &k);
	while (k--) {
		scanf("%d%lf", &e, &c);
		A[e] = c;
	}
	scanf("%d", &k);
	while (k--) {
		scanf("%d%lf", &e, &c);
		B[e] = c;
	}
	for (int i = 0; i < 1001; i++) {
		if (A[i] != 0 || B[i] != 0) {
			A[i] += B[i];
			if (A[i] != 0) count++;
		}
	}
	if (count == 0) printf("0 0");

	return 0;
}