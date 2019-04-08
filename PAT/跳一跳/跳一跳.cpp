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
	int x, flag = 0;
	int sum = 0;
	while (~scanf("%d", &x)) {
		if (x == 0)	break;
		if (x == 1) {
			sum++;
			flag = 0;
		}
		else if (x == 2) {
			if (flag) {
				x += flag * 2;
				flag++;
				sum += x;
			}
			else {
				flag = 1;
				sum += 2;
			}
		}
	}
	printf("%d", sum);
	return 0;
}