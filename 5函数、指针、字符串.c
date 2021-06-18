#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include <cassert>

//̷��ǿ 6.0 ��ŵ��
void move(char x, char y) {
	printf("%c -> %c\n", x, y);
}
void hanoi(int n, char one, char two, char three) {
	if (n == 1) {
		move(one, three);
	}
	else {
		hanoi(n - 1, one, three, two);
		move(one, three);
		hanoi(n - 1, two, one, three);
	}
}
int main0() {
	int m;
	scanf_s("%d", &m);
	hanoi(m, 'A', 'B', 'C');
	return 0;
}

//������ 7.5 �ݹ������Լ��
int fun(int x, int y) {
	if (x <= 0 || y <= 0) {
		printf("����������");
	}
	if (x % y == 0) {
		return y;
	}
	else {
		return fun(y, x % y);
	}
}
int main5() {
	int x,y;
	scanf_s("%d%d", &x,&y);
	if (x < y) {
		int temp = x;
		x = y;
		y = temp;
	}
	printf("%d��%d�����Լ��Ϊ%d", x, y, fun(x, y));
	return 0;
}

//������ 7.6 ����n*n�ľ����ú�����̼��㲢����������Խ����ϵĸ�Ԫ��֮��
int fun1(int a[3][3]) {
	int i, sum = 0;
	for (i = 0; i < 3; i++) {
		sum += a[i][i];
	}
	for (i = 0; i < 3; i++) {
		sum += a[i][2 - i];
	}
	return sum;
}
int main8() {
	int a[3][3];
	int i, j;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			scanf_s("%d", &a[i][j]);
		}
	}
	printf("%d", fun1(a));
	return 0;
}

//������ 7.7 ����10����������������С�������һ�����Ի����������������һ�����Ի�
void fun2(int* p) {
	int i;
	for (i = 0; i < 10; i++) {
		scanf_s("%d", &p[i]);
	}
}
void fun3(int* p) {
	int i;
	int max = -32768, maxloc = 0, min = 32767, minloc = 0;
	for (i = 0; i < 10; i++) {
		if (max < p[i]) {
			max = p[i];
			maxloc = i;
		}
	}
	for (i = 0; i < 10; i++) {
		if (min > p[i]) {
			min = p[i];
			minloc = i;
		}
	}
	int temp = p[9];
	p[9] = max;
	p[maxloc] = temp;
	temp = p[0];
	p[0] = min;
	p[minloc] = temp;
}
void fun4(int* p) {
	int i;
	for (i = 0; i < 10; i++) {
		printf("%d ", p[i]);
	}
}
int main7() {
	int array[10];
	fun2(array);
	fun3(array);
	fun4(array);
	return 0;
}

//������ 7.9 ��4��4�еĶ�ά�������ҳ���С���������ڵ��к��У������估�����ڵ�����ֵ��ӡ����
void fun5(int(*p)[4]) {
	int i, j;
	printf("������һ��4��4�еĶ�ά����\n");
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			scanf_s("%d", &p[i][j]);
		}
	}
}
void fun6(int (*p)[4],int* pdata) {
	int i, j,min,x,y;
	min = p[0][0];
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			if (min > p[i][j]) {
				min = p[i][j];
				x = i;
				y = j;
			}
		}
	}
	pdata[0] = min;
	pdata[1] = x;
	pdata[2] = y;
}
void fun7(int* p) {
	printf("min[%d][%d] = %d\n", p[1], p[2], p[0]);
}
int main9() {
	int a[4][4];
	int data[3];
	fun5(a);
	fun6(a,data);
	fun7(data);
	return 0;
}

//������ 7.10 ת��3*3����
void fun8(int (*p)[3]) {
	int a[3][3];
	int i, j;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			a[j][i] = p[i][j];
		}
	}
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			p[i][j] = a[i][j];
		}
	}
}
int main10() {
	int a[3][3] = { 0 };
	int i,j;
	printf("������3*3����\n");
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			scanf_s("%d", &a[i][j]);
		}
	}
	fun8(a);
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			printf("%d\t", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}

