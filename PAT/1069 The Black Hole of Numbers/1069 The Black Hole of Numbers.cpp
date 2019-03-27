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
	string s;
	cin >> s;
	s.insert(0, 4 - s.size(), '0');
	do {
		string a = s, b = s;
		sort(a.begin(), a.end(), greater<char>());
		sort(b.begin(), b.end());
		int x = stoi(a) - stoi(b);
		s = to_string(x);
		s.insert(0, 4 - s.size(), '0');
		cout << a << " - " << b <<" = "<< s << '\n';
	} while (s != "6174"&&s != "0000");
	return 0;
}