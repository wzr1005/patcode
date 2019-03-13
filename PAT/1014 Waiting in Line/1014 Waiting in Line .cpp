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
#include <queue>
#include <ctype.h>
using namespace std;
const int maxn = 1010;
int Time[maxn], WindowSpace[maxn];
int n, m, k, query, q;
int convertToMinute(int h, int m) {
	return h * 60 + m;
}
struct Window {
	int endTime, popTime;
	queue<int> q;
}w[25];
int ans[maxn], needTime[maxn];//服务结束时间和服务需要时间
int main() {
	int index = 0;
	scanf("%d%d%d%d", &n, &m, &k, &query);
	for (int i = 0; i < k; i++) {
		scanf("%d", &needTime[i]);
	}
	for (int i = 0; i < n; i++) {

	}
}