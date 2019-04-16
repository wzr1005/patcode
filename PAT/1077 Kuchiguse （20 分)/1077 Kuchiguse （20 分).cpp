#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main() {
	char ans[280] = { 0 };
	char temp[110][280] = { 0 };
	int n, num = 0, flag = 1;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		getchar();
		scanf("%[^\n]", temp[i]);
	}
	int minlen = 10000;
	for (int i = 0; i < n; i++) {
		int len = strlen(temp[i]);
		if (len < minlen) minlen = len;
		reverse(temp[i], temp[i] + len);
	}
	for (int i = 0; i < minlen; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (temp[j][i] != temp[j + 1][i]) {
				flag = 0;
				break;
			}
		}
		if (flag) ans[num++] = temp[0][i];
		else break;
	}
	if (num) {
		reverse(ans, ans + num);
		printf("%s", ans);
	}
	else printf("nai");
}