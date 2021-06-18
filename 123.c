#include<stdio.h>

int main() {
	int n[4] = { 0 },i = 0;
	for (i = 0; i < 4; i++) {
		scanf_s("%d", &n[i]);
	}
	for (i = 0; i < 4; i++) {
		int j = i+1;
		for (; j < 4; j++) {
			if (n[i] > n[j]) {
				int t = n[i];
				n[i] = n[j];
				n[j] = t;
			}
		}
	}
	for (i = 0; i < 4; i++) {
		printf("%d ",n[i]);
	}
	return 0;
}