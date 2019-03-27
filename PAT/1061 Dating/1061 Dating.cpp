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
char week[8][10] = { "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN" };
int main() {
	string s1, s2, s3, s4;
	cin >> s1 >> s2 >> s3 >> s4;
	int i;
	for (i = 0; i < s1.size() && s2.size(); i++) {
		if (s1[i] == s2[i]) {
			if (s1[i] >= 'A'&&s1[i] <= 'G') {
				printf("%s ", week[s1[i] - 'A']);
				i++;
				break;//i
			}
		}
	}
	int hour, minute;
	for (i; i < s1.size(); i++) {
		if (s1[i] == s2[i]) {
			if (s1[i] >= '0'&&s1[i] <= '9') {
				hour = s1[i] - '0';
				break;
			}
			else if (s1[i] >= 'A'&&s1[i] <= 'N') {
				hour = s1[i] - 'A' + 10;
				break;
			}
			
		}
	}
	for (int i = 0; i < s3.size(); i++) {
		if (s3[i] == s4[i] && isalpha(s3[i])) {
			minute = i;
			break;
		}
	}
	printf("%02d:%02d", hour, minute);
	return 0;
}