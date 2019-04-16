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
	string ID;
	int Gp, Gm, Gf;
	int G;
};
bool cmp(student a, student b) {
	if (a.G != b.G)	return a.G > b.G;
	else return a.ID < b.ID;
}
map<string, int> idx;
int main() {
	int p, m, n;
	int score, cnt = 1;
	//学生提交的任务数，期中考试的学生数量，期末考试学生的数量
	scanf("%d%d%d", &p, &m, &n);
	vector<student> v, ans;
	string s;//临时输入ID
	for (int i = 0; i < p; i++) {
		cin >> s >> score;//ID Gp得分
		if (score >= 200) {
			v.push_back(student{ s, score, -1, -1, 0 });
			idx[s] = cnt++;//标记学生的顺序
		}
	}
	for (int i = 0; i < m; i++) {
		cin >> s >> score;
		if (idx[s] != 0) {//如果学号存在
			int temp = idx[s] - 1;//因为压入的时候，是从0开始的，所以序号-1
			v[temp].Gm = score;
		}
	}
	for (int i = 0; i < n; i++) {
		cin >> s >> score;
		if (idx[s]) {
			int temp = idx[s] - 1;
			v[temp].Gf = v[temp].G = score;
			if (v[temp].Gm > v[temp].Gf) {
				v[temp].G = (int)(v[temp].Gm * 0.4 + v[temp].Gf * 0.6 + 0.5);//这里保证四舍五入
			}
		}
	}
	for (int i = 0; i < v.size(); i++) {
		if (v[i].G >= 60) ans.push_back(v[i]);
	}
	sort(ans.begin(), ans.end(), cmp);
	for (int i = 0; i < ans.size(); i++) {
		printf("%s %d %d %d %d\n", ans[i].ID.c_str(), ans[i].Gp, ans[i].Gm, ans[i].Gf, ans[i].G);
	}

	return 0;
}