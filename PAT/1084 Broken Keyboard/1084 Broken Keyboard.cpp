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
	string a, b, c = "";
	cin >> a >> b;
	int i, j = 0;
	for (i = 0; i < a.size(); ) {
		while (j < b.size()||i < a.size()) {
			if (a[i] == b[j]) {
				i++;
				j++;
			}
			else {
				if (islower(a[i]))
					a[i] -= 32;
				if (c.find(a[i]) == c.npos) {
					c += a[i];
				}
				i++;
				//getchar();
			}
		}
		
	}
	cout << c;
	return 0;
}