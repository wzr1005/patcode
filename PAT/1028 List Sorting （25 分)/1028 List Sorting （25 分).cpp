#include <cstdio>	
#include <cstring>
#include <algorithm>
using namespace std;
struct student {
	int id;
	char name[20];
	int grade;
}stu[100010];
int m;
bool cmp1(student a, student b) {
	if (m == 1) return a.id < b.id;
	else if (m == 2) {
		int s = strcmp(a.name, b.name);
		if (s != 0)	return s < 0;
		else return a.id < b.id;
	}
	else if (m == 3) {
		if (a.grade != b.grade)	return a.grade < b.grade;
		else return a.id < b.id;
	}
}
int main() {
	int n;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d%s %d", &stu[i].id, stu[i].name, &stu[i].grade);
		//printf("%d%s %d\n", stu[i].id, stu[i].name, stu[i].grade);
	}
	sort(stu, stu + n, cmp1);
	//printf("haha\n");
	for (int i = 0; i < n; i++) {
		printf("%06d %s %d\n", stu[i].id, stu[i].name, stu[i].grade);
	}
	return 0;
}