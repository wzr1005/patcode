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
int main() {
	int n, x;
	long long p;
	cin >> n >> p;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + res; j < n; j++) {
			if (v[j] <= v[i] * p) {//这里p要用long long,因为v[i]*p可能会溢出
				int len = j - i + 1;
				if (res < len)	res = len;
			}//如果v[j] > v[i]*p 就可以停止了，从一个i开始，
			//res保存最大长度
			else break;
		}
	}
	cout << res;
	return 0;
}