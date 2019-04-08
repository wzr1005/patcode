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
int main() {
	int n; cin >> n;
	vector<int> v(n + 1);
	for (int i = 1; i <= n; i++)	cin >> v[i];
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			//这里先假设i,j为狼人
			vector<int> lie, a(n + 1, 1);//a的初始值为1
			a[i] = a[j] = -1;//假设i j 是狼人
			for (int k = 1; k <= n; k++) {
				if (v[k] * a[abs(v[k])] < 0) {//abs(v[k])第k个人说的某个人
					//a[abs(v[k])] 第k个人说的这个人的身份
					//v[k]是第k个人说的这个人的身份
					//如果小于0，则这矛盾了，说明第k个人撒谎
					lie.push_back(k);
				}
			}
			//刚好有两个人撒谎 则符合条件
			if (lie.size() == 2&&a[lie[0]] + a[lie[1]] == 0 ) {//?且其中一个狼人说谎
				cout << i << " " << j;
				return 0;
			}
		}
	}
	cout << "No Solution";
	return 0;
}