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
struct school {
	string name;
	int Ns;
	int total = 0;
}temp;
struct 
vector<school> Sch;
string change(string str) {
	for (int i = 0; i < str.size(); i++) {
		if (str[i] >= 'A'&&str[i] <= 'Z') {
			str[i] += 32;
		}
	}
	return str;
}
bool cmp(school a, school b) {
	if (a.total != b.total)	return a.total > b.total;
	else if (a.Ns != b.Ns)	return a.Ns < b.Ns;
	else return a.name < b.name;
}
map<string, double> mp;
map<char, double> w;//分数权重
map<string, int> stunum;//每个学校对应的学生数量
int main() {
	int n;
	scanf("%d", &n);
	w['A'] = 1;
	w['T'] = 1.5;
	w['B'] = 1 / 1.5;
	for (int i = 0; i < n; i++) {
		string Id, name; int score;
		cin >> Id >> score >> name;
		name = change(name);
		mp[name] += score * w[Id[0]];//学校总分统计
		stunum[name]++;//学校参赛人数统计
	}
	printf("%d\n", stunum.size());
	auto it1 = stunum.begin();
	//把学校对应的分数、人数存储起来，并排序
	for (auto it = mp.begin(); it != mp.end(); it++) {
		temp.name = it->first;
		temp.Ns = it1->second;
		temp.total = (int)it->second;
		it1++;
		Sch.push_back(temp);//将每个学校的信息压入Sch
	}
	sort(Sch.begin(), Sch.end(), cmp);
	//按照题目要求打印
	int r = 1;
	cout << r<<" " << Sch[0].name << " " << Sch[0].total << " " << Sch[0].Ns << '\n';
	for (int i = 1; i < Sch.size(); i++) {
		if (Sch[i].total != Sch[i - 1].total) {
			r = i + 1;
		}
		cout <<r<< " " << Sch[i].name << " " << Sch[i].total << " " << Sch[i].Ns << '\n';
	}
	return 0;
}