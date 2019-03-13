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
#include <ctype.h>
#include <stack>
using namespace std;
const int maxn = 1010;
int arr[maxn];
stack<int> st;
int main() {
	int m, n, T;
	scanf("%d%d%d", &m, &n, &T);
	while (T--) {
		while (!st.empty()) {
			st.pop();
		}
		for (int i = 1; i <= n; i++) {
			scanf("%d", &arr[i]);
		}
		int current = 1;
		int flag = 1;
		for (int i = 1; i <= n; i++) {
			st.push(i);
			if (st.size() > m) {//如果此时栈中元素个数容量m 则序列非法
				flag = 0;
				break;
			}
			while (!st.empty() && st.top() == arr[current]) {
				st.pop();
				current++;//如果相同，则反复弹栈并令current++
			}
		}
		if (st.empty() && flag) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
	return 0;
}