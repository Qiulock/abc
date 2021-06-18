#include<stdio.h>
int main() {
	int x = 0,y = 0;
	scanf_s("%d", &x);
	for (int i = 1; i <= 3; i++) {
		y *= 10;
		y += x % 10;
		x /= 10;
	}
	printf("%d", y);
	return 0;
}