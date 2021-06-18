#include<stdio.h>
struct SCORE 
{
	int math;
	int english;
	int chinese;
};
struct STUDENT
{
	char sid[5];
	char name[10];
	struct SCORE score;
}student[5];

void input() {
	int i;
	for (i = 0; i < 5; i++) {
		printf("%dof%d\n",i,5);
		scanf_s("%s", student[i].sid,5);
		scanf_s("%s", student[i].name,10);
		scanf_s("%d", &student[i].score.math);
		scanf_s("%d", &student[i].score.english);
		scanf_s("%d", &student[i].score.chinese);
	}
}

void print() {
	int i = 0, avg[4] = {0}, sum[4] = { 0 }, max = 0, maxid = 0;
	printf("Êä³ö\n");
	for (i = 0; i < 5; i++) {
		printf("%dof%d\n", i, 5);
		printf("%s\t%s\t%d\t%d\t%d\n", student[i].sid,student[i].name,student[i].score.math, student[i].score.english, student[i].score.chinese);
		if (max < student[i].score.math + student[i].score.english + student[i].score.chinese) {
			max = student[i].score.math + student[i].score.english + student[i].score.chinese;
			maxid = i;
		}
		sum[0] += student[i].score.math;
		sum[1] += student[i].score.english;
		sum[2] += student[i].score.chinese;
	}
	sum[3] += sum[0] + sum[1] + sum[2];
	printf("math=%d\tenglish=%d\tchinese=%d\tscore=%d\n", sum[0] / 5, sum[1] / 5, sum[2] / 5, sum[3] / 15);
	printf("max:\n");
	printf("sid=%s\tname=%s\tmath=%d\tenglish=%d\tchinese=%d\t", student[maxid].sid, student[maxid].name, student[maxid].score.math, student[maxid].score.english, student[maxid].score.chinese);
}

int main() {
	input();
	print();
	return 0;
}