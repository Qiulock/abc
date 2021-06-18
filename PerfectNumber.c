#include<stdio.h>
int IsFerfect(int x) {
	int sum = 0,ret = 0;
	if (x == 1) {
		ret = 0;
	}
	else {
		for (int i = 1; i <= (x / 2); i++) {
			if (x % i == 0) {
				sum += i;
			}
		}
		if (sum == x) {
			ret = 1;
		}
	}
	return ret;
}

int main() {
	int start = 0, end = 0,count = 0;
	scanf_s("%d%d", &start, &end);
	for (int i = start; i <= end; i++) {
		if (IsFerfect(i)) {
			if (count == 0) {
				printf("%d", i);
				count++;
			}
			else {
				printf(" %d", i);
				count++;
			}
		}
	}
	if (count == 0) {
		printf("\n");
	}
	return 0;
}