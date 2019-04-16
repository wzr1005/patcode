#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct student {
	char id[20];
	int score;
	int location_number;//考场号
	int local_rank;//考场内排名
	int final_rank;
}stu[31000];
bool cmp(student a, student b) {
	if (a.score != b.score)	return a.score > b.score;
	else return strcmp(a.id, b.id) < 0;
}
int main() {
	int n, num = 0;//考生人总数
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int k; scanf("%d", &k);
		for (int j = 0; j < k; j++) {
			scanf("%s%d", &stu[num].id, &stu[num].score);
			stu[num++].location_number = i;
		}
		//考场内排序
		sort(stu + num - k, stu + num, cmp);
		stu[num - k].local_rank = 1;
		for (int j = num - k + 1; j < num; j++) {
			if (stu[j].score == stu[j - 1].score)	stu[j].local_rank = stu[j - 1].local_rank;
			else stu[j].local_rank = j + 1 - (num - k);
		}
	}
	printf("%d\n", num);
	sort(stu, stu + num, cmp);
	stu[0].final_rank = 1;
	for (int i = 1; i < num; i++) {
		if (stu[i].score == stu[i - 1].score) stu[i].final_rank = stu[i - 1].final_rank;
		else stu[i].final_rank = i + 1;
	}
	for (int i = 0; i < num; i++) {
		printf("%s %d %d %d\n", stu[i].id, stu[i].final_rank, stu[i].location_number, stu[i].local_rank);
	}
	return 0;
}
