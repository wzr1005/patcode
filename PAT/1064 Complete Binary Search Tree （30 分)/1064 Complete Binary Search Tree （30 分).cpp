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
int n, number[maxn], CBT[maxn];
int num = 0;
void inorder(int root) {//中序转成层次遍历
	if (root > n)	return;
	inorder(root * 2);
	CBT[root] = number[num++];
	inorder(root * 2 + 1);
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &number[i]);
	}
	sort(number, number + n);
	inorder(1);
	for (int i = 1; i <= n; i++) {
		printf("%d", CBT[i]);
		if (i < n) printf(" ");
	}
	return 0;
}