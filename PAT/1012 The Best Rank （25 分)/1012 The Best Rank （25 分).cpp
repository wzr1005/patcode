#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
struct student {
	int id;
	int grade[4];
}stu[2010];
int now;
int Rank[1000010][4] = { 0 };
char course[4] = { 'A', 'C', 'M', 'E' };
bool cmp(student a, student b) {
	return a.grade[now] > b.grade[now];
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d%d", &stu[i].id, &stu[i].grade[1], &stu[i].grade[2], &stu[i].grade[3]);
		stu[i].grade[0] = round((stu[i].grade[1] + stu[i].grade[2] + stu[i].grade[3]) / 3.0);
	}
	for (now = 0; now < 4; now++) {
		sort(stu, stu + n, cmp);
		Rank[stu[0].id][now] = 1;
		for (int i = 1; i < n; i++) {
			if (stu[i].grade[now] == stu[i - 1].grade[now])
				Rank[stu[i].id][now] = Rank[stu[i - 1].id][now];
			else Rank[stu[i].id][now] = i + 1;
		}
	}//每一门排好了序，存储在Rank数组中 0 1 2 3
	//接下来查找
	int query;
	for (int i = 0; i < m; i++) {
		scanf("%d", &query);
		int k = 0;
		if (Rank[query][0] == 0) printf("N/A\n");
		else {
			for (int j = 1; j < 4; j++) {
				if (Rank[query][k] > Rank[query][j]) k = j;
			}
			printf("%d %c\n", Rank[query][k], course[k]);
		}
	}
	return 0;
}