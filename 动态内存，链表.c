#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
		p->data = x;
		p->next = NULL;
		tail->next = p;
		tail = p;
*/


struct Node
{
	char data;
	struct Node* next;
};

typedef struct Node LNode;
typedef struct Node* LinkList;


/*
祁文青 10.1 用malloc开辟动态存储单元，顺序存放10个整数，求这10个数的最大值
*/
int main1()
{
	int* p = (int*)malloc(10 * sizeof(int));
	if (p == NULL)
	{
		printf("申请空间失败");
		exit(1);
	}
	int i;
	printf("请输入十个整数:\n");
	for (i = 0; i < 10; i++)
	{
		scanf_s("%d", p + i);
	}
	int max = p[0];
	for (i = 1; i < 10; i++)
	{
		if (max < p[i])
		{
			max = p[i];
		}
	}
	printf("最大的数为:%d\n", max);
	free(p);
	return 0;
}

/*
祁文青 10.2 用malloc开辟动态存储单元，顺序存放10个字符串，求这10个字符串的最大值
用malloc开辟动态存储单元二维需要**套娃，而链表不需要
*/
int main2()
{
	char** p = (char**)malloc(10 * sizeof(char*));
	if (p == NULL)
	{
		printf("申请空间失败");
		exit(1);
	}
	int i;
	for (i = 0; i < 10; i++)
	{
		p[i] = (char*)malloc(20 * sizeof(char));
		if (p[i] == NULL)
		{
			printf("申请空间失败");
			exit(1);
		}
	}
	printf("请输入最大长度为19的十个字符串:\n");
	for (i = 0; i < 10; i++)
	{
		scanf_s("%s", p[i],20);
	}
	char max[20];
	strcpy_s(max, 20, p[0]);
	for (i = 1; i < 10; i++)
	{
		if (strcmp(max,p[i]) < 0)
		{
			strcpy_s(max, 20, p[i]);
		}
	}
	printf("最大的字符串为:%s\n", max);
	for (i = 0; i < 10; i++)
	{
		free(p[i]);
	}
	free(p);
	return 0;
}

/*
祁文青 10.3 用malloc开辟动态存储单元，顺序存放10个学生数据，输出10个学生中平均分最高的学生信息
*/
struct date
{
	int year;
	int month;
	int day;
};
struct sco
{
	int math;
	int chinese;
	int english;
};
struct stu
{
	char num[10];
	char name[20];
	char sex;
	struct date brith;
	struct sco score;
	float avg;
};
int main3()
{
	struct stu* p = (struct stu*)malloc(10 * sizeof(struct stu));
	if (p == NULL)
	{
		printf("申请空间失败");
		exit(1);
	}
	printf("请输入10个学生的信息\n");
	int i;
	float max = 0;
	for (i = 0; i < 10; i++)
	{
		scanf_s("%s %s %c %d %d %d %d %d %d", p[i].num, 10, p[i].name, 20, &p[i].sex, 1, &p[i].brith.year, &p[i].brith.month, &p[i].brith.day, &p[i].score.math, &p[i].score.chinese, &p[i].score.english);
		p[i].avg = (p[i].score.math + p[i].score.chinese + p[i].score.english) / (float)3.0;
		if (p[i].avg > max)
		{
			max = p[i].avg;
		}
	}
	printf("平均分最高的学生信息:\n");
	for (i = 0; i < 10; i++)
	{
		if (p[i].avg == max)
		{
			printf("num=%s name=%s sex=%c birthday:%d-%d-%d math=%d chinese=%d english=%d avg=%f\n", p[i].num, p[i].name, p[i].sex, p[i].brith.year, p[i].brith.month, p[i].brith.day, p[i].score.math, p[i].score.chinese, p[i].score.english, p[i].avg);
		}
	}
	free(p);
	return 0;
}

