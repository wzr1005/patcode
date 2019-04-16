#include <cstdio>
#include <iostream>
#include <string>
#include <set>
#include <map>
using namespace std;
map <string, set<int>> mptitle, mpauthor, mpkey, mppub, mpyear;
void query(map<string, set<int>>& mp, string& str) {
	if (mp.find(str) == mp.end())	printf("Not Found\n");
	else {
		for (auto it = mp[str].begin(); it != mp[str].end(); it++) {
			printf("%07d\n", *it);
		}
	}
}
int main() {
	int n, m, id, cmd;
	string title, author, key, pub, year;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &id);
		char c = getchar();
		getline(cin, title);
		mptitle[title].insert(id);
		getline(cin, author);
		mpauthor[author].insert(id);
		while (cin >> key) {
			mpkey[key].insert(id);
			c = getchar();
			if (c == '\n')	break;
		}
		getline(cin, pub);
		mppub[pub].insert(id);
		getline(cin, year);
		mpyear[year].insert(id);
	}
	string temp;
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d: ", &cmd);
		getline(cin, temp);
		cout << cmd << ": " << temp << endl;
		if (cmd == 1)	query(mptitle, temp);
		else if (cmd == 2) query(mpauthor, temp);
		else if (cmd == 3)	query(mpkey, temp);
		else if (cmd == 4)	query(mppub, temp);
		else query(mpyear, temp);
	}
	return 0;
}