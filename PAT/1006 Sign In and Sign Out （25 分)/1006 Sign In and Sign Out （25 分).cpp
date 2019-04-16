#include <cstdio>
#include <cstring>
struct student {
	char name[20];
	int hh, mm, ss;
}early, last, temp;
bool earlyequ(student a, student b) {//如果a日期比他早返回1
	if (a.hh != b.hh)	return a.hh < b.hh;
	else if (a.mm != b.mm)	return a.mm < b.mm;
	else if (a.ss != b.ss)	return a.ss < b.ss;
}bool lastequ(student a, student b) {//如果a日期比他晚返回1
	if (a.hh != b.hh)	return a.hh > b.hh;
	else if (a.mm != b.mm)	return a.mm > b.mm;
	else if (a.ss != b.ss)	return a.ss > b.ss;
}
int main() {
	int hh, mm, ss;
	int n;
	scanf("%d", &n);
	early.hh = 24, early.mm = 60, early.ss = 60;
	last.hh = 0, last.mm = 0, last.ss = 0;
	while (n--) {
		getchar();
		scanf("%s %d:%d:%d", temp.name, &temp.hh, &temp.mm, &temp.ss);
		if (earlyequ(temp, early))	early = temp;
		scanf("%d:%d:%d", &temp.hh, &temp.mm, &temp.ss);
		if ((lastequ(temp, last)))	last = temp;
	}
	printf("%s %s", early.name, last.name);
	return 0;
}