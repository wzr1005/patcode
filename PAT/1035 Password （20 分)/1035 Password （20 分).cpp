#include <cstdio>
struct password {
	char id[15];
	char p[20];
	int flag;
}A[1100];
int main() {
	int n, count = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		getchar();
		scanf("%s %s", A[i].id, A[i].p);
		A[i].flag = 0;
		int k = 0;
		while (A[i].p[k] != '\0') {
			if (A[i].p[k] == '1') {
				A[i].p[k] = '@';
				A[i].flag = 1;
			}if (A[i].p[k] == '0') {
				A[i].p[k] = '%';
				A[i].flag = 1;
			}if (A[i].p[k] == 'l') {
				A[i].p[k] = 'L';
				A[i].flag = 1;
			}if (A[i].p[k] == 'O') {
				A[i].p[k] = 'o';
				A[i].flag = 1;
			}
			k++;
		}
		if (A[i].flag) count++;
	}
	if (count) {
		printf("%d\n", count);
		for (int i = 0; i < n; i++) {
			if (A[i].flag) printf("%s %s\n", A[i].id, A[i].p);
		}
	}
	else {
		if (n == 1)	printf("There is 1 account and no account is modified\n");
		if (n > 1)	printf("There are %d accounts and no account is modified\n", n);
	}

	return 0;
}