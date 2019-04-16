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
///注意初始的时候
struct bign {
	int d[1010] = { 0 };
	int len = 0;
};
int isPalindrome(bign a) {
	
	for (int i = 0; i < a.len/2; i++) {
		if (a.d[i] != a.d[a.len - i - 1])	return 0;
	}
	return 1;
}
bign stringToint(string s) {
	bign a;
	for (int i = s.length() - 1; i >= 0; i--) {
		a.d[a.len++] = s[i] - '0';
	}
	return a;
}
bign reverse(bign a) {
	bign c;
	for (int i = a.len - 1; i >= 0; i--) {
		c.d[c.len++] = a.d[i];
	}
	return c;
}
bign add(bign a) {
	bign c;
	int carry = 0;

	for (int i = 0; i < a.len; i++) {
		int temp = a.d[i] + a.d[a.len - 1 - i] + carry;
		c.d[c.len++] = temp % 10;
		carry = temp / 10;

	}
	if (carry)	c.d[c.len++] = carry;
	return c;
}
void print(bign a) {
	for (int i = a.len - 1; i >= 0; i--) {
		printf("%d", a.d[i]);
	}
}
int main() {
	string s;
	cin >> s;
	bign a = stringToint(s);
	if (isPalindrome(a)) {
		print(a);
		printf(" is a palindromic number.\n");
		return 0;
	}
	for (int i = 1; i <= 10; i++) {
		print(a);
		printf(" + ");
		print(reverse(a));
		printf(" = ");
		bign c = add(a);
		print(c);
		printf("\n");
		if (isPalindrome(c)) {
			print(c);
			printf(" is a palindromic number.\n");
			return 0;
		}
		a = c;
	}
	printf("Not found in 10 iterations.\n");
	return 0;
}