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
map<char, int> mp;

struct hashTable {
	int site;
	int value = 0;
};
bool cmp(hashTable a, hashTable b) {
	if (a.value != b.value)	return a.value > b.value;
	else return a.site < b.site;
}
bool cmp1(student a, student b) {
	if (a.score != b.score)	return a.score > b.score;
	else return a.number < b.number;
}
int main() {
	cin >> n >> m;
	int d;
	string s;
	mp['A'] = 0;
	mp['B'] = 1;
	mp['T'] = 2;
	vector<student> stu(n);
	for (int i = 0; i < n; i++) {
		cin >> stu[i].number >> stu[i].score;
		// B123180908127 99
		stu[i].site = stoi(stu[i].number.substr(1, 3));
		Level[mp[stu[i].number[0]]].push_back(stu[i]);
		stu[i].date = stoi(stu[i].number.substr(4, 6));
		Sitenum[stu[i].site].push_back(stu[i]);
		Date[stu[i].date].push_back(stu[i]);
	}
	for (int i = 1; i <= m; i++) {
		int kind;
		char cmd;
		scanf("%d", &kind);
		//1 A
		//2 107
		//Case 1: 1 A
		printf("Case %d: %d ", i, kind);
		if (kind == 1) {
			scanf(" %c", &cmd);
			cout << cmd << '\n';
			if (Level[mp[cmd]].size() == 0) {
				cout << "NA\n";
				continue;
			}
			sort(Level[mp[cmd]].begin(), Level[mp[cmd]].end(), cmp1);
			for (int j = 0; j < Level[mp[cmd]].size(); j++) {
				cout << Level[mp[cmd]][j].number << " " << Level[mp[cmd]][j].score << "\n";
			}
		}
		else if (kind == 2) {
			//2 107
			int site, total = 0;
			cin >> site;
			cout << site << '\n';
			if (Sitenum[site].size() == 0) {
				cout << "NA\n";
				continue;
			}
			for (int j = 0; j < Sitenum[site].size(); j++) {
				total += Sitenum[site][j].score;
			}
			cout << Sitenum[site].size() << " " << total << '\n';
		}
		else {
			//3 180908
			int date;
			cin >> date;
			printf("%06d\n", date);
			//hashTable hash[10010];
			if (Date[date].size() == 0) {
				printf("NA\n");
				continue;
			}
			map<int, int> md;
			vector<hashTable> hash;
			set<int> count;
			for (int j = 0; j < Date[date].size(); j++) {
				//按Sitenum[size].size排序
				int snum = Date[date][j].site;
				md[snum]++;
				count.insert(snum);
				//md[Sitenum[Date[date][j].site].size()] = Date[date][j].site;
			}
			for (auto it = md.begin(); it != md.end(); it++) {
				hashTable temp;
				temp.site = it->first, temp.value = it->second;
				hash.push_back(temp);
			}
			sort(hash.begin(), hash.end(), cmp);
			for (int j = 0; j < count.size(); j++) {
				cout << hash[j].site << " " << hash[j].value << "\n";
			}
		}
	}
	return 0;
}