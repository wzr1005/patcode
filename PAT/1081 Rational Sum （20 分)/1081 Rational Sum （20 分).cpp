#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
struct Fraction {
	LL up, down;
};
LL gcd(LL a, LL b) {
	if (b == 0) return a;
	else return gcd(b, a%b);
}
Fraction reduction(Fraction result) {
	if (result.down < 0) {
		result.up = -result.up;
		result.down = -result.down;
	}
	if (result.up == 0) {
		result.down = 1;
	}
	else {
		int d = gcd(abs(result.up), abs(result.down));
		result.up /= d;
		result.down /= d;
	}
	return result;
}
Fraction add(Fraction f1, Fraction f2) {
	Fraction result;
	result.up = f1.up * f2.down + f1.down * f2.up;
	result.down = f1.down * f2.down;
	return reduction(result);
}
void print(Fraction r) {
	if (r.down == 1) printf("%lld\n", r.up);
	else if (abs(r.up) > abs(r.down)) {
		printf("%lld %lld/%lld\n", r.up / r.down, abs(r.up) % r.down, r.down);
	}
	else
		printf("%lld/%lld", r.up, r.down);
}
int main() {
	int n;
	scanf("%d", &n);
	Fraction sum, temp;
	sum.up = 0, sum.down = 1;
	for (int i = 0; i < n; i++) {
		scanf("%lld/%lld", &temp.up, &temp.down);
		sum = add(sum, temp);
	}
	print(sum);
	return 0;
}