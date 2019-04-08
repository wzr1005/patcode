#include <cstdio>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;
int Msize, n, m;
int isPrime(int n) {
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0)	return 0;
	}
	return 1;
}
int main() {
	cin >> Msize >> n >> m;
	while (!isPrime(Msize))	Msize++;
	vector<int> v(Msize);
	for (int i = 0; i < n; i++) {
		int x;
		int flag = 0;
		scanf("%d", &x);
		for (int j = 0; j < Msize; j++) {
			int pos = (x + j * j) % Msize;
			if (v[pos] == 0) {
				v[pos] = x;
				flag = 1;
				break;
			}
		}
		if (!flag) printf("%d cannot be inserted.\n", x);
	}
	int ans = 0, x;
	for (int i = 0; i < m; i++) {
		scanf("%d", &x);
		for (int j = 0; j <= Msize; j++) {
			ans++;
			int pos = (x + j * j) % Msize;
			if (v[pos] == x || v[pos] == 0) {
				break;
			}
		}
	}
	printf("%.1lf", ans * 1.0 / m);
}