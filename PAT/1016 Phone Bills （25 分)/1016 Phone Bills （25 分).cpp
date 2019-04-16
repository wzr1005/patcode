
#include <cstdio>
#include <cstring>	
#include <algorithm>
using namespace std;
struct subscribe {
	char id[30];
	int mm, dd, hh, min;
	int flag;
}sub[1010], temp;
bool cmp(subscribe a, subscribe b) {
	int k = strcmp(a.id, b.id);
	if (k != 0) return k < 0;
	else if (a.mm != b.mm) return a.mm < b.mm;
	else if (a.dd != b.dd)	return a.dd < b.dd;
	else if (a.hh != b.hh)	return a.hh < b.hh;
	else return a.min < b.min;
}
int rate[25];
void gets_ans(int on, int off, int &time, int &money) {
	temp = sub[on];
	while (temp.dd < sub[off].dd || temp.hh < sub[off].hh || temp.min < sub[off].min) {
		time++;
		money += rate[temp.hh];
		temp.min++;
		if (temp.min >= 60) {
			temp.min = 0;
			temp.hh++;
		}
		if (temp.hh >= 24) {
			temp.hh = 0;
			temp.dd++;
		}
	}
}
int main() {
	for (int i = 0; i < 24; i++) {
		scanf("%d", &rate[i]);
	}
	int n;
	char s[15];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s %d:%d:%d:%d %s", sub[i].id, &sub[i].mm, &sub[i].dd, &sub[i].hh, &sub[i].min, s);
		if (strcmp(s, "on-line") == 0) sub[i].flag = 1;
		else sub[i].flag = 0;
	}
	sort(sub, sub + n, cmp);
	//代码的关键部分
	int on = 0, off, next;
	while (on < n) {
		int needprint = 0;
		next = on;
		//开始跟next跟踪下一个用户的第一个
		while (next < n&&strcmp(sub[on].id, sub[next].id) == 0) {
			if (needprint == 0 && sub[next].flag == 1)
				needprint = 1;
			else if (needprint == 1 && sub[next].flag == 0) {
				needprint = 2;//?如果连续的online呢？
			}
			next++;
		}
		if (needprint < 2) {
			on = next;//无需打印
			continue;
		}
		int allpay = 0;
		printf("%s %02d\n", sub[on].id, sub[on].mm);
		while (on < next) {
			while (on < next - 1 && !(sub[on].flag == 1 && sub[on + 1].flag == 0))
				on++;
			off = on + 1;
			if (off == next) {
				on = next;
				break;
			}
			printf("%02d:%02d:%02d ", sub[on].dd, sub[on].hh, sub[on].min);
			printf("%02d:%02d:%02d ", sub[off].dd, sub[off].hh, sub[off].min);
			int money = 0, time = 0;
			gets_ans(on, off, time, money);//得到time和money
			allpay += money;
			printf("%d $%.2f\n", time, money / 100.0);
			on = off + 1;
		}
		printf("Total amount: $%.2f\n", allpay / 100.0);

	}
	return 0;
}