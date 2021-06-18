#include<stdio.h>
int main() {
	int power[100] = { 0 };
	int isfinish = 0,power0 = 0;
	while (isfinish != 2) {
		int i = 0, j = 0;
		scanf_s("%d%d",&i,&j);
		if (i == 0) {
			power0 += j;
			isfinish++;
		}
		else {
			power[i - 1] += j;
		}
	}
	for (int i = 99; i >= 0; i--) {
		if (power[i] != 0 && i != 1) {
			printf("%dx%d+", power[i], i + 1);
		}
		else if (power[i] != 0 && i == 1) {
			printf("%dx+", power[i]);
		}
	}
	printf("%d", power0);
	return 0;
}