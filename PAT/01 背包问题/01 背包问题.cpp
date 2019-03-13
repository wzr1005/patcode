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
const int maxn = 110;
const int maxv = 1010;
int w[maxn], c[maxn], dp[maxn][maxv];
int main() {
	int n, V;
	scanf("%d%d", &n, &V);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &w[i]);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &c[i]);
	}
	for (int i = 0; i <= n; i++) {
		dp[i][0] = 0;
	}
	for (int i = 1; i <= V; i++)
	{
		dp[0][i] = 0;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= V; j++) {
			if (j < w[i]) {//包放不进， 就不放，继承没放的状态
				dp[i][j] = dp[i - 1][j];//j容量保持不变
			}
			else {
				//能装
				if (dp[i - 1][j] > dp[i - 1][j - w[i]] + c[i]) {
					//不如不装,继承
					dp[i][j] = dp[i - 1][j];
				}
				else {
					dp[i][j] = dp[i - 1][j - w[i]] + c[i];
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= V; j++) {
			printf("%d ", dp[i][j]);
		}
		printf("\n");
	}
	printf("%d", dp[n][V]);
	return 0;
}
/*
5 8
3 5 1 2 2
4 5 2 1 3
*/