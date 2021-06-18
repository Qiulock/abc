#include<stdio.h>
#include<math.h>
int main3() {
	int m, n, x, y;
	scanf_s("%d%d", &m, &n);
	if (m > n) {
		x = m;
		y = n;
	}
	else {
		x = n;
		y = m;
	}
	int z = x;
	while (1) {
		if (x % n == 0 && x % m == 0) {
			printf("最小公倍数为:%d\n", x);
			break;
		}
		x++;
	}
	while (1) {
		int tem = 0;
		if (z % y != 0) {
			tem = z;
			z = y;
			y = tem % y;
		}
		else {
			printf("最大公约数为:%d\n", y);
			break;
		}
	}
	return 0;
}

int main5() {
	int a = 2, n = 0, sum = 0;
	scanf_s("%d", &n);
	int i,j;
	for (i = 1; i <= n; i++) {
		int x = 0;
		for (j = 0; j < i; j++) {
			x += a * pow(10, j);
		}
		if (i != n) {
			printf("%d+", x);
		}
		else printf("%d", x);
		sum += x;
	}
	printf("=%d", sum);
	return 0;
}

int main6() {
	int n,sum = 0;
	scanf_s("%d", &n);
	int i,j;
	for (i = 1; i <= n; i++) {
		int x = 1;
		for (j = 1; j <= i; j++) {
			x *= j;
			printf("%d\t%d\t%d\n", i, j, x);
		}
		sum += x;
	}
	printf("%d", sum);
	return 0;
}

int main7() {
	double j, sum = 0;
	int i;
	for (i = 1; i <= 100; i++) {
		sum += i;
	}
	for (i = 1; i <= 50; i++) {
		sum += pow(i, 2);
	}
	for (j = 1.0; j <= 10; j++) {
		double t = 1 / j;
		printf("%lf\n", t);
		sum += t;
	}
	printf("%lf", sum);
	return 0;
}

int main8() {
	int i;
	for (i = 100; i < 999; i++) {
		int x = 0,j = i;
		while (j != 0) {
			x += pow(j % 10,3);
			j /= 10;
		}
		//printf("%d\n", i);
		if (x == i) {
			printf("%d\t", i);
		}
	}
	return 0;
}

int main9() {
	int i,j,sum,count;
	for (i = 2; i < 1000; i++) {
		int a[100] = { 0 };
		sum = 0,count = 0;
		for (j = 1; j < i; j++) {
			if (i % j == 0) {
				sum += j;
				a[count] = j;
				count++;
			}
		}
		if (sum == i) {
			printf("%d its factor are:", i);
			for (j = 0; j < count; j++) {
				printf("%d ", a[j]);
			}
			printf("\n");
		}
	}
	return 0;
}

int main10() {
	double n = 1, m = 2, sum = 0, temp;
	int i = 0;
	for (; i < 20; i++) {
		sum += m / n;
		temp = n;
		n = m;
		m += temp;
	}
	printf("%f", sum);
	return 0;
}

int main() {
	int i, j, k;
	for (i = 1; i < 5; i++) {
		for (j = 1; j < 5; j++) {
			for (k = 1; k < 5; k++) {
				if (i != j && j != k && k != i) {
					printf("%d%d%d\n", i, j, k);
				}
			}
		}
	}
	return 0;
}
