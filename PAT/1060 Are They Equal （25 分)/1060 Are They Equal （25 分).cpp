#include <iostream>
#include <string>
using namespace std;
int n;
string deal(string s, int &e) {
	int k = 0;
	string ans;
	while (s.length() > 0 && s[0] == '0') {
		s.erase(s.begin());
	}
	if (s[0] == '.') {
		s.erase(s.begin());
		while (s.length() > 0 && s[0] == '0') {
			e--;
			s.erase(s.begin());
		}
	}
	else {
		while (s.length() > k && s[k] != '.') {
			e++;
			k++;
		}
		if (k < s.length()) {
			s.erase(s.begin() + k);
		}
	}
	if (s.length() == 0) {
		e = 0;
	}
	int num = 0;
	k = 0;
	while (num < n) {
		if (k < s.length()) ans += s[k++];//只要还有数字
		else ans += '0';
		num++;
	}
	return ans;
}
int main() {
	string s1, s2, s3, s4;
	int e1 = 0, e2 = 0;
	cin >> n >> s1 >> s2;
	s3 = deal(s1, e1);
	s4 = deal(s2, e2);
	if (s3 == s4 && e1 == e2) {
		cout << "YES 0." << s3 << "*10^" << e1 << endl;
	}
	else {
		cout << "NO 0." << s3 << "*10^" << e1 << " 0." << s4 << "*10^" << e2 << endl;
	}
}