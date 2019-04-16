#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn = 1010;
int n, m, k, query, q;
int needTime[maxn], ans[maxn];
struct Window {
	int endTime, popTime;
	queue<int> q;
}w[25];
int convertToMinute(int h, int m) {
	return h * 60 + m;
}
int main() {
	scanf("%d%d%d%d", &n, &m, &k, &query);
	for (int i = 0; i < k; i++) {
		scanf("%d", &needTime[i]);
	}
	for (int i = 0; i < n; i++) {
		w[i].endTime = w[i].popTime = convertToMinute(8, 0);
	}
	int inIndex = 0;
	for (int i = 0; i < min(n * m, k); i++) {
		w[inIndex % n].q.push(inIndex);
		w[inIndex % n].endTime += needTime[inIndex];
		if (inIndex < n)	w[inIndex].popTime = needTime[inIndex];
		ans[inIndex] = w[inIndex % n].endTime;
		inIndex++;
	}
	for (; inIndex < k; inIndex++) {
		int idx = -1, minPopTime = 1 << 30;
		for (int i = 0; i < n; i++) {
			if (minPopTime > w[i].popTime) {
				idx = i;
				minPopTime = w[i].popTime;
			}
		}
		Window& W = w[idx];
		W.q.pop();
		W.q.push(inIndex);
		W.endTime += needTime[inIndex];
		W.popTime += needTime[W.q.front()];
		ans[inIndex] = W.endTime;//新加入的inIndex排在窗口最后一位
	}
	for (int i = 0; i < query; i++) {
		scanf("%d", &q);
		if (ans[q - 1] - needTime[q - 1] >= convertToMinute(17, 0)) {
			printf("Sorry\n");
		}
		else printf("%02d:%02d\n", ans[q - 1] / 60, ans[q - 1] % 60);
	}
	return 0;
}