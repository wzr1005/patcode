#include <cstdio>
#include <algorithm>
using namespace std;
int orgin[110], tempor[110], changed[110];
int n;
bool issame(int A[], int B[]) {
	for (int i = 0; i < n; i++) {
		if (A[i] != B[i])	return false;
	}
	return true;
}
void print(int A[]) {
	for (int i = 0; i < n; i++) {
		printf("%d", A[i]);
		if (i != n - 1)	printf(" ");
	}
	printf("\n");
}
bool insertSort() {
	bool flag = false;
	for (int i = 1; i < n; i++) {
		if (i != 1 && issame(tempor, changed)) {
			flag = true;//中间步骤与目标相同 且不是初始序列
		}
		//以下为插入排序代码
		int temp = tempor[i], j = i;
		while (j > 0 && tempor[j - 1] > temp) {
			tempor[j] = tempor[j - 1];
			j--;
		}
		tempor[j] = temp;
		if (flag)	return true;//这里刚好多迭代了一轮
	}
	return false;
}
void mergesort() {
	bool flag = false;
	for (int step = 2; step / 2 <= n; step *= 2) {//log2n次
		if (step != 2 && issame(tempor, changed)) {
			flag = true;
		}
		//以下为模拟归并排序
		for (int i = 0; i < n; i += step) {
			sort(tempor + i, tempor + min(i + step, n));
		}
		if (flag == true) {
			print(tempor);
			return;
		}
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &orgin[i]);
		tempor[i] = orgin[i];
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &changed[i]);
	}
	if (insertSort()) {
		printf("Insertion Sort\n");
		print(tempor);
	}
	else {
		printf("Merge Sort\n");
		for (int i = 0; i < n; i++) {
			tempor[i] = orgin[i];
		}
		mergesort();
	}
	return 0;
}