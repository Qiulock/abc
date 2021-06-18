#include<stdio.h>

int main() {
	int x = 0;
	scanf_s("%d", &x);
	if (x < -8) {
		printf("%d", 2 * x * x - 1);
	}
	else if (x > -8 && x < 8) {
		if (x < 0) printf("%d", 0 - x);
		else printf("%d", x);
	}
	else if (x > 8) {
		printf("%d", 3 * x * x * x + 10);
	}
	return 0;
}