//������ 7.11 ʹ��ָ�뽻�����������ж�Ӧ��Ԫ��
void fun9(int (*pa)[3],int (*pb)[3]) {
	int i, j, temp;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			temp = pa[i][j];
			pa[i][j] = pb[i][j];
			pb[i][j] = temp;
		}
	}
}
int main11() {
	int a[3][3] = { 1,2,3,4,5,6,7,8,9 };
	int b[3][3] = { 10,11,12,13,14,15,16,17,18 };
	fun9(a, b);
	int i, j;
	printf("a:\n");
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			printf("%d\t", a[i][j]);
		}
		printf("\n");
	}
	printf("b:\n");
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			printf("%d\t", b[i][j]);
		}
		printf("\n");
	}
	return 0;
}

//������ 7.12  ������ĵ�n��Ԫ�ؿ�ʼ����
void fun10(int* p, int n, int m)
{
	n--;
	m--;
	int i,j;
	for (i = 0; i < m/2; i++)
	{
		int temp = p[n + m - i];
		p[n + m - i] = p[n + i];
		p[n + i] = temp;
		for (j = 0; j < 10; j++)
		{
			printf("%d\t", p[j]);
		}
		printf("\n");
	}
}
int main12()
{
	int a[10] = { 2,4,6,8,10,12,14,16,18,20 };
	int n, m, i;
	printf("please input n\n");
	scanf_s("%d", &n);
	printf("please input m\n");
	scanf_s("%d", &m);
	fun10(a, n, m);
	for (i = 0; i < 10; i++)
	{
		printf("%d\t", a[i]);
	}
	return 0;
}

//������ 7.13 ��m��n�еĶ�ά���鰴�е�˳��ŵ�һά������
void fun11(int (*pa)[5], int* pb)
{
	int i, j, k = 0;
	printf("��ά����Ϊ��\n");
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 5; j++)
		{
			pb[k] = pa[i][j];
			printf("%d\t", pb[k]);
			k++;
		}
		printf("\n");
	}
	printf("һά����Ϊ��\n");
	for (k = 0; k < 20; k++)
	{
		printf("%d\t", pb[k]);
	}
}
int main13()
{
	int a[4][5];
	int b[20] = { 0 };
	int i,j;
	srand((unsigned)time(NULL));
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 5; j++)
		{
			a[i][j] = rand();
			printf("%d\t", a[i][j]);
		}
		printf("\n");
	}
	fun11(a,b);
	return 0;
}

//̷��ǿ8.4 ��n��������ʹǰ�����˳�������m��λ�ã����m���������ǰ��m����
void fun12(int* p, int m, int n)
{
	int i,j = 0;
	int b[100] = {0};
	for (i = n - m; i < n; i++)
	{
		b[j] = p[i];
		j++;
	}
	for (i = n - m - 1; i >= 0; i--)
	{
		p[i + m] = p[i];
	}
	for (i = 0; i < m; i++) {
		p[i] = b[i];
	}
}
int main14()
{
	int a[100] = {1,2,3,4,5,6,7,8,9,10};
	int i = 0, m;
	printf("����m��ֵ\n");
	scanf_s("%d", &m);
	int n = 0;
	while (a[i] != 0)
	{
		n++;
		i++;
	}
	fun12(a, m, n);
	printf("����������飺\n");
	for (i = 0; i < 10; i++)
	{
		printf("%d\t", a[i]);
	}
	return 0;
}
//̷��ǿ8.5 n����1~3����������3�˳���������µ���ԭ���ĵڼ�λ
void fun13(int* p, int n)
{
	int i, j = 1,k = 0;
	while (k < n-1)
	{
		for (i = 0; i < n; i++)
		{
			if (p[i] == 0)
			{
				continue;
			}
			if (j == 3)
			{
				p[i] = 0;
				j = 1;
				k++;
			}
			else
			{
				j++;
			}
		}
	}
}
int main85()
{
	int a[100] = {0};
	int n, i;
	printf("intput n:\n");
	scanf_s("%d", &n);
	for (i = 0; i < n; i++)
	{
		a[i] = i + 1;
	}
	fun13(a, n);
	for (i = 0; i < n; i++)
	{
		if (a[i] != 0)
		{
			printf("%d", a[i]);
		}
	}
	return 0;
}

//̷��ǿ8.6 ���ַ�������
void fun14(char *p)
{
	int i, count = 0;
	for (i = 0; i < 100; i++)
	{
		if (p[i] == '\0')
		{
			break;
		}
		count++;
	}
	printf("length = %d", count);
}
int main86()
{
	char str[100];
	gets_s(str,100);
	fun14(str);
	return 0;
}

