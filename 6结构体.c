#include<stdio.h>
#include<string.h>

//������ 9.1����һ���ṹ�����ͱ����������գ�������һ��������ʾ���Ǹ���ڼ���
struct DATE
{
	int year;
	int month ;
	int day;
};
int main1()
{
	struct DATE date;
	int a[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	printf("input year-month-day:\n");
	scanf_s("%d-%d-%d", &date.year, &date.month, &date.day);
	int flag = 0;
	if ((date.year % 4 == 0 && date.year % 100 != 0) || (date.year % 400 == 0))
	{
		if (date.month > 2)
		{
			flag = 1;
		}
	}
	int i, x = 0;;
	for (i = 0; i < date.month - 1; i++)
	{
		x += a[i];
	}
	x += flag + date.day;
	printf("���Ǹ���ĵ�%d��", x);
	return 0;
}
//������ 9.2����һ���ṹ���������飨�����գ���ʵ������ʮ�����ڣ������ڴӴ�С���
int main2()
{
	struct DATE date[10];
	int i = 0,j = 0;
	for (i = 0; i < 10; i++)
	{
		printf("�������%d�����ڣ���-��-�գ�:\n", i + 1);
		scanf_s("%d-%d-%d", &date[i].year, &date[i].month, &date[i].day);
	}
	struct DATE temp;
	for (i = 0; i < 9; i++)
	{
		for (j = i+1; j < 10; j++)
		{
			int flag = 0;
			if (date[i].year < date[j].year)
			{
				flag = 1;
			}
			else if (date[i].year == date[j].year)
			{
				if (date[i].month < date[j].month)
				{
					flag = 1;
				}
				else if (date[i].month == date[j].month)
				{
					if (date[i].day < date[j].day)
					{
						flag = 1;
					}
				}
			}
			if (flag)
			{
				temp = date[i];
				date[i] = date[j];
				date[j] = temp;
			}
		}
	}
	printf("�����ڴӴ�С��\n");
	for (i = 0; i < 10; i++)
	{
		printf("%d-%d-%d\n", date[i].year, date[i].month, date[i].day);
	}
	return 0;
}

/*������ 9.4 ����ѧ����Ϣ��ѧ�š��������Ա𡢳������ڡ�4�ſγ̳ɼ���ƽ���֣��Ľṹ���ͣ���д���º���:
1���뵥��ѧ����Ϣ�ĺ���input(struct stu* a)
2�������ѧ����Ϣ�ĺ���output(struct a)
3����һ��ѧԱ��Ϣ�ĺ���inputarray(struct stu a[],int n)
4���һ��ѧԱ��Ϣ�ĺ���outputarray(struct stu a[],int n)
5���������в��ҵĺ���searchname()�����ҵ������ظ�ѧ����Ϣ�����ų���ͬ��ͬ�յ���������򷵻ز��޴���
6��ѧ����������С����ѧ������sortname()
��̽����ṹ����������ȫ�ࣨ���50�ˣ�ѧ����Ϣ����ѧ����������С�����������ѧ����������Ϣ
*/
struct SCORE
{
	int math;
	int english;
	int chinese;
	int sport;
};
struct STUDENT
{
	char number[5];
	char name[20];
	char sex;
	struct DATE birthday;
	struct SCORE score;
	int avgscore;
};
void input(struct STUDENT* p)
{
	scanf_s("%s %s %c %d-%d-%d %d-%d-%d-%d", p->number, 5, p->name, 20, &p->sex, 1, &p->birthday.year, &p->birthday.month, &p->birthday.day, &p->score.math, &p->score.english, &p->score.chinese, &p->score.sport);
	p->avgscore = (p->score.math + p->score.english + p->score.chinese + p->score.sport) / 4;
}
void output(struct STUDENT p)
{
	printf("number:%s name:%s sex:%c birthday:%d-%d-%d math:%d english:%d chinese:%d sport:%d avgscore:%d\n\n", p.number, p.name, p.sex, p.birthday.year, p.birthday.month, p.birthday.day, p.score.math, p.score.english, p.score.chinese, p.score.sport, p.avgscore);
}
void inputs(struct STUDENT p[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("�������%d��ѧ����Ϣ\n", i + 1);
		scanf_s("%s %s %c %d-%d-%d %d-%d-%d-%d", p[i].number, 5, p[i].name, 20, &p[i].sex, 1, &p[i].birthday.year, &p[i].birthday.month, &p[i].birthday.day, &p[i].score.math, &p[i].score.english, &p[i].score.chinese, &p[i].score.sport);
		p[i].avgscore = (p[i].score.math + p[i].score.english + p[i].score.chinese + p[i].score.sport) / 4;
	}
}
void outputs(struct STUDENT p[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("number:%s name:%s sex:%c birthday:%d-%d-%d math:%d english:%d chinese:%d sport:%d avgscore:%d\n", p[i].number, p[i].name, p[i].sex, p[i].birthday.year, p[i].birthday.month, p[i].birthday.day, p[i].score.math, p[i].score.english, p[i].score.chinese, p[i].score.sport, p[i].avgscore);
	}
}
void searchname(struct STUDENT p[], char str[20], int n)
{
	int i,found = 0;
	for (i = 0; i < n; i++)
	{
		if (strcmp(p[i].name, str) == 0)
		{
			printf("Found! number:%s name:%s sex:%c birthday:%d-%d-%d math:%d english:%d chinese:%d sport:%d avgscore:%d\n", p[i].number, p[i].name, p[i].sex, p[i].birthday.year, p[i].birthday.month, p[i].birthday.day, p[i].score.math, p[i].score.english, p[i].score.chinese, p[i].score.sport, p[i].avgscore);
			found = 1;
		}
	}
	if (found == 0)
	{
		printf("���޴���\n");
	}
}
void sortname(struct STUDENT p[], int n)
{
	int i,j;
	for (i = 0; i < n-1; i++)
	{
		for (j = i; j < n; j++)
		{
			if (strcmp(p[i].name, p[j].name) > 0)
			{
				struct STUDENT temp = p[i];
				p[i] = p[j];
				p[j] = temp;
			}
		}
	}
}
int main4()
{
	struct STUDENT student[50];
	inputs(student,5);
	searchname(student, "zhu", 5);
	printf("��ѧ����������С��������\n");
	sortname(student, 5);
	outputs(student, 5);
	return 0;
}

/*
������ 9.6 ��֪һ������Ϊ2���ֽڵ�����������������ֽ��� ���ֽ��໥��������������ù���������ʵ����һ���ܡ�
û�㶮
*/
int main6()
{
	union date
	{
		short i;
		char c[2];
	};
	union date x;
	char tmp;
	x.i = 0x1234;
	short a = 0x1234;
	printf("Before:%x\n", a);
	tmp = x.c[0];
	x.c[0] = x.c[1];
	x.c[1] = tmp;
	printf("After:%x\n", x.i);
	return 0;
}

/*
������ 9.7 ����ö������money����ö��Ԫ�ش�������ҵ���ֵ��1��2��5�֣�1��2��5�ǣ�1��2��5��10��50��100Ԫ�����Ӽ���ָ�������345.78Ԫ����ʾ��֧���ĸ���������������
*/
int main7()
{
	enum money { f1 = 1, f2 = 2, f5 = 5, j1 = 10, j2 = 20, j5 = 50, y1 = 100, y2 = 200, y5 = 500, y10 = 1000, y50 = 5000, y100 = 10000 };
	return 0;
}
