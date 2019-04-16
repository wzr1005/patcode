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
struct bign {
	int d[25], len;
	bign() {
		memset(d, 0, sizeof(d));
		len = 0;
	}
}A;
int main() {
	char s[25];
	scanf("%s", s);
	set<char> ans;
	for (int i = 0; i < strlen(s); i++) {
		ans.insert(s[i]);
	}//012345
	for (int i = strlen(s) - 1; i >= 0; i--) {
		A.d[A.len++] = s[i] - '0';
	}
	while (A.d[A.len - 1] == 0 && A.len > 1)	A.len--;
	int carry = 0;
	bign C;
	for (int i = 0; i < A.len; i++) {
		int temp = 2 * A.d[i] + carry;
		C.d[C.len++] = temp % 10;
		carry = temp / 10;
	}
	if (carry) {
		C.d[C.len++] = carry;
	}
	int flag = 1;
	set<char> temp;
	for (int i = 0; i < C.len; i++) {//³ËÒÔ2ÊÇ
		temp.insert(C.d[i] + '0');
	}
	if (ans == temp)	printf("Yes\n");
	else printf("No\n");
	for (int i = C.len - 1; i >= 0; i--) {
		printf("%d", C.d[i]);
	}
	return 0;
}