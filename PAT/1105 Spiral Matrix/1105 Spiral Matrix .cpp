#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn = 10010;
int A[maxn], matrix[maxn][maxn];
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &A[i]);
	}
	if (n == 1) {
		printf("%d", A[0]);
		return 0;
	}
	sort(A , A + n, cmp);
	int m = (int)ceil(sqrt(1.0*n));
	while (n % m != 0) {
		m++;
	}
	int v = n / m;
	int left = 1, right = v, up = 1, down = m;
	int i = 1, j = 1, now = 0;
	while (now < n) {
		while (now < n&&j < right) {
			matrix[i][j] = A[now++];
			j++;
		}
		while (now < n&&i < down) {
			matrix[i][j] = A[now++];
			i++;
		}
		while (now < n&&j > left) {
			matrix[i][j] = A[now++];
			j--;
		}
		while (now < n&&i > up) {
			matrix[i][j] = A[now++];
			i--;
		}
		up++, down--, left++, right--;
		i++, j++;
		if (now == n - 1)	matrix[i][j] = A[now++];
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= v; j++) {
			printf("%d", matrix[i][j]);
			if (j < v)	printf(" ");
			else printf("\n");
		}
	}
}