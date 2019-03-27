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
const int maxn = 100010;
using namespace std;
struct student {
	string name;
	int talent, virtue;
	int grade, score;
	student() {
		grade = 110000;
	}
}stu[maxn];
bool cmp(student a, student b) {
	if (a.grade != b.grade)	return a.grade < b.grade;
	else if (a.score != b.score)	return a.score > b.score;
	else if (a.virtue != b.virtue)	return a.virtue > b.virtue;
	else return a.name < b.name;
}
int main() {
	ios::sync_with_stdio(false);
	int n, L, H;
	cin >> n >> L >> H;
	for (int i = 0; i < n; i++) {
		cin >> stu[i].name >> stu[i].virtue >> stu[i].talent;
		if (stu[i].virtue >= H && stu[i].talent >= H) {
			stu[i].grade = 1;
		}
		else if (stu[i].virtue >= H&&stu[i].talent >= L)	stu[i].grade = 2;
		else if (stu[i].virtue >= L && stu[i].talent >= L) {
			if (stu[i].virtue >= stu[i].talent) {
				stu[i].grade = 3;
			}
			else stu[i].grade = 4;
		}
		stu[i].score = stu[i].virtue + stu[i].talent;
	}
	sort(stu, stu + n, cmp);
	int num = 0;
	for (int i = 0; i < n; i++) {
		if (stu[i].grade < 110000) num++;
	}
	cout << num << '\n';
	for (int i = 0; i < num; i++) {
		cout << stu[i].name << " " << stu[i].virtue << " " << stu[i].talent << '\n';
	}
	return 0;
}