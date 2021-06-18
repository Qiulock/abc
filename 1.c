#include<stdio.h>

int main2() {
	char ch;
	scanf_s("%c", &ch);
	printf("%d", ch);
	return 0;
}

int main3() {
	char ch;
	scanf_s("%c", &ch);
	ch -= 32;
	printf("%c\t%d\t0x%x", ch, ch, ch);
	return 0;
}

int main4() {
	int a,b;
	float he, cha, ji, chu;
	scanf_s("%d%d", &a, &b);
	he = a + b;
	cha = a - b;
	ji = a * b;
	chu = a / b;
	printf("%.2f\t%.2f\t%.2f\t%.2f", he,cha,ji,chu);
	return 0;
}

int main() {
	int r, h;
	scanf_s("%d%d", &r, &h);
	printf("Ô²ÖùÌå=%.2f\tÔ²×¶Ìå=%.2f", r * r * h * 3.14, r * r * h * 3.14 / 3);
	return 0;
}