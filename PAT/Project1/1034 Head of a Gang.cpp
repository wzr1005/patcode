#include <cstdio>
#include <map>
#include <string>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int maxn = 2010;
map<string, int> stringToint, Gang;
map<int, string> intTostring;
int n, k, numperson = 0;
int G[maxn][maxn] = { 0 }, weight[maxn] = { 0 }, visit[maxn] = { 0 };
int change(string str) {
	if (stringToint.find(str) != stringToint.end()) {
		return stringToint[str];
	}
	else {
		stringToint[str] = numperson;
		intTostring[numperson] = str;
		return numperson++;
	}

}
void DFS(int nowvisit, int& head, int& numMember, int& totalvalue) {
	visit[nowvisit] = 1;
	numMember++;
	if (weight[head] < weight[nowvisit]) {
		head = nowvisit;
	}
	for (int i = 0; i < numperson; i++) {
		if (G[nowvisit][i] > 0) {
			totalvalue += G[nowvisit][i];
			G[nowvisit][i] = G[i][nowvisit] = 0;
			if (visit[i] == 0) {
				DFS(i, head, numMember, totalvalue);
			}
		}
	}
}
void DFStrave() {
	for (int i = 0; i < numperson; i++) {
		if (visit[i] == 0) {
			int head = i, numMember = 0, totalvalue = 0;
			DFS(i, head, numMember, totalvalue);
			if (numMember > 2 && totalvalue > k) {
				Gang[intTostring[head]] = numMember;
			}
		}

	}
}
int main() {
	scanf("%d%d", &n, &k);
	int w;
	string str1, str2;
	for (int i = 0; i < n; i++){
		cin >> str1 >> str2 >> w;
		int id1 = change(str1);
		int id2 = change(str2);
		weight[id1] += w;
		weight[id2] += w;
		G[id1][id2] += w;
		G[id2][id1] += w;
	}
	DFStrave();
	printf("%d\n", Gang.size());
	for (auto i = Gang.begin(); i != Gang.end(); i++) {
		cout << i->first << " " << i->second << endl;
	}
}