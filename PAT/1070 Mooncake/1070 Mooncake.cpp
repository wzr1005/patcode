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
const int maxn = 1010;

struct mooncake {
	double sale, weight;
	double price;
}cake[maxn];
bool cmp(mooncake a, mooncake b) {
	return a.price > b.price;
}
int main() {
	int n, d, x;
	double price;
	cin >> n >> d;

	for (int i = 0; i < n; i++) {
		cin >> cake[i].weight;
	}
	for (int i = 0; i < n; i++) {
		cin >> cake[i].sale;
		cake[i].price = cake[i].sale / cake[i].weight;
	}
	double ans = 0;
	sort(cake, cake + n, cmp);
	for (int i = 0; i < n&&d; i++) {
		if (d >= cake[i].weight) {
			d -= cake[i].weight;
			ans += cake[i].sale;
		}
		else {
			ans += d * cake[i].price;
			d = 0;
		}
	}
	printf("%.2f", ans);
	return 0;
}