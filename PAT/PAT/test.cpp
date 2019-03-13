#include <iostream>
#include <map>
using namespace std;
#define ll long long
map<ll, ll> a;
ll gao(ll n) {
	if (n == 1 || n == 0)
		return 1;
	else if (a.find(n) != a.end())
		return a.find(n)->second;
	if ((n & 1) != 0) {
		ll x = gao(n >> 1);
		a[n] = x;
		return x;
	}
	else {
		ll x = gao(n >> 1);
		ll y = gao((n >> 1) - 1);
		a[n] = x + y;
		return x + y;
	}
}

int main()
{
	ll n;
	cin >> n;
	cout << gao(n) << endl;
	return 0;
}
