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
using namespace std;
const int maxn = 10009;
int table[maxn] = { 0 };
int m, n, key;
void insert(int key) {
	for (int i = 0; i < m; i++) {//直接二次探测，i以0开始
		int index = (key + i * i) % m;
		if (table[index] == 0) {
			table[index] = 1;
			cout << index % m;
			return;
		}
	}
	cout << '-';
}
int isprime(int n) {
	if (n == 1)	return 0;
	for (int i = 2; i*i <= n; i++) {
		if (n % i == 0)	return 0;
	}
	return 1;
}
int main() {
	cin >> m >> n;
	while (!isprime(m))	m++;
	//cout << m << '\n';
	for (int i = 0; i < n; i++) {
		cin >> key;
		if (i)	cout << ' ';
		insert(key);
	}
	return 0;
}