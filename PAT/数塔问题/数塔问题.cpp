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
const int maxn = 1000;
int f[maxn][maxn], dp[maxn][maxn];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			scanf("%d", &f[i][j]);
		}
	}
	for (int i = 5; i >= 1; i--) {
		dp[n][i] = f[n][i];
	}
	for (int i = 4; i >= 1; i--) {
		for (int j = 1; j <= i; j++) {
			dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]) + f[i][j];
		}
	}
	printf("%d", dp[1][1]);
	return 0;
}
/*
5
5
8 3
12 7 16
4 10 11 6
9 5 3 9 4
44
*/