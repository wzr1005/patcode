#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> p(n);
	map<int, int> mp;
	for (int i = 0; i < n; i++) {
		cin >> p[i];
		mp[p[i]]++;
	}
	int flag = 1;
	for (int i = 0; i < n; i++) {
		if (mp[p[i]] == 1) {
			cout << p[i];
			flag = 0;
			break;
		}
	}
	if (flag)	cout << "None";
}