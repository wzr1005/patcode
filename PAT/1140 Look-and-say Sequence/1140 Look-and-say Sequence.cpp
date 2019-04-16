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
	int k;
	string s;
	cin >> s >> k;
	string ans = s;
	//D
	//D1
	//D111
	//s存了第一个元素D
	while (k--) {
		s = ans;
		ans = "";
		//cout << s << "\n";
		int cnt = 1;
		for (int i = 0; i < s.size(); i++) {
			//cout << i << "i\n";
			if ((i+1) < s.size()&&s[i + 1] == s[i]) {
				cnt++;
			}
			else {
				ans += s[i];
				ans += cnt + '0';
				cnt = 1;
			}
		}
		//s = ans;
	}
	cout << s;
	return 0;
}