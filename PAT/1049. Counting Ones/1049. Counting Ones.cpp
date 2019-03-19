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
int main() {//分情况讨论 now 为0 1 其他
	int n, a = 1, ans = 0;
	int left, now, right;
	scanf("%d", &n);
	while (n / a != 0) {//a是位数
		left = n / (a * 10);
		now = n / a % 10;
		right = n % a;
		if (now == 0) ans += left * a;
		else if (now == 1) {
			ans += (left * a + right + 1);//右边是在左边固定的范围内变动
		}
		else {
			ans += (left + 1) * a;
		}
		a *= 10;
	}
	printf("%d", ans);
	return 0;
}