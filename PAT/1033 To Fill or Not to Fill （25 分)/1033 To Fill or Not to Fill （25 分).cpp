#include <cstdio>
#include <algorithm>
using namespace std;
struct station {
	double price, dis;
}st[510];
const int INF = 1000000;
bool cmp(station a, station b) {
	return a.dis < b.dis;
}
int main() {
	double Cmax, D, Davg;
	int n;
	scanf("%lf%lf%lf%d", &Cmax, &D, &Davg, &n);
	for (int i = 0; i < n; i++) {
		scanf("%lf%lf", &st[i].price, &st[i].dis);
	}
	st[n].price = 0;
	st[n].dis = D;
	sort(st, st + n, cmp);
	if (st[0].dis != 0) {
		printf("The maximum travel distance = 0.00\n");
	}
	else {
		double ans = 0, nowtank = 0, Max = Cmax * Davg;
		int now = 0;
		while (now < n) {
			int k = -1;
			double Minprice = INF;
			for (int i = now + 1; i <= n & (st[i].dis - st[now].dis) <= Max; i++) {
				if (Minprice > st[i].price) {
					Minprice = st[i].price;
					k = i;
					if (Minprice < st[now].price)
						break;
				}
			}
			if (k == -1) break;
			double need = (st[k].dis - st[now].dis) / Davg;
			if (Minprice < st[now].price) {
				if (nowtank < need) {
					ans += (need - nowtank) * st[now].price;
					nowtank = 0;
				}
				else {
					nowtank -= need;
				}
			}
			else {
				ans += (Cmax - nowtank) * st[now].price;
				nowtank = Cmax - need;
			}
			now = k;
		}
		if (now == n) {
			printf("%.2f\n", ans);
		}
		else {
			printf("The maximum travel distance = %.2f\n", st[now].dis + Max);
		}
	}

}