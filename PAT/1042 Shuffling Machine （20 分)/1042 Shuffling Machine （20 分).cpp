#include <cstdio>
#include <cstring>
const int N = 54;
int main() {
	char mp[5] = { 'S', 'H', 'C', 'D', 'J' };
	int start[N + 1], final[N + 1], next[N + 1];
	int k;
	scanf("%d", &k);
	for (int i = 1; i <= N; i++) start[i] = i;
	for (int i = 1; i <= N; i++) scanf("%d", &next[i]);
	for (int step = 0; step < k; step++) {
		for (int i = 1; i <= N; i++) final[next[i]] = start[i];
		for (int i = 1; i <= N; i++) start[i] = final[i];
	}
	for (int i = 1; i <= N; i++) {
		int temp = final[i] - 1;
		printf("%c%d", mp[temp / 13], temp % 13 + 1);
		if (i < N) printf(" ");
	}
	return 0;
}