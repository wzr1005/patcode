#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
int main() {
	int hash[128];
	string str1, str2;
	getline(cin, str1);
	getline(cin, str2);
	memset(hash, 0, sizeof(hash));
	for (int i = 0; i < str2.size(); i++) {
		hash[str2[i]] = 1;
	}
	for (int i = 0; i < str1.size(); i++) {
		if (hash[str1[i]] == 0) {
			printf("%c", str1[i]);
		}
	}
}