#include <cstdio>
#include <cmath>
using namespace std;
struct person {
	char name[200];
	char sex;
	char id[20];
	int score;										//3
}M_min, F_max, temp;								//Joe M Math990112 89
int main() {										//Mike M CS991301 100
	int n, flagm = 0, flagf = 0;					//Mary F EE990830 95
	scanf("%d", &n);
	M_min.score = 101, F_max.score = -1;
	while (n--) {
		getchar();
		scanf("%s %c %s %d", temp.name, &temp.sex, temp.id, &temp.score);
		if (temp.sex == 'M') {
			flagm = 1;
			//printf("%s %c\n", temp.name, temp.sex);
			if (M_min.score > temp.score)	M_min = temp;
		}
		else if (temp.sex == 'F') {
			flagf = 1;
			//printf("%s %c\n", temp.name, temp.sex);
			if (F_max.score < temp.score) F_max = temp;
		}
	}
	if (flagf)	printf("%s %s\n", F_max.name, F_max.id);
	else printf("Absent\n");
	if (flagm)	printf("%s %s\n", M_min.name, M_min.id);
	else printf("Absent\n");
	if (flagm&&flagf)	printf("%d\n", F_max.score - M_min.score);
	else printf("NA\n");
	return 0;
}