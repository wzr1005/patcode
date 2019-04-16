#include <cstdio>
#include <iostream>
#include <ctype.h>
#include <map>
#include <string>
using namespace std;
int main() {
	string s, ans;
	getline(cin, s);
	map<string, int> mp;
	for (int i = 0; i < s.size(); i++) {
		ans = "";
		if (isalnum(s[i])) {
			while (isalnum(s[i])) {
				s[i] = towlower(s[i]);
				ans += s[i];
				i++;
			}
			mp[ans]++;
			//printf("%c mp[%s] = %d, \n", s[i], ans.c_str(), mp[ans]);
		}
	}
	int max = 0;
	for (auto it = mp.begin(); it != mp.end(); it++) {
		if (it->second > max) {
			max = it->second;
			ans = it->first;
		}
	}
	printf("%s %d", ans.c_str(), max);
}