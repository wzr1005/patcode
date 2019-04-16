#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
string d[13] = { "tret","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec" };
string g[13] = { "", "tam", "hel", "maa","huh", "tou", "kes", "hei", "elo", "syy","lok","mer","jou" };
int main() {
	string mess, messp = "";
	int n;
	scanf("%d", &n);
	getchar();
	while (n--) {
		int temp = 0;
		getline(cin, mess);
		if (mess[0] <= '9'&&mess[0] >= '0') {
			for (int i = 0; i < mess.size(); i++) {
				temp = temp * 10 + mess[i] - '0';
			}
			if (temp > 12) {
				cout << g[temp / 13];
				if (temp % 13 != 0) {
					cout << " " << d[temp % 13];
				}
				printf("\n");
			}


			else
				cout << d[temp % 13] << endl;
		}
		else {
			for (int i = 0; i < mess.size(); i += 4) {
				messp = mess.substr(i, 3);
				for (int j = 0; j < 13; j++) {
					if (messp == g[j]) {
						temp = j * 13;
						break;
					}
					if (messp == d[j]) {
						temp = temp + j;
						break;
					}
				}
			}

			printf("%d\n", temp);
		}

	}
	return 0;
}