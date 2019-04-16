#include <cstdio>
#include <cstring>
int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	int c = a + b, num = 0, s[20] = { 0 };
	if (c == 0)	s[num++] = 0;
	if (c < 0) {
		printf("-");
		c = -c;
	}
	while (c != 0) {
		s[num++] = c % 10;
		c /= 10;
	}
	for (int i = num - 1; i >= 0; i--) {
		printf("%d", s[i]);
		if (i % 3 == 0 && i != 0) printf(",");
	}
	return 0;
}