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
#include <queue>
using namespace std;
const int maxn = 1010;
struct Node {
	int id, layer;//≤„¥Œ±È¿˙±Í≈‰
};
vector<Node> Follows[maxn];
int n, k;
void BFS(int s) {
	int visit[maxn] = { 0 };
	Node start;
	start.id = s;
	start.layer = 0;
	queue<Node> q;
	q.push(start);
	visit[start.id] = 1;
	int count = 0;
	while (!q.empty()) {
		Node topNode = q.front();
		q.pop();
		int u = topNode.id;
		for (int i = 0; i < Follows[u].size(); i++) {
			Node next = Follows[u][i];
			next.layer = topNode.layer + 1;
			if (visit[next.id] == 0 && next.layer <= k) {
				q.push(next);
				visit[next.id] = 1;
				count++;
			}
		}
	}
	printf("%d\n", count);
}
int main() {
	scanf("%d%d", &n, &k);
	int num;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &num);
		for (int j = 0; j < num; j++) {
			int v;
			scanf("%d", &v);
			Node user;
			user.id = i;
			Follows[v].push_back(user);
		}
	}
	int query, m;
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &query);
		BFS(query);
	}
	return 0;
}