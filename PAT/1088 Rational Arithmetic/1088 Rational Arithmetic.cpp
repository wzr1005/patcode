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
long long a, b, c, d;
long long gcd(long long a, long long b) {
	if (b == 0)	return a;
	else return gcd(b, a % b);
}
void printR(long long m, long long n) {
	if (n * m == 0) {
		if (n == 0)	printf("Inf");
		else if (m == 0)	printf("0");
		return;
	}
	long long x = m / n;
	if (x < 0) {

		x = -x;
	}
	long long g = gcd(abs(m), abs(n));
	m /= g, n /= g;//分数已化成最简
	if (m * n < 0) {
		printf("(-");
		m = abs(m) - x * abs(n);
		if (x) {
			printf("%lld", x);
			if (m) {
				printf(" %lld/%lld)", m, abs(n));
			}
			else
				printf(")");
		}
		else {
			printf("%lld/%lld)", m, abs(n));
		}
		
	}
	else {
		m = abs(m) - x * abs(n);
		if (x) {
			printf("%lld", x);
			if (m) {
				printf(" %lld/%lld", m, n);
			}
			
		}
		else {
			printf("%lld/%lld", m, n);
		}
	}
}
int main() {
	scanf("%lld/%lld %lld/%lld", &a, &b, &c, &d);
	printR(a, b); printf(" + "); printR(c, d); printf(" = "); printR(a*d + c * b, b * d); printf("\n");
	printR(a, b); printf(" - "); printR(c, d); printf(" = "); printR(a*d - c * b, b * d); printf("\n");
	printR(a, b); printf(" * "); printR(c, d); printf(" = "); printR(a*c, b * d); printf("\n");
	printR(a, b); printf(" / "); printR(c, d); printf(" = "); printR(a*d, b * c);
	return 0;
}