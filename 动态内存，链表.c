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
������ 10.1 ��malloc���ٶ�̬�洢��Ԫ��˳����10������������10���������ֵ
*/
int main1()
{
	int* p = (int*)malloc(10 * sizeof(int));
	if (p == NULL)
	{
		printf("����ռ�ʧ��");
		exit(1);
	}
	int i;
	printf("������ʮ������:\n");
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
	printf("������Ϊ:%d\n", max);
	free(p);
	return 0;
}

/*
������ 10.2 ��malloc���ٶ�̬�洢��Ԫ��˳����10���ַ���������10���ַ��������ֵ
��malloc���ٶ�̬�洢��Ԫ��ά��Ҫ**���ޣ���������Ҫ
*/
int main2()
{
	char** p = (char**)malloc(10 * sizeof(char*));
	if (p == NULL)
	{
		printf("����ռ�ʧ��");
		exit(1);
	}
	int i;
	for (i = 0; i < 10; i++)
	{
		p[i] = (char*)malloc(20 * sizeof(char));
		if (p[i] == NULL)
		{
			printf("����ռ�ʧ��");
			exit(1);
		}
	}
	printf("��������󳤶�Ϊ19��ʮ���ַ���:\n");
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
	printf("�����ַ���Ϊ:%s\n", max);
	for (i = 0; i < 10; i++)
	{
		free(p[i]);
	}
	free(p);
	return 0;
}

/*
������ 10.3 ��malloc���ٶ�̬�洢��Ԫ��˳����10��ѧ�����ݣ����10��ѧ����ƽ������ߵ�ѧ����Ϣ
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
		printf("����ռ�ʧ��");
		exit(1);
	}
	printf("������10��ѧ������Ϣ\n");
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
	printf("ƽ������ߵ�ѧ����Ϣ:\n");
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
������ 10.4 β�巨����һ����������ĵ�����������-1��������ӡ���������
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
		printf("����ռ�ʧ��");
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
			printf("����ռ�ʧ��");
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
������ 10.5 β�巨����һ������ַ����ĵ�����������stop��������ӡ���������
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
		printf("����ռ�ʧ��");
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
			printf("����ռ�ʧ��");
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
	printf("�������:\n");
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
������ 10.6 β�巨����һ����Ŷ��ѧ�����ݵĵ�����������ѧ��0��������ӡ���������
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
		printf("����ռ�ʧ��\n");
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
			printf("����ռ�ʧ��\n");
			exit(0);
		}
		p->data = x;
		p->next = NULL;
		tail->next = p;
		tail = p;
		printf("������ѧ����Ϣ\n");
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
������ 10.7 ���ô�ͷ���ĵ�������ÿ���ڵ�����ַ����������ָ����
*/
//ת�ú���
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
//����
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
		printf("����ռ�ʧ��\n");
		exit(1);
	}
	LNode* p, * tail;
	head->next = NULL;
	tail = head;
	char x;
	printf("�����������ַ�,��'#'�ַ���ʾ����\n");
	scanf_s(" %c", &x, 1);
	while (x != '#')
	{
		if ((p = (LNode*)malloc(sizeof(LNode))) == NULL)
		{
			printf("����ռ�ʧ��\n");
			exit(1);
		}
		p->data = x;
		p->next = NULL;
		tail->next = p;
		tail = p;
		scanf_s(" %c", &x, 1);
	}
	printf("������ַ�:\n");
	p = head->next;
	while (p != NULL)
	{
		printf("%c\t", p->data);
		p = p->next;
	}
	printf("\n");
	head = Inverse(head);
	printf("ת�ú������:\n");
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
������ 10.9 ͷ�巨������������ĵ�������-1��������ӡ�����������ֵ
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
		printf("����ռ�ʧ��");
		exit(1);
	}
	head->next = NULL;
	printf("��������:\n");
	int x;
	scanf_s("%d", &x);
	while (x != -1)
	{
		if ((p = (LNode*)malloc(sizeof(LNode))) == NULL)
		{
			printf("����ռ�ʧ��");
			exit(1);
		}
		p->data = x;
		p->next = head->next;
		head->next = p;
		scanf_s("%d", &x);
	}
	p = head->next;
	int max = p->data;
	printf("�������:\n");
	while (p != NULL)
	{
		printf("%d\t", p->data);
		if (max < p->data)
		{
			max = p->data;
		}
		p = p->next;
	}
	printf("������Ϊ%d\n", max);
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
������ 10.10 ͷ�巨��������ַ����ĵ�������stop��������ӡ�����������ֵ
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
		printf("����ռ�ʧ��\n");
		exit(0);
	}
	head->next = NULL;
	char x[20] = "";
	printf("���������ɳ��Ȳ�����19���ֽڵ��ַ�������stop����\n");
	scanf_s("%s", x, 20);
	while (strcmp(x,"stop") != 0)
	{
		if ((p = (LNode*)malloc(sizeof(LNode))) == NULL)
		{
			printf("����ռ�ʧ��\n");
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
	printf("�������:\n");
	while (p != NULL)
	{
		printf("%s\n", p->data);
		if (strcmp(max, p->data) < 0)
		{
			strcpy_s(max, 20, p->data);
		}
		p = p->next;
	}
	printf("�����ַ���Ϊ:%s\n", max);
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