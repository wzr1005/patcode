#include <cstdio>
#include <cstring>
//n1 + n2 + n3 = N + 2
int main() {
	char str[100];
	scanf("%s", str);
	int n = strlen(str), n1 = (2 + n) / 3;
	int n2 = n - 2 * n1 + 2, i;
	char ans[100][100];
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			ans[i][j] = ' ';
		}
	}
	for (i = 0; i < n1 - 1; i++) {
		ans[i][0] = str[i];
		ans[i][n2 - 1] = str[n - i - 1];
	}
	int k = 0, f = i;
	for (i; i < n1 + n2; i++) ans[f][k++] = str[i];
	for (i = 0; i < n1; i++) {
		for (int j = 0; j < n2; j++) {
			printf("%c", ans[i][j]);
		}
		printf("\n");
	}
	return 0;
}