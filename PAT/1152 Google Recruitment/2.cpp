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
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0)	return 0;
	}
	return 1;
}
int main() {
	int l, k; string s;
	scanf("%d %d", &l, &k);
	cin  >> s;
	for (int i = 0; i < l - k + 1; i++) {
		long long ans = 0, len = 0;
		int flag = 1;//?
		for (int j = i; j < i + k; j++) {
			if (s[j] != '0')	flag = 0;//统计前缀0的个数
			if (flag) len++;
			ans = ans * 10 + s[j] - '0';
		}
		if (isprime(ans)) {
			while (len--) {
				cout << "0";
			}
			cout << ans;
			return 0;
		}
	}
	printf("404");
	return 0;
}