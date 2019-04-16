#include <cstdio>
#include <queue>
using namespace std;
const int maxn = 1010;
queue<int> q;
struct mouse {
	int weight, R;
}mouse[maxn];
int main() {
	int np, ng;
	scanf("%d%d", &np, &ng);
	for (int i = 0; i < np; i++) {
		scanf("%d", &mouse[i].weight);
	}
	int order;
	for (int i = 0; i < np; i++) {
		scanf("%d", &order);
		q.push(order);
	}
	int temp = np, group;
	while (q.size() != 1) {
		if (temp % ng == 0)	group = temp / ng;
		else group = temp / ng + 1;
		for (int i = 0; i < group; i++) {
			int k = q.front();
			for (int j = 0; j < ng; j++) {
				if (i * ng + j >= temp) {
					break;
				}
				int front = q.front();//这里有可能会越界,发生错误,所以要放在下面,
				if (mouse[front].weight > mouse[k].weight) {
					k = front;
				}
				mouse[front].R = group + 1;
				q.pop();
			}
			q.push(k);
		}
		//一轮比赛结束
		temp = group;//队列内留下group个
	}
	mouse[q.front()].R = 1;
	for (int i = 0; i < np; i++) {
		printf("%d", mouse[i].R);
		if (i != np - 1)	printf(" ");
	}
	return 0;
}
