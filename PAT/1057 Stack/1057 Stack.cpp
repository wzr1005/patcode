#include <cstdio>
#include <cstring>
#include <cmath>
#include <stack>
using namespace std;
const int maxn = 100010;
const int sqrN = 316;//把取sqrt(100010) 分成316块
//方便统计数字
int block[sqrN] = { 0 };
int table[maxn] = { 0 };
stack<int> st;
int k;
void Push(int x) {
	st.push(x);
	block[x / sqrN]++;
	table[x]++;
}
void Pop() {
	if (st.empty()) {
		printf("Invalid\n");
		return;
	}
	int x = st.top();
	st.pop();
	block[x / sqrN]--;
	table[x]--;
	printf("%d\n", x);
}
void peekMedian() {
	if (st.empty() == 1) {
		printf("Invalid\n");
	}
	else {
		int idx = 0; 
		int sum = 0;
		while (sum + block[idx] < k) {
			sum += block[idx++];
		}
		int num = idx * sqrN;
		while (sum + table[num] < k) {
			sum += table[num++];
		}
		printf("%d\n", num);
	}
}
int main() {
	int x, query;
	char cmd[15];
	scanf("%d", &query);
	for (int i = 0; i < query; i++) {
		scanf("%s", cmd);
		if (strcmp(cmd, "Push") == 0) {
			scanf("%d", &x);
			Push(x);
		}
		else if (strcmp(cmd, "Pop") == 0) {
			Pop();
		}
		else if (strcmp(cmd, "PeekMedian") == 0) {
			k = st.size();
			if (k % 2 == 1)	k = (k + 1) / 2;
			else k = k / 2;
			peekMedian();
		}
	}
}