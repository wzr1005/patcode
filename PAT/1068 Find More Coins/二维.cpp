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
const int maxn = 1e4 + 10;
const int maxm = 1e2 + 10;
int a[maxn], dp[maxn][maxm], pre[maxn][maxm];
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	dp[0][0] = 1;
	memset(pre, 0xff, sizeof pre);//³õÊ¼»¯Îª-1
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			if (dp[i - 1][j]) {

			}
		}
	}
	return 0;
}