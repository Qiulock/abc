#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//祁文青 6.3 找出并对调max和min
int main3() {
	int a[10] = { 0 };
	int i, min, minloc, max, maxloc;
	for (i = 0; i < 10; i++) {
		scanf_s("%d", &a[i]);
	}
	min = a[0];
	max = a[9];
	for (i = 0; i < 10; i++) {
		if (a[i] < min) {
			min = a[i];
			minloc = i;
		}
		if (a[i] > max) {
			max = a[i];
			maxloc = i;
		}
	}
	int temp = a[minloc];
	a[minloc] = a[maxloc];
	a[maxloc] = temp;
	printf("\n");
	for (i = 0; i < 10; i++) {
		printf("%d ", a[i]);
	}
	return 0;
}
//祁文青 6.4 查找数值
int main4() {
	int a[10] = { 51,13,5,8,664,321,564,89,15,478 };
	int x = 0,xloc,i,found = 0;
	scanf_s("%d", &x);
	for (i = 0; i < 10; i++) {
		if (x == a[i]) {
			xloc = i;
			found = 1;
			printf("found! loc=%d", xloc+1);
			break;
		}
	}
	if (found == 0) {
		printf("not found!");
	}
	return 0;
}
//祁文青 6.5 二分法查数
int main5() {
	int a[15] = { 15,14,13,12,11,10,9,8,7,6,5,4,3,2,1 };
	int x = 0, i = 0, low = 0, high = 14;
	scanf_s("%d", &x);
	if (x < a[14] || x > a[0])
	{
		printf("不在此数组中");
	}
	else {
		while (low <= high) 
		{
			i = (low + high) / 2;
			if (a[i] == x) {
				printf("%d", i + 1);
				break;
			}
			else if (a[i] < x)
			{
				high = i - 1;
			}
			else
			{
				low = i + 1;
			}
		}
	}
	return 0;
}
//祁文青 6.6 插入元素保持顺序
int main6() {
	int a[10] = { 0 };
	int i, j, x, maxloc, isplace = 0;
	for (i = 0; i < 10; i++) {
		scanf_s("%d", &a[i]);
	}
	for (i = 0; i < 10; i++) {
		int max = 0;
		for (j = i; j < 10; j++) {
			if (max < a[j]) {
				max = a[j];
				maxloc = j;
			}
		}
		int temp = a[i];
		a[i] = max;
		a[maxloc] = temp;
	}
	scanf_s("%d", &x);
	for (i = 0; i < 9; i++) {
		if (x < a[i] && x > a[i + 1]) {
			printf("%d %d ", a[i],x);
			isplace = 1;
		}
		else printf("%d ", a[i]);
	}
	if (isplace == 1) {
		printf("%d",a[9]);
	}
	else {
		if (a[9] > x) printf("%d %d", a[9], x);
		else printf("%d %d", x, a[9]);
	}
	return 0;
}
//祁文青 6.7 找出最大元素并删除
int main7() {
	int a[10] = { 0 };
	int i, max = 0,maxloc;
	for (i = 0; i < 10; i++) {
		scanf_s("%d", &a[i]);
		if (max < a[i]) {
			max = a[i];
			maxloc = i;
		}
	}
	for (i = 0; i < 10; i++) {
		if (i == maxloc) {
			continue;
		}
		printf("%d ", a[i]);
	}
	return 0;
}
//祁文青 6.9 计算平均成绩
int main9() {
	int a[1000] = {0};
	int i = 1,sum = 0,count = -1,avg = 0;
	for (i = 1; i < 1000; i++) {
		a[i] = -1;
	}
	i = 1;
	while (a[i-1] >= 0) {
		scanf_s("%d", &a[i]);
		sum += a[i];
		i++;
		count++;
	}
	avg = sum / count;
	printf("avg = %d  count = %d\n", avg, count);
	for (i = 1; i < 1000; i++) {
		if (a[i] < 0) {
			break;
		}
		else if(a[i] < avg){
			printf("%d ", a[i]);
		}
	}
	return 0;
}
//祁文青 6.11 3行4列矩阵找最大值
int main11() {
	int a[3][4] = { 0 };
	int i, j, x, y;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 4; j++) {
			scanf_s("%d", &a[i][j]);
		}
	}
	int max = -32768;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 4; j++) {
			if (max < a[i][j]) {
				max = a[i][j];
				x = i;
				y = j;
			}
		}
	}
	printf("max[%d][%d] = %d", x, y, max);
	return 0;
}
//祁文青 6.12 一维数组输出10行杨辉三角
int main12() {
	int a[10] = {1,0,0,0,0,0,0,0,0,0};
	int i,j;
	printf("%d\n", 1);
	for (i = 1; i < 10; i++) {
		for (j = 9; j >= 0; j--){
			if (j != 0) a[j] += a[j - 1];
			if (a[j] != 0) printf("%d ", a[j]);
		}
		printf("\n");
	}
	return 0;
}
//谭浩强 5.1 筛选法求100以内的素数
int main13() {
	int a[100];
	int i,j;
	for (i = 0; i < 100; i++) {
		a[i] = i + 1;
	}
	a[0] = 0;
	for (i = 1; i < 99; i++) {
		if (a[i] != 0) {
			for (j = i+1; j < 100; j++) {
				if (a[j] != 0) {
					if (a[j] % a[i] == 0) {
						a[j] = 0;
					}
				}
			}
		}
	}
	for (i = 0; i < 100; i++) {
		if (a[i] != 0) printf("%d ", a[i]);
	}
	return 0;
}
//谭浩强 5.7 魔方阵
int main2_7() {
	int a[15][15] = { 0 };
	int i = 0, x; 
	printf("intput namber(3~15)");
	scanf_s("%d", &x);
	int j = 0, k = x / 2 +1;
	for (i = 1; i <= x * x; i++) {
		if (j < 0) j = x-1;
		if (k > x-1) k = 0;
		if (a[j][k] == 0) {
			a[j][k] = i;
		}
		else {
			j++;
			k--;
			if (j > x - 1) j = 0;
			if (k < 0) k = x - 1;
			while (a[j][k] != 0) {
				j++;
				if (j > x-1) j = 0;
			}
			a[j][k] = i;
		}
		j--;
		k++;
	}
	for (j = 0; j < x; j++) {
		for (k = 0; k < x; k++) {
			printf("%d ",a[j][k]);
		}
		printf("\n");
	}
	return 0;
}

//谭浩强 5.8 找出鞍点
int main() {
	/*
	srand((unsigned)time(NULL));
	int array[5][5];
	int i,j,k,found = 0,x = 5;
	for (i = 0; i < x; i++) {
		for (j = 0; j < x; j++) {
			array[i][j] = rand();
		}
	}
	*/
	int array[3][3] = {1,5,3,0,1,2,3,2,4};
	int i, j, k, found, max,maxj,x = 3;
	for (i = 0; i < x; i++) {
		max = array[i][0];
		maxj = 0;
		found = 1;
		for (j = 0; j < x; j++) {
			if (max < array[i][j]) {
				max = array[i][j];
				maxj = j;
			}
		}
		for (k = 0; k < x; k++) {
			if (max > array[k][maxj]) {
				found = 0;
			}
		}
		if (found) {
			break;
		}
	}
	if (found == 0) {
		printf("not found\n");
	}
	else {
		printf("find! array[%d][%d] = %d\n", i, maxj, array[i][maxj]);
	}
	for (i = 0; i < x; i++) {
		for (j = 0; j < x; j++) {
			printf("%d\t", array[i][j]);
		}
		printf("\n");
	}
	return 0;
}



