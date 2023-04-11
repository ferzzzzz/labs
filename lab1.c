#include <stdio.h>
#include <stdlib.h>

int sum(int x)
{
	int sum = 0;
	while (x)
	{ 
		sum += x%10;
		x /= 10;
	}
	return sum*sum*sum;
}

void solution (int f, int l)
{
	printf("Numbers from range:\n");
	int i, flag = 0;
	for (i=f; i <= l; ++i)
	{
		if (sum(abs(i)) == i*i)
		{
			printf("%d\n", i);
			flag = 1;
		}
	}

	if (flag == 0) printf("No answer!\n");
	
}
int main()
{
	int c1, c2;

	printf("Write two numbers:\n");
	scanf("%d%d", &c1, &c2);
	int f, l;
	if (c1<=c2)
	{
		f = c1;
		l = c2;
	}
	else
	{
		f = c2;
		l = c1;
	}
	solution(f, l);
	return 0;
}
