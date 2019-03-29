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
int isprime(int n) {
	if (n == 1||n == 0)	return 0;
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0)	return 0;
	}
	return 1;

}
int change(string s, int pos, int L) {
	int res = 0, num = 0;
	for (int i = pos; num < L; i++) {
		if (s[i] == '.')	continue;
		res = res * 10 + s[i] - '0';
		num++;
	}
	return res;
}
int main() {
	int L, K;
	cin >> L >> K;
	string s;
	cin >> s;
	int flag = 0, ans[15] = { 0 };
	for (int i = 0; i < s.size() - K; i++) {
		int n = change(s, i, K);
		if (isprime(n)) {
			int k = 0;
			while (n) {
				ans[k++] = n % 10; 
				n /= 10;
			}
			for (int i = K - 1; i >= 0; i--) {
				printf("%d", ans[i]);
			}
			flag = 1;
			break;
		}
	}
	if (!flag)	printf("404");
	return 0;
}