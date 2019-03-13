#include <cstdio>
#include <stack>
#include <algorithm>
using namespace std;
int num = 0, n, Array[17];
stack<int> s;
void printstack(int p) {
	if (p < n) {
		s.push(p + 1);
		printstack(p + 1);
		//恢复完数据之后 弹出
		//**弹出3的时候，p是等于2的，
		s.pop();//弹出之后在下面的if里面转移到Array中
	}
	if (!s.empty()) {
		int temp = s.top();
		Array[num++] = temp;
		s.pop();
		if (s.empty() && p >= n) {
			for (int i = 0; i < n; i++) {
				printf("%d ", Array[i]);
			}
			printf("\n");
		}
		printstack(p);//第一种情况就不说了，第二种情况当转移完了之后
		//s为空，
		//栈内元素全部转移到Array数组，
		//push恢复数据
		s.push(temp);
		num--;
	}
}
int main() {
	scanf("%d", &n);
	s.push(1);
	printstack(1);
	return 0;
}