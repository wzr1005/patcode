#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int n, sum, a[1005] = { 0 };
	scanf("%d %d", &n, &sum);
	for (int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);
		a[temp]++;
	}
	for (int i = 0; i < sum; i++) {
		if (a[i] && a[sum - i]) {
			if (i == sum - i && a[i] <= 1) {
				continue;
			}

			printf("%d %d\n", i, sum - i);
			return 0;
		}
	}
	cout << "No Solution" << endl;
}