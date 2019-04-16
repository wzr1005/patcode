#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <cstring>
#include <algorithm>
using namespace std;
unordered_map<int, int> arr;
vector<int> v[10000];
struct node {
	int x, y;
};
bool cmp(node a, node b) {
	if (a.x != b.x)	return a.x < b.x;
	else return a.y < b.y;
}
int main() {
	int n, m, k;
	string s1, s2;
	scanf("%d%d", &n, &m);
	//用arr标记两人是否是朋友，用v标记所有人的同性朋友
	for (int i = 0; i < m; i++) {
		cin >> s1 >> s2;
		if (s1.length() == s2.length()) {
			v[abs(stoi(s1))].push_back(abs(stoi(s2)));
			v[abs(stoi(s2))].push_back(abs(stoi(s1)));
		}
		int id1 = abs(stoi(s1)) * 10000 + abs(stoi(s2));
		int id2 = abs(stoi(s2)) * 10000 + abs(stoi(s1));
		arr[id1] = arr[id2] = 1;
	}
	scanf("%d", &k);
	while (k--) {
		int a, b;
		vector<node> ans;
		scanf("%d%d", &a, &b);
		for (int i = 0; i < v[abs(a)].size(); i++) {
			for (int j = 0; j < v[abs(b)].size(); j++) {
				if (v[abs(a)][i] == abs(b) || v[abs(b)][j] == abs(a))	continue;
				//A在寻找同性朋友时，需要避免找到他想要的伴侣B 所以当直接相遇的时候
				//要舍弃该结果
				int id = v[abs(a)][i] * 10000 + v[abs(b)][j];
				if (arr[id]) {
					ans.push_back(node{ v[abs(a)][i], v[abs(b)][j] });
				}
			}
		}
		printf("%d\n", ans.size());
		sort(ans.begin(), ans.end(), cmp);
		for (int i = 0; i < ans.size(); i++) {
			printf("%04d %04d\n", ans[i].x, ans[i].y);
		}
	}
}