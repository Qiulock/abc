#include<stdio.h>
#include<string.h>

//祁文青 9.1定义一个结构体类型变量（年月日），输入一个日期显示他是该年第几天
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
	printf("他是该年的第%d天", x);
	return 0;
}
//祁文青 9.2定义一个结构体类型数组（年月日），实现输入十个日期，按日期从大到小输出
int main2()
{
	struct DATE date[10];
	int i = 0,j = 0;
	for (i = 0; i < 10; i++)
	{
		printf("请输入第%d个日期（年-月-日）:\n", i + 1);
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
	printf("按日期从大到小：\n");
	for (i = 0; i < 10; i++)
	{
		printf("%d-%d-%d\n", date[i].year, date[i].month, date[i].day);
	}
	return 0;
}

/*祁文青 9.4 定义学生信息（学号、姓名、性别、出生日期、4门课程成绩、平均分）的结构类型，编写以下函数:
1输入单个学生信息的函数input(struct stu* a)
2输出单个学生信息的函数output(struct a)
3输入一批学员信息的函数inputarray(struct stu a[],int n)
4输出一批学员信息的函数outputarray(struct stu a[],int n)
5按姓名进行查找的函数searchname()，若找到，返回该学生信息，不排除有同名同姓的情况；否则返回查无此人
6按学生的姓名从小到大将学生排序sortname()
编程建立结构体数组输入全班（最多50人）学生信息，按学生的姓名从小到大排序，输出学生的所有信息
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
		printf("请输入第%d个学生信息\n", i + 1);
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
		printf("查无此人\n");
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
	printf("按学生的姓名从小到大排序\n");
	sortname(student, 5);
	outputs(student, 5);
	return 0;
}

/*
祁文青 9.6 已知一个长度为2个字节的整数，现欲将其高字节与 低字节相互交换后输出，试用共用体类型实现这一功能。
没搞懂
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
祁文青 9.7 定义枚举类型money，用枚举元素代表人民币的面值（1、2、5分，1、2、5角，1、2、5、10、50、100元），从键盘指定金额如345.78元，显示该支付的各种面额人民币数量
*/
int main7()
{
	enum money { f1 = 1, f2 = 2, f5 = 5, j1 = 10, j2 = 20, j5 = 50, y1 = 100, y2 = 200, y5 = 500, y10 = 1000, y50 = 5000, y100 = 10000 };
	return 0;
}
