#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
const int M = 26 * 26 * 26 * 10 + 2;
vector<int> selectcourse[M];
int getid(char s[]) {
	int id = 0;
	for (int i = 0; i < 3; i++) {
		id = id * 26 + s[i] - 'A';
	}
	id = id * 10 + s[3] - '0';
	return id;
}
int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	char name[15];
	int course, x;
	for (int i = 0; i < k; i++) {
		scanf("%d%d", &course, &x);
		for (int j = 0; j < x; j++) {
			scanf("%s", name);
			int id = getid(name);
			selectcourse[id].push_back(course);
		}
	}
	for (int i = 0; i < n; i++) {
		scanf("%s", name);
		int id = getid(name);
		sort(selectcourse[id].begin(), selectcourse[id].end());
		printf("%s %d", name, selectcourse[id].size());
		for (int j = 0; j < selectcourse[id].size(); j++) {
			printf(" %d", selectcourse[id][j]);
		}
		printf("\n");
	}
}