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
const int maxc = 210;
const int maxn = 10010;
int A[maxc], B[maxn], dp[maxc][maxn];
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d", &A[i]);
	}
	int L;
	scanf("%d", &L);
	for (int i = 1; i <= L; i++) {
		scanf("%d", &B[i]);
	}
	for (int i = 0; i <= m; i++) {
		dp[i][0] = 0;
	}
	for (int j = 0; j <= L; j++) {
		dp[0][j] = 0;
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= L; j++) {

		}
	}
	return 0;
}