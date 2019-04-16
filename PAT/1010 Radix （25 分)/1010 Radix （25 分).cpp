#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
LL map[256];//0~9\a~z与0~35对应
LL INF = (1LL << 63) - 1;
void init() {
	for (char c = '0'; c <= '9'; c++) {
		map[c] = c - '0';
	}
	for (char c = 'a'; c <= 'z'; c++) {
		map[c] = c - 'a' + 10;
	}
}
LL converNum10(char a[], LL radix, LL t) {
	LL ans = 0;
	int len = strlen(a);
	for (int i = 0; i < len; i++) {
		ans = ans * radix + map[a[i]];
		if (ans < 0 || ans > t)	return -1;//溢出或超过N1 的十进制
	}
	return ans;
}
int cmp(char N2[], LL radix, LL t) {
	int len = strlen(N2);
	LL num = converNum10(N2, radix, t);
	if (num < 0)	return 1; //溢出肯定N2 > t
	if (t > num)	return -1;
	if (t == num)	return 0;
	else return 1;
}
LL binarySearch(char N2[], LL left, LL right, LL t) {
	LL mid;
	while (left <= right) {
		mid = (left + right) / 2;
		int flag = cmp(N2, mid, t);
		if (flag == 0)	return mid;
		if (flag == -1) left = mid + 1;
		else right = mid - 1;
	}
	return -1;
}

int findLargestDigit(char N2[]) {//下界
	int ans = -1, len = strlen(N2);
	for (int i = 0; i < len; i++) {
		if (map[N2[i]] > ans) {
			ans = map[N2[i]];
		}
	}
	return ans + 1;
}
char N1[20], N2[20], temp[20];
int tag, radix;
int main() {
	init();
	scanf("%s %s %d %d", N1, N2, &tag, &radix);
	if (tag == 2) {//交换N1N2
		strcpy(temp, N1);
		strcpy(N1, N2);
		strcpy(N2, temp);
	}
	LL t = converNum10(N1, radix, INF);//将N1从radix进制转换成十进制
	LL low = findLargestDigit(N2);
	LL hign = max(low, t) + 1;//上界？
	LL ans = binarySearch(N2, low, hign, t);
	if (ans == -1)	printf("Impossible\n");
	else printf("%lld\n", ans);
	return 0;
}