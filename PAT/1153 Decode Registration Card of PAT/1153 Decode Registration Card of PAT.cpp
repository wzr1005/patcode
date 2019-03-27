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
#include <unordered_map>
#include <ctype.h>
using namespace std;
int n, m;
struct student {
	string number;
	int score, site, date;//分数，考场，日期
};
vector<student> Level[3], Sitenum[1000];
unordered_map<int, vector<student> > Date;
int main() {
	cin >> n >> m;
	int d;
	string s;
	vector<student> stu(n);
	for (int i = 0; i < n; i++) {
		cin >> stu[i].number >> stu[i].score;
		// B123180908127 99
		stu[i].site = stoi(stu[i].number.substr(1, 3));
		if (stu[i].number[0] == 'A') {
			Level[0].push_back(stu[i]);
		}
		else if (stu[i].number[0] == 'B') {
			Level[1].push_back(stu[i]);
		}
		else {
			Level[2].push_back(stu[i]);
		}
		stu[i].date = stoi(stu[i].number.substr(4, 9));
		Sitenum[stu[i].site].push_back(stu[i]);
		Date[stu[i].date].push_back(stu[i]);
	}
	for (int i = 1; i <= m; i++) {
		int kind;
		scanf("%d", &kind);
		printf("Case %d: %d ", i, kind);
	}
	return 0;
}