/*
祁文青 10.4 尾插法创建一个存放整数的单向链表，输入-1结束，打印输出该链表
*/
int main4()
{
	struct Node
	{
		int date;
		struct Node* next;
	};

	typedef struct Node LNode;
	typedef struct Node* LinkList;

	LinkList head;
	if ((head =  (LNode*)malloc(sizeof(LNode))) == NULL)
	{
		printf("申请空间失败");
		exit(0);
	}
	head->next = NULL;
	LNode* p, * tail;
	int x, flag = -1;
	tail = head;
	scanf_s("%d", &x);
	while (x != flag)
	{
		if ((p = (LNode*)malloc(sizeof(LNode))) == NULL)
		{
			printf("申请空间失败");
			exit(0);
		}
		p->date = x;
		p->next = NULL;
		tail->next = p;
		tail = p;
		scanf_s("%d", &x);
	}
	p = head->next;
	while (p != NULL)
	{
		printf("%d\t", p->date);
		p = p->next;
	}
	p = head->next;
	LNode* q;
	while (p != NULL)
	{
		q = p->next;
		free(p);
		p = q;
	}
	return 0;
}

/*
祁文青 10.5 尾插法创建一个存放字符串的单向链表，输入stop结束，打印输出该链表
*/
int main5()
{
	struct Node
	{
		char date[20];
		struct Node* next;
	};

	typedef struct Node LNode;
	typedef struct Node* LinkList;

	LinkList head;
	if ((head = (LNode*)malloc(sizeof(LNode))) == NULL)
	{
		printf("申请空间失败");
		exit(0);
	}
	LNode* p, * tail;
	head->next = NULL;
	tail = head;
	char str[20] = "";
	scanf_s("%s", str, 20);
	while (strcmp(str, "stop") != 0)
	{
		if ((p = (LNode*)malloc(sizeof(LNode))) == NULL)
		{
			printf("申请空间失败");
exit(0);
		}
		strcpy_s(p->date, 20, str);
		p->next = NULL;
		tail->next = p;
		tail = p;
		scanf_s("%s", str, 20);
	}
	p = head->next;
	while (p != NULL)
	{
		printf("%s\n", p->date);
		p = p->next;
	}
	printf("输出链表:\n");
	p = head->next;
	LNode* q;
	while (p != NULL)
	{
		q = p->next;
		free(p);
		p = q;
	}
	return 0;
}

/*
祁文青 10.6 尾插法创建一个存放多个学生数据的单向链表，输入学号0结束，打印输出该链表
struct stu x;
p = x;
*/
int main6()
{
	struct Node
	{
		struct stu data;
		struct Node* next;
	};

	typedef struct Node LNode;
	typedef struct Node* LinkList;

	LinkList head;
	if ((head = (LNode*)malloc(sizeof(LNode))) == NULL)
	{
		printf("申请空间失败\n");
		exit(0);
	}
	LNode* p, * tail;
	head->next = NULL;
	tail = head;
	struct stu x;
	scanf_s("%s %s %c %d %d %d %d %d %d", x.num, 10, x.name, 20, &x.sex, 1, &x.brith.year, &x.brith.month, &x.brith.day, &x.score.math, &x.score.chinese, &x.score.english);
	x.avg = (x.score.math + x.score.chinese + x.score.english) / (float)3.0;
	while (strcmp(x.num, "0") != 0)
	{
		if ((p = (LNode*)malloc(sizeof(LNode))) == NULL)
		{
			printf("申请空间失败\n");
			exit(0);
		}
		p->data = x;
		p->next = NULL;
		tail->next = p;
		tail = p;
		printf("请输入学生信息\n");
		scanf_s("%s %s %c %d %d %d %d %d %d", x.num, 10, x.name, 20, &x.sex, 1, &x.brith.year, &x.brith.month, &x.brith.day, &x.score.math, &x.score.chinese, &x.score.english);
		x.avg = (x.score.math + x.score.chinese + x.score.english) / (float)3.0;
	}
	p = head->next;
	while (p != NULL)
	{
		printf("num=%s name=%s sex=%c birthday:%d-%d-%d math=%d chinese=%d english=%d avg=%f\n", p->data.num, p->data.name, p->data.sex, p->data.brith.year, p->data.brith.month, p->data.brith.day, p->data.score.math, p->data.score.chinese, p->data.score.english, p->data.avg);
		p = p->next;
	}
	LNode* q;
	p = head->next;
	while (p != NULL)
	{
		q = p->next;
		free(p);
		p = q;
	}
	return 0;
}

