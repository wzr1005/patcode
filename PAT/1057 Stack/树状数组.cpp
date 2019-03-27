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
#include <stack>
#include <ctype.h>
using namespace std;
const int maxn = 100050;
#define lowbit(i) ((i)&-(i))
stack<int> s;
int d[maxn] = { 0 };
int k;
void update(int x, int v) {
	for (int i = x; i < maxn; i += lowbit(i)) {
		d[i] += v;
	}
}
int getsum(int x) {
	int sum = 0;
	for (int i = x; i > 0; i -= lowbit(i)) {
		sum += d[i];
	}
	return sum;
}
void PeekMedian() {
	int l = 1, r = maxn, mid, k = (s.size() + 1) / 2;
	while (l < r) {
		mid = (l + r) / 2;
		if (getsum(mid) >= k)  r = mid;
		else l = mid + 1;
	}
	cout << l << "\n";
}
int main() {
	int n, x;
	string cmd;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		cin >> cmd;
		if (cmd == "Push") {
			scanf("%d", &x);
			s.push(x);
			update(x, 1);
		}
		else if (cmd == "Pop") {
			if (s.empty())	cout << "Invalid\n";
			else {
				update(s.top(), -1);
				cout << s.top() << "\n";
				s.pop();
			}
		}
		else if (cmd == "PeekMedian") {
			if (s.empty())	cout << "Invalid\n";
			else {
				PeekMedian();
			}
		}
	}
}
/*

summer 2019/3/24 20:33:56
我用的 maxn = 10 依次输入 4 7 8
则d[4] = 1, d[7] = 1, d[8] = 3 其余为0
mid = 5 getsum(5) = 1, < k,
L = mid + 1 = 6,
mid = (6 + 10) / 2 = 8
getsum(8) = 5 >= k
r = 8, L = 6 mid = (8 + 6)/ 2 = 7
7 >= k r = 7, L = 6 mid = 6
getsum(6) = 1 L = 6 + 1 = 7,
L == r == 7
*/