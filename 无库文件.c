// 祁文青8.8 整数转换成相应的字符
void fun(int a,char* p)
{
	int i = 0,count = 1;
	if (a < 0)
	{
		p[0] = '-';
		a *= -1;
	}
	int x = a;
	while (x > 10)
	{
		x /= 10;
		count++;
	}
	for (i = 0; i < count; i++)
	{

		p[count - i - 1] = a % 10 + '0';
		a /= 10;
	}
}
int main()
{
	char str[100] = "";
	int a = 1234;
	fun(a,str);
	return 0;
}