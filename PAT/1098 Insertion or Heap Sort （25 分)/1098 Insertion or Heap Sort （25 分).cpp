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
const int N = 110;
int origin[N], tempOri[N], changed[N];
int n;
int isSame(int a[], int b[]) {
	for (int i = 1; i <= n; i++) {
		if (a[i] != b[i])	return 0;
	}
	return 1;
}
void printArray(int a[]) {
	for (int i = 1; i <= n; i++) {
		printf("%d", a[i]);
		if (i != n)	printf(" ");
	}
}
int insertSort() {
	int flag = 0;
	for (int i = 2; i <= n; i++) {
		//n-1次
		if (i != 2 && isSame(tempOri, changed)) {
			flag = 1;
		}
		sort(tempOri + 1, tempOri + i + 1);
		if (flag)	return 1;
	}
	return 0;
}
void downAdjust(int low, int high) {
	int i = low, j = i * 2;
	while (j <= high) {
		if (j + 1 <= high && tempOri[j + 1] > tempOri[j]) {
			j++;
		}
		if (tempOri[i] < tempOri[j]) {
			swap(tempOri[i], tempOri[j]);
			i = j;
			j = i * 2;
		}
		else break;
	}
}
void heap() {
	int flag = 0;
	for (int i = n / 2; i >= 1; i--) {
		downAdjust(i, n);
	}
	for (int i = n; i >= 1; i--) {
		if (i != n && isSame(tempOri, changed)) {
			flag = 1;
		}
		swap(tempOri[1], tempOri[i]);
		downAdjust(1, i - 1);
		if (flag) {
			printArray(tempOri);
			break;
		}
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		//考虑堆排序的结构特性
		scanf("%d", &origin[i]);
		tempOri[i] = origin[i];
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &changed[i]);
	}
	if (insertSort()) {
		printf("Insertion Sort\n");
		printArray(tempOri);
	}
	else {
		printf("Heap Sort\n");
		for (int i = 1; i <= n; i++) {
			tempOri[i] = origin[i];
		}
		heap();
	}
	return 0;
}