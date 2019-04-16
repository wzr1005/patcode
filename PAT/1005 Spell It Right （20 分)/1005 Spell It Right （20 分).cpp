#include <cstdio>
int main() {
	char c[1110];
	char num[20][16] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
	scanf("%s", c);
	int k = 0, sum = 0;
	while (c[k] != '\0') {
		sum += (c[k] - '0');
		k++;
	}
	if (sum == 0) printf("zero");
	int digit[1010], i = 0;
	//printf("%d", sum);
	while (sum != 0) {
		digit[i++] = sum % 10;
		sum /= 10;
	}
	int j;
	for (j = i - 1; j >= 0; j--) {
		printf("%s", num[digit[j]]);
		if (j != 0) printf(" ");
	}
	return 0;
}
