#include <stdio.h>
int main() {
	int number[100][100] = { {0} ,{0} };
	int x = 0 ,count = 0;
	scanf_s("%d", &x);
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < x; j++) {
			scanf_s("%d", &number[i][j]);
		}
	}
	for (int i = 0; i < x; i++) {
		int max = 0;
		for (int j = 0; j < x; j++) {
			if (max < number[i][j]) {
				max = number[i][j];
			}
		}
		for (int j = 0; j < x; j++) {
			if (max == number[i][j]) {
				int ismin = 1;
				for (int k = 0; k < x; k++) {
					if (number[i][j] > number[k][j]) {
						ismin = 0;
						break;
					}
				}
				if (ismin) {
					printf("%d %d\n", i, j);
					count++;
				}
			}
		}
	}
	if (count == 0) {
		printf("NO");
	}
	return 0;
}