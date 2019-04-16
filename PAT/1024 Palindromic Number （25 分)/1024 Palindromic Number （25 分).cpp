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
	int d[1010], len;
	bign() {
		memset(d, 0, sizeof(d));
		len = 0;
	}
};
bool isPalindromic(bign a) {
	for (int i = 0; i < a.len / 2; i++) {
		if (a.d[i] != a.d[a.len - i - 1])	return 0;
	}
	return 1;
}
bign Add(bign a) {
	bign b, c;
	for (int i = 0; i < a.len; i++) {
		b.d[i] = a.d[a.len - i - 1];
		b.len++;
	}
	int carry = 0;
	for (int i = 0; i < a.len; i++) {
		int temp = a.d[i] + b.d[i] + carry;
		c.d[c.len++] = temp % 10;
		carry = temp / 10;
	}
	if (carry)	c.d[c.len++] = carry;
	return c;
}
int main() {
	char s[15];
	int k;
	bign A, B;
	scanf("%s %d", s, &k);
	for (int i = strlen(s) - 1; i >= 0; i--) {
		A.d[A.len++] = s[i] - '0';
	}
	for (int i = 0; i <= k; i++) {
		if (isPalindromic(A) || i == k) {
			for (int j = A.len - 1; j >= 0; j--) {
				printf("%d", A.d[j]);
			}
			printf("\n%d", i);
			break;
		}
		A = Add(A);
	}
	return 0;
}