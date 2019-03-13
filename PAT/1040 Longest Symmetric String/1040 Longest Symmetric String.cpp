#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 1010;
char s[maxn];
int dp[maxn][maxn] = { 0 };
int main() {
	scanf("%[^\n]", s);
	int len = strlen(s), ans = 1;
	for (int i = 0; i < len; i++) {
		dp[i][i] = 1;
		if (i < len - 1) {
			if (s[i] == s[i + 1]) {
				dp[i][i + 1] = 1;
				ans = 2;
			}
		}
	}
	for (int L = 3; L <= len; L++) {
		for (int i = 0; i + L - 1 < len; i++) {
			int j = i + L - 1;
			if (s[i] == s[j] && dp[i + 1][j - 1] == 1) {
				dp[i][j] = 1;
				ans = L;
			}
		}
	}
	printf("%d", ans);
}