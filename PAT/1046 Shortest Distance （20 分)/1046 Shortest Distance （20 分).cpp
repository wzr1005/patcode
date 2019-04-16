#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100010;
int main() {
	int n, sum = 0;
	scanf("%d", &n);
	int A[maxn], dis[maxn] = { 0 };
	for (int i = 1; i <= n; i++) {
		scanf("%d", &A[i]);
		sum += A[i];
		dis[i] = sum;
	}
	int query;
	scanf("%d", &query);
	int left, right;
	for (int i = 0; i < query; i++) {
		scanf("%d%d", &left, &right);
		if (left > right) swap(left, right);
		int temp = dis[right - 1] - dis[left - 1];
		printf("%d\n", min(temp, sum - temp));
	}
	return 0;
}