/*
祁文青 10.7 逆置带头结点的单向链表，每个节点包含字符型数字域和指针域
*/
//转置函数
LNode* Inverse(LNode* L)
{
	LNode* p, * q;
	p = L->next;
	L->next = NULL;
	while (p != NULL)
	{
		q = p;
		p = p->next;

		q->next = L->next;
		L->next = q;
	}
	return L;
}
//结束
int main7()
{
	/*
	struct Node
	{
		char data;
		struct Node* next;
	};

	typedef struct Node LNode;
	typedef struct Node* LinkList;
	*/

	LNode* head;
	if ((head = (LNode*)malloc(sizeof(LNode))) == NULL )
	{
		printf("申请空间失败\n");
		exit(1);
	}
	LNode* p, * tail;
	head->next = NULL;
	tail = head;
	char x;
	printf("请输入若干字符,以'#'字符表示结束\n");
	scanf_s(" %c", &x, 1);
	while (x != '#')
	{
		if ((p = (LNode*)malloc(sizeof(LNode))) == NULL)
		{
			printf("申请空间失败\n");
			exit(1);
		}
		p->data = x;
		p->next = NULL;
		tail->next = p;
		tail = p;
		scanf_s(" %c", &x, 1);
	}
	printf("输入的字符:\n");
	p = head->next;
	while (p != NULL)
	{
		printf("%c\t", p->data);
		p = p->next;
	}
	printf("\n");
	head = Inverse(head);
	printf("转置后的链表:\n");
	p = head->next;
	while (p != NULL)
	{
		printf("%c\t", p->data);
		p = p->next;
	}
	LNode* q;
	p = head->next;
	while (p != NULL)
	{
		q = p->next;
		free(p);
		p = q;
	}
	return 0;
}

/*
祁文青 10.9 头插法创建存放整数的单向链表，-1结束，打印输出链表和最大值
*/
int main9()
{
	struct node
	{
		int data;
		struct node* next;
	};

	typedef struct node LNode;
	typedef struct node* LinkList;

	LNode* head, * p;
	if ((head = (LNode*)malloc(sizeof(LNode))) == NULL)
	{
		printf("申请空间失败");
		exit(1);
	}
	head->next = NULL;
	printf("输入整数:\n");
	int x;
	scanf_s("%d", &x);
	while (x != -1)
	{
		if ((p = (LNode*)malloc(sizeof(LNode))) == NULL)
		{
			printf("申请空间失败");
			exit(1);
		}
		p->data = x;
		p->next = head->next;
		head->next = p;
		scanf_s("%d", &x);
	}
	p = head->next;
	int max = p->data;
	printf("输出链表:\n");
	while (p != NULL)
	{
		printf("%d\t", p->data);
		if (max < p->data)
		{
			max = p->data;
		}
		p = p->next;
	}
	printf("最大的数为%d\n", max);
	p = head->next;
	LNode* q;
	while (p != NULL)
	{
		q = p->next;
		free(p);
		p = q;
	}
	return 0;
}

/*
祁文青 10.10 头插法创建存放字符串的单向链表，stop结束，打印输出链表和最大值
*/
int main()
{
	struct node
	{
		char data[20];
		struct node* next;
	};

	typedef struct node LNode;
	typedef struct node* LinkList;

	LNode* head, * p;
	if ((head = (LNode*)malloc(sizeof(LNode))) == NULL)
	{
		printf("申请空间失败\n");
		exit(0);
	}
	head->next = NULL;
	char x[20] = "";
	printf("请输入若干长度不大于19个字节的字符串，以stop结束\n");
	scanf_s("%s", x, 20);
	while (strcmp(x,"stop") != 0)
	{
		if ((p = (LNode*)malloc(sizeof(LNode))) == NULL)
		{
			printf("申请空间失败\n");
			exit(0);
		}
		strcpy_s(p->data, 20, x);
		p->next = head->next;
		head->next = p;
		scanf_s("%s", &x, 20);
	}
	p = head->next;
	char max[20];
	strcpy_s(max, 20, p->data);
	printf("输出链表:\n");
	while (p != NULL)
	{
		printf("%s\n", p->data);
		if (strcmp(max, p->data) < 0)
		{
			strcpy_s(max, 20, p->data);
		}
		p = p->next;
	}
	printf("最大的字符串为:%s\n", max);
	LNode* q;
	p = head->next;
	while (p != NULL)
	{
		q = p->next;
		free(p);
		p = q;
	}
	return 0;
}