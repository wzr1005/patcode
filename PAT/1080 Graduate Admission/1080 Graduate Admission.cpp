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
	int GE, GI, id;
	vector<int> app;
	int rank;
	int total = 0;
};
bool cmp(student a, student b) {
	if (a.total != b.total) return a.total > b.total;
	else if (a.GE != b.GE)  return a.GE > b.GE;
	else return a.id > b.id;

}
int main() {
	int n, m, k;
	cin >> n >> m >> k;//总申请数，学校数量，每人志愿数
	vector<int> quota(m);
	vector<student> stu(n);

	for (int i = 0; i < m; i++) {
		cin >> quota[i];
	}
	int GE, GI;
	vector<vector<int>> accept(m);
	for (int i = 0; i < n; i++) {
		cin >> stu[i].GE >> stu[i].GI;
		stu[i].total = (stu[i].GE + stu[i].GI);
		stu[i].id = i;
		for (int j = 0; j < k; j++) {
			int x;
			cin >> x;//志愿
			stu[i].app.push_back(x);
		}
	}
	//根据id找出排序号的代号
	vector<int> hash(n);
	sort(stu.begin(), stu.end(), cmp);
	for (int i = 0; i < n; i++) {
		hash[stu[i].id] = i;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < stu[i].app.size(); j++) {
			int t = stu[i].app[j];//志愿学校
			if (quota[t] > 0) {
				accept[t].push_back(stu[i].id);
				quota[t]--;
				break;
			}
			else if (quota[t] == 0) {
				if (accept[t].size() == 0)  continue;
				int L = accept[t].size() - 1;//如果加权得分和GE成绩都与该学校最后录取的相同
				int lastId = accept[t][L];//上一个被录取的ID
				int r = hash[lastId];

				if (stu[i].total == stu[r].total&&stu[i].GE == stu[r].GE) {
					//这个得到的是学生的id，并不是排名
					accept[t].push_back(stu[i].id);

					break;//这位学生录取了，跳下一位学生 从第一志愿开始
				}
			}
		}
	}
	for (int i = 0; i < m; i++) {
		sort(accept[i].begin(), accept[i].end());
		for (int j = 0; j < accept[i].size(); j++) {
			printf("%d", accept[i][j]);
			if (j != accept[i].size() - 1)  printf(" ");
		}
		printf("\n");
	}
	return 0;
}