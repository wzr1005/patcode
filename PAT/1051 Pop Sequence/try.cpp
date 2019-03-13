#include <cstdio>
#include <algorithm>
#include <stack>
using namespace std;
int num = 0, n, temp;//记录序列个数
int ans[17];
stack<int> s;
void oper(int p) {
	//可入栈
	if (p < n) {
		s.push(p + 1);
		//printf("%d ", p);
		oper(p + 1);//s[1 2 3 4]
		//恢复数据
		s.pop();
	}
	//可出栈
	if (!s.empty()) {
		int temp = s.top();//取下栈顶
		ans[num++] = temp;//存储栈顶
		s.pop();
		if (s.empty() && p >= n) {//如果栈元素全部转移到ans数组
			//则输出
			for (int i = 0; i < n; i++) {
				printf("%d ", ans[i]);
				//if (i != n - 1)	printf(" ");
			}
			printf("\n");
		}
		oper(p);//p此时是n，回到取下栈顶那里
		//恢复数据
		//printf("temp = %d p = %d", temp, p);
		s.push(temp);
		num--;
	}
}
int main() {
	scanf("%d", &n);
	s.push(1);
	oper(1);
	return 0;
}
