#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
struct student {
	int id, rank;
	int total;
	vector<int> score;
	int passnum = 0;
	int isshow = 0;
};
bool cmp(student a, student b) {
	if (a.total != b.total)	return a.total > b.total;
	else if (a.passnum != b.passnum) return a.passnum > b.passnum;
	else if (a.id != b.id)	return a.id < b.id;
}
int main() {
	int n, m, k;
	int id, num, score;
	cin >> n >> k >> m;
	vector<student> v(n + 1);
	for (int i = 1; i <= n; i++) {
		v[i].score.resize(k + 1, -1);
	}
	vector<int> full(k + 1);
	for (int i = 1; i <= k; i++) {
		cin >> full[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> id >> num >> score;
		v[id].id = id;
		v[id].score[num] = max(v[id].score[num], score);
		if (score != -1)	v[id].isshow = 1;
		else if (v[id].score[num] == -1)
			v[id].score[num] = -2;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (v[i].score[j] != -1&&v[i].score[j] != -2) {
				v[i].total += v[i].score[j];
				if (v[i].score[j] == full[j])	v[i].passnum++;
			}
		}
	}
	sort(v.begin() + 1, v.end(), cmp);
	for (int i = 1; i <= n; i++) {
		if (i != 1 && v[i].total == v[i - 1].total) {
			v[i].rank = v[i - 1].rank;
		}
		else
		{
			v[i].rank = i;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (v[i].isshow) {
			printf("%d %05d %d", v[i].rank, v[i].id, v[i].total);
			for (int j = 1; j <= k; j++) {
				if (v[i].score[j] >= 0) {
					printf(" %d", v[i].score[j]);
				}
				else if (v[i].score[j] == -1)	printf(" -");
				else printf(" 0");
			}
			printf("\n");
		}
	}
	return 0;
}