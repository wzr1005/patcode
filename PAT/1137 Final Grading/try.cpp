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
	int Gp, Gm, Gf, G;
};
map<string, int> idx;
bool cmp(student a, student b) {
	if (a.G != b.G)	return a.G > b.G;
	else return a.ID < b.ID;
}
int main() {
	int p, m, n;
	int score, cnt = 1;
	string s;
	vector<student> v, ans;
	scanf("%d%d%d", &p, &m, &n);
	for (int i = 0; i < p; i++) {
		cin >> s >> score;
		if (score >= 200) {
			v.push_back(student{ s, score, -1, -1, 0 });
			idx[s] = cnt++;
		}
		
	}
	for (int i = 0; i < m; i++) {
		cin >> s >> score;
		if (idx[s] != 0) {
			int temp = idx[s] - 1;
			v[temp].Gm = score;

		}
	}
	for (int i = 0; i < n; i++) {
		cin >> s >> score;
		if (idx[s] != 0) {
			int temp = idx[s] - 1;
			v[temp].Gf = v[temp].G = score;
			if (v[temp].Gf < v[temp].Gm) {
				v[temp].G = (int)(v[temp].Gm * 0.4 + v[temp].Gf * 0.6 + 0.5);
			}
			if (v[temp].G >= 60)	ans.push_back(v[temp]);
			//’‚æ‰¬‰¡À
		}
	}
	sort(ans.begin(), ans.end(), cmp);
	for (int i = 0; i < ans.size(); i++) {
		printf("%s %d %d %d %d\n", ans[i].ID.c_str(), ans[i].Gp, ans[i].Gm, ans[i].Gf, ans[i].G);
	}
	return 0;
}