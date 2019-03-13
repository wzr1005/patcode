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
const int N = 100;
char A[N], B[N];
int dp[N][N];
int main() {
	int n;
	scanf("%[^\n]", A + 1);
	getchar();
	scanf("%[^\n]", B + 1);
	int lenA = strlen(A + 1);
	int lenB = strlen(B + 1);
	for (int i = 0; i <= lenA; i++) {
		dp[i][0] = 0;
	}
	for (int j = 0; j <= lenB; j++) {
		dp[0][j] = 0;
	}//边界为0；
	//状态转移方程
	for (int i = 1; i <= lenA; i++) {
		for (int j = 1; j <= lenB; j++) {
			if (A[i] == B[j]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			//dp[i][j] 表示 A串前i个与B串前j个的最大公共长度
			else {
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
				//d[i][j]继承dp[i-1][j]与dp[i][j-1]的较大者
			}
		}
	}
	printf("%d", dp[lenA][lenB]);
	return 0;
}