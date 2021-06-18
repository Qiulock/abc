#include <stdio.h>
#include <string.h>

int main() {
	int isnew = 0,count = 0;
	char str[81];
	gets_s(str,81);
	char c = str[0];
	for (int i = 1; c != '/0'; i++) {
		if (c == ' ') {
			isnew = 0;
		}
		else if (isnew == 0) {
			count++;
		}
		c = str[i];
		printf("%c\t", c);
	}
	printf("%d", count);
	return 0;
}