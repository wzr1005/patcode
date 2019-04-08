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
map<int, int> mp;
int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		mp[x]++;
	}
	int i = 0;
	while (++i) {
		if (mp[i] == 0) break;
	}
	cout << i;
	return 0;
}