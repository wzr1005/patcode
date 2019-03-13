#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 10010;
const int INF = 1000000000;
struct Customer {
	int comTime, serveTime;
}newCustom;
bool cmp(Customer a, Customer b) {
	return a.comTime < b.comTime;
}
int convert(int h, int m, int s) {
	return h * 3600 + m * 60 + s;
}
vector<Customer> Custom;
int main() {
	int c, w;
	scanf("%d%d", &c, &w);
	int openTime = convert(8, 0, 0);
	int closeTime = convert(17, 0, 0);
	int WindowSpace[maxn];
	int hh, mm, ss, serveTime, waitingTime = 0;
	for (int i = 0; i < w; i++)	WindowSpace[i] = openTime;//每个窗口刚刚开门等客
	for (int i = 0; i < c; i++) {
		scanf("%d:%d:%d %d", &hh, &mm, &ss, &serveTime);
		int comTime = convert(hh, mm, ss);
		if (comTime > closeTime)	continue;
		if (serveTime > 60)	serveTime = 60;
		newCustom.comTime = comTime;
		newCustom.serveTime = serveTime * 60;
		Custom.push_back(newCustom);
	}
	sort(Custom.begin(), Custom.end(), cmp);
	for (int i = 0; i < Custom.size(); i++) {
		int idx = -1, minEndTime = INF;
		for (int j = 0; j < w; j++) {
			if (WindowSpace[j] < minEndTime) {
				minEndTime = WindowSpace[j];
				idx = j;//idx号窗口空闲，
			}
		}
		if (minEndTime <= Custom[i].comTime) {
			WindowSpace[idx] = Custom[i].comTime + Custom[i].serveTime;
		}
		else {
			waitingTime += WindowSpace[idx] - Custom[i].comTime;
			WindowSpace[idx] += Custom[i].serveTime;
		}
	}
	if (Custom.size() == 0)	printf("0.0");
	else printf("%.1f", waitingTime / 60.0 / Custom.size());
	return 0;
}