//̷��ǿ8.7 n���ַ����ַ��дӵ�m���ַ���ʼȫ���ַ����Ƴ���һ���ַ���
void fun15(char* pa, char* pb, int m)
{
	int i, j = 0;
	for (i = m - 1; i < 100; i++)
	{
		if (pa[i] != '/0')
		{
			pb[j] = pa[i];
			j++;
		}
		else break;
	}
}
int main87()
{
	char str1[100];
	char str2[100];
	int m;
	printf("input str\n");
	gets_s(str1,100);
	printf("input m\n");
	scanf_s("%d", &m);
	fun15(str1, str2, m);
	puts(str2);
	return 0;
}

//̷��ǿ8.11 ����10���ȳ��ַ���
void fun16(char(*p)[100])
{
	int i,j;
	for (i = 0; i < 9; i++)
	{
		for (j = i + 1; j < 10; j++)
		{
			if (strcmp(p[i], p[j]) > 0)
			{
				char temp[100];
				strcpy_s(temp, 100, p[i]);
				strcpy_s(p[i], 100, p[j]);
				strcpy_s(p[j], 100, temp);
			}
		}
	}
}
int main811()
{
	char str[10][100];
	int i;
	printf("����ı�ǰ���ַ���\n");
	for (i = 0; i < 10; i++)
	{
		gets_s(str[i],100);
	}
	fun16(str);
	printf("�ı����ַ���\n");
	for (i = 0; i < 10; i++)
	{
		puts(str[i]);
	}
	return 0;
}

//̷��ǿ8.16 ����һ���ַ����������е�����������Ϊ�����浽����a�У�ͳ���ж��ٸ�
int fun17(char* p,int* pa)
{
	int i = 0, j = 0, flag = 0;
	while (p[i] != '\0')
	{
		if (p[i] >= '0' && p[i] <= '9')
		{
			pa[j] = pa[j] * 10 + (p[i] - 48); 
			flag = 1;
		}
		if (flag == 1 && (p[i] < '0' || p[i] > '9'))
		{
			flag = 2;
		}
		if (flag == 2)
		{
			j++;
			flag = 0;
		}
		i++;
	}
	j++;
	return j;
}
int main816()
{
	char str[100];
	int a[100] = {0};
	int i, j;
	fflush(stdin);
	printf("������һ���ַ���\n");
	gets_s(str, 100);
	j = fun17(str, a);
	printf("����%d����\n", j);
	for (i = 0; i < j; i++)
	{
		printf("%d\t", a[i]);

	}
	return 0;
}

//������ 8.1 ���ַ������Ⱥ���
int fun18(char* p)
{
	int i = 0;
	while (p[i] != '\0')
	{
		i++;
	}
	return i;
}
int main81()
{
	char str[100];
	printf("input string\n");
	gets_s(str, 100);
	int n = fun18(str);
	printf("length of string = %d", n);
	return 0;
}

//������ 8.2 �ַ������Ӻ���
void mycat(char* pa,char* pb)
{
	int i = 0, j = 0;
	if (strlen(pa) + strlen(pb) > 10)
	{
		printf("not enough space\n");
		exit(0);
	}
	while (pa[i] != '\0')
	{
		i++;
	}
	while (pb[j] != '\0')
	{
		pa[i] = pb[j];
		i++;
		j++;
	}
	pa[i + 1] = '\0';
	puts(pa);
}
int main82()
{
	char str1[10] = { "abcd" };
	char str2[10] = { "efghijk" };
	mycat(str1, str2);
	return 0;
}

//������ 8.3 �����ַ�������
void mycpy(char* pa, char* pb, unsigned int x)
{
	if (strlen(pb) + 1 > x)
	{
		printf("not enough space!");
		exit(0);
	}
	unsigned int i;
	for (i = 0; i < strlen(pb); i++)
	{
		pa[i] = pb[i];
	}
	puts(pa);
}
int main83()
{
	char str1[10] = { "abcd" };
	char str2[10] = { "efgh" };
	mycpy(str1, str2, 10);
	return 0;
}

//������ 8.4 �Ƚ��ַ�������
int mycmp(char* pa, char* pb)
{
	int i, x = 0;
	for (i = 0; i < 100; i++)
	{
		x += pa[i] - pb[i];
		printf("%d\t%d\t%d\n", x, pa[i], pb[i]);
	}
	return x;
}
int main84()
{
	char str1[100] = "";
	char str2[100] = "";
	printf("input first string\n");
	gets_s(str1, 100);
	printf("input second string\n");
	gets_s(str2, 100);
	int i = 0;
	for (i = strlen(str1) + 1; i < 100; i++)
	{
		str1[i] = '\0';
	}
	for (i = strlen(str2) + 1; i < 100; i++)
	{
		str2[i] = '\0';
	}
	printf("%d\n", mycmp(str1, str2));
	return 0;
}

//������ 8.5 ɾ���ַ����е�����Ȼ�����
void fun19(char* p)
{
	int i = 0;
	while (p[i] != '\0')
	{
		if (p[i] >= '0' && p[i] <= '9')
		{
			int j;
			for (j = i; j < 100 - i; j++)
			{
				p[j] = p[j + 1];
			}
		}
		else i++;
	}
}
int main185()
{
	char str[100];
	printf("input string\n");
	gets_s(str, 100);
	fun19(str);
	puts(str);
	return 0;
}

//������ 8.6 ͳ��26����ĸ���ֵĴ���
void fun20(char* pa, int* pb)
{
	int i = 0;
	while (pa[i] != '\0')
	{
		pb[pa[i] - 'a']++;
		i++;
	}
}
int main186()
{
	char str[100];
	int a[26] = {0};
	gets_s(str, 100);
	fun20(str,a);
	int i;
	for (i = 0; i < 26; i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
}

//������ 8.7 �������ַ���ת��Ϊ����ֵ
int fun21(char* pa)
{
	int i = 0, n = 0,flag = 1;
	if (pa[0] == '-')
	{
		flag = -1;
		i++;
	}
	while (pa[i] != '\0')
	{
		n = n * 10 + (pa[i] - '0');
		i++;
	}
	return n * flag;
}
int main187()
{
	char str[100];
	printf("input string\n");
	gets_s(str, 100);
	int n = fun21(str);
	printf("tranform to %d", n);
	return 0;
}

//������ 8.9 �ӵ�m������ʼ�����������ǰ���������
void fun22(char* p, int m, int n)
{
	int i, j = 0;
	char str2[100] = "";
	for (i = 0; i < m; i++)
	{
		str2[i] = p[i];
	}
	for (i = m; i < n; i++)
	{
		p[j] = p[i];
		j++;
	}
	j = n - m;
	for (i = 0; i < m; i++)
	{
		p[j] = str2[i];
		j++;
	}
}
int main189()
{
	char str[100] = "ABCDEFGH";
	int m, n;
	printf("input m\n");
	scanf_s("%d", &m);
	n = strlen(str);
	fun22(str, m, n);
	puts(str);
	return 0;
}

//������ 8.10 ���������ַ�����������ȣ�����ӡ���һ���ַ�������
int main810()
{
	char str[100][100] = {""};
	int length[100] = { 0 };
	int i = 0, j = 0;
	do
	{
		gets_s(str[j], 100);
		j++;
	} while (strcmp(str[j-1], "stop") != 0);
	int max = strlen(str[0]), index = 0;
	for (i = 0; i < j; i++)
	{
		length[i] = strlen(str[i]);
		if (max < strlen(str[i]))
		{
			max = strlen(str[i]);
			index = i;
		}
	}
	printf("the %dth is longest:\n%s\n", index + 1, str[index]);
	return 0;
}

//������ 8.11 �����ַ���s1��s2�Լ�����λ��f�����ַ���s1��fλ�ò���s2
int main()
{
	char str1[100] = "";
	char str2[100] = "";
	int f;
	printf("intput string s1:\n");
	gets_s(str1, 100);
	printf("intput string s2:\n");
	gets_s(str2, 100);
	printf("input f:\n");
	scanf_s("%d", &f);
	if (strlen(str1) + strlen(str2) + 1 > 100)
	{
		printf("not enough space!\nexit now\n");
		exit(0);
	}
	int i, length = strlen(str1);;
	for (i = length - 1 ; i >= f ; i--)
	{
		str1[i + strlen(str2)] = str1[i];
	}
	for (i = 0; i < strlen(str2); i++)
	{
		str1[f + i] = str2[i];
	}
	printf("output:\n%s", str1);
	return 0;
}
