#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct person {
	char name[25];
	int age;
	int value;
}p[100010];
bool cmp(person a, person b) {
	if (a.value != b.value)	return a.value > b.value;
	else if (a.age != b.age)	return a.age < b.age;
	else return strcmp(a.name, b.name) < 0;
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s %d%d", p[i].name, &p[i].age, &p[i].value);
	}
	sort(p, p + n, cmp);
	int count, age1, age2;
	for (int i = 1; i <= m; i++) {
		scanf("%d %d %d", &count, &age1, &age2);
		int k = count;
		//printf("count,:%d k:%d\n", count, k);
		printf("Case #%d:\n", i);
		for (int j = 0; j < n; j++) {
			if (count <= 0) break;
			if (p[j].age >= age1 && p[j].age <= age2) {
				count--;
				printf("%s %d %d\n", p[j].name, p[j].age, p[j].value);
			}

		}
		if (k == count)	printf("None\n");
	}
	return 0;
}