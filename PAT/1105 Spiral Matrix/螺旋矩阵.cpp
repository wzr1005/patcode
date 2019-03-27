#include <cstdio>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <cstring>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <ctype.h>
using namespace std;
const int maxn = 10010;
int A[maxn], ans[maxn][maxn];
int main() {
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	sort(A, A + N, greater<int>());
	int m, n, sqr = sqrt(N);
	for (int i = 1; i <= sqr; i++) {
		if (N % i == 0) {
			n = i;
		}
	}
	m = N / n;
	int left = 1, right = n, up = 1, down = m, i = 1, j = 1;
	int num = 0;
	if (n == 1 && m == 1)	ans[i][j] = A[0];
	while (num < N) {
		while (j < right&&num < N) {
			ans[i][j++] = A[num++];
		}
		while (i < down&&num < N) {
			ans[i++][j] = A[num++];
		}
		while (j > left && num < N) {
			ans[i][j--] = A[num++];
		}
		while (i > up&&num < N) {
			ans[i--][j] = A[num++];
		}
		up++, down--, left++, right--;

		i++, j++;
		if (num == N - 1) {
			ans[i][j] = A[num++];
		}
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			printf("%d", ans[i][j]);
			if (j < n)	printf(" ");
		}
		printf("\n");
	}
	return 0;
}