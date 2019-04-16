#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> fac, ans, temp;
int n, k, p, maxfacsum = -1;
int pow(int x) {
	int ans = 1;
	for (int i = 0; i < p; i++) {
		ans *= x;
	}
	return ans;
}
void init() {
	int temp = 0, i = 0;
	while (temp <= n) {
		fac.push_back(temp);
		temp = pow(++i);
	}
}
void DFS(int index, int nowk, int sum, int facsum) {
	if (sum == n && nowk == k) {
		if (facsum > maxfacsum) {
			ans = temp;
			maxfacsum = facsum;
		}
		return;
	}
	if (sum > n || nowk > k)	return;
	if (index - 1 >= 0) {
		temp.push_back(index);
		DFS(index, nowk + 1, sum + fac[index], facsum + index);
		temp.pop_back();
		DFS(index - 1, nowk, sum, facsum);
	}
}
int main() {
	scanf("%d%d%d", &n, &k, &p);
	init();
	DFS(fac.size() - 1, 0, 0, 0);
	if (maxfacsum == -1)	printf("Impossible\n");
	else {
		printf("%d = %d^%d", n, ans[0], p);
		for (int i = 1; i < ans.size(); i++) {
			printf(" + %d^%d", ans[i], p);
		}
	}
}