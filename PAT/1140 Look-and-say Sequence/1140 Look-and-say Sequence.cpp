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
	int n, k;
	cin >> n >> k;
	string s, ans;
	s += n + '0';//s存了第一个元素D
	while (k--) {
		int cnt = 1;
		for (int i = 0; i < s.size()-1; i++) {
			if (s[i + 1] == s[i]) {
				cnt++;
			}
			else {
				ans += s[i];
				ans += cnt + '0';
			}
		}
	}
	return 0;
}