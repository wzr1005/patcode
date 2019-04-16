#include <cstdio>
int main() {
	int e, n, count = 0;
	double k, A[1010] = { 0 }, B[1010] = { 0 }, ans[2010] = { 0 };
	//kÊÇÏµÊý
	scanf("%d", &n);
	while (n--) {
		scanf("%d%lf", &e, &k);
		A[e] = k;
	}scanf("%d", &n);
	while (n--) {
		scanf("%d%lf", &e, &k);
		B[e] = k;
	}
	for (int i = 1000; i >= 0; i--) {
		if (A[i] != 0.0) {
			//printf("%d %.1f\n", i, A[i]);
			for (int j = 1000; j >= 0; j--) {
				if (B[j] != 0.0) {
					//printf("%d %.1f\n", j, B[j]);
					//if (ans[i + j] == 0.0) count++;
					ans[i + j] += A[i] * B[j];
					//printf("%d %.1f\n", i+j, ans[i+j]);
				}
			}
		}
	}
	for (int i = 0; i < 2001; i++) {
		if (ans[i] != 0) count++;
	}
	//printf("haha");
	if (count == 0) printf("%d", count);
	else {
		printf("%d ", count);
		for (int i = 2000; i >= 0; i--) {
			if (ans[i] != 0.0) {
				printf("%d %.1f", i, ans[i]);
				--count;
				if (count != 0) printf(" ");
			}
		}
	}
	return 0;
}