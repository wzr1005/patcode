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
struct student {
	string name, id;
	int score;
};
bool cmp(student a, student b) {
	return a.score > b.score;
}
int main() {
	int n, g1, g2;
	cin >> n;
	vector<student> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].name >> v[i].id >> v[i].score;
	}
	sort(v.begin(), v.end(), cmp);
	cin >> g1 >> g2;
	if (g1 > g2)	swap(g1, g2);
	int flag = 0;
	for (int i = 0; i < n; i++) {
		if (v[i].score >= g1 && v[i].score <= g2) {
			flag = 1;
			cout << v[i].name << " " << v[i].id << '\n';
		}
		else if (v[i].score < g1)	break;
	}
	if (!flag)	cout << "NONE";
	return 0;
}