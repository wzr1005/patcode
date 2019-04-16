#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int pos[100010];
int main() {
	int n, ans = 0;
	scanf("%d", &n);
	int left = n - 1, num;
	for (int i = 0; i < n; i++) {
		scanf("%d", &num);
		pos[num] = i;//表示某某数 在第几个位置
		if (num == i && num != 0)
			left--;
	}
	int k = 1;
	while (left > 0) {//只要还有数不在本位上
		if (pos[0] == 0) {
			while (k < n) {
				if (pos[k] != k) {
					swap(pos[0], pos[k]);//0所在的位置与k所在的位置交换
					ans++;
					break;
				}
				k++;
			}
		}
		while (pos[0] != 0) {
			swap(pos[0], pos[pos[0]]);//0的位置是7， 而7的位置是2，交换一下， 0的位置是2， 7的位置是7
			ans++;
			left--;//7回到了自己的位置上
		}
	}
	printf("%d\n", ans);
}