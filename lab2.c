#include <stdio.h>
#include <math.h>
#include <stdlib.h>

long double solution (long double x, long double e, long int* n)
{
	long double p = 1, p1 = 0, pr = x * x, sum = 1;
	int i = 1;
	*n = 0;
	while (fabsl(p1 - p) > e)
	{
		p1 = p;
		p *= ((2 * i + 1) * pr) / (2 * i);
		sum += p;
		*n += 1;
		++i;
	}
	return sum;
}

long double correct_input_x (long double* x)
{
	*x = 0;
  	printf ("Введите х (|x|<1):\n");
  	int scan = scanf ("%Lf", x);
 	if (scan < 1 || *x <= -1 || *x >= 1)
 	{
 		int b = scanf("%*[^\n]");
 		if (b < 0)
 		{
 			printf ("Завершение программы\n");
 			return 2;
 		}
 		printf("Некорректный ввод!\n");
 		return 1;		
 	}
 	return 0;
}

long double correct_input_e (long double* e)
{
	*e = 0;
  	printf ("Введите точность:\n");
  	int scan = scanf ("%Lf", e);
 	if (scan < 1 || *e <= 0 || *e >= 1)
 	{
 		int b = scanf("%*[^\n]");    
 		if (b < 0)
		{
 			printf ("Завершение программы\n");
 			return 2;
 		}
 		printf("Некорректный ввод!\n");
 		return 1;		
 	}
 	return 0;
}

int main ()
{
	long double x = 0, e = 0, sum, j, l; 
 	int cix = 1, cin = 1; 
 	long int n = 0;
    while (cix == 1)
    {
    	cix = correct_input_x (&x);
    }
    if (cix == 2)
    {
       	exit (0);
    }    
    while (cin == 1)
    {
    	cin = correct_input_e (&e);
    }	
    if (cin == 2)
    {
    	exit (0);
    }
 	e = fabsl(e);
 	l = (1 - x*x) * sqrt( 1 - x * x);
 	j = 1/l;
 	sum = solution (x, e, &n);
 	printf("Значение функции: %.20Lf\n", sum );
 	printf("Значение дроби: %.20Lf\n", j );
 	printf("Количество членов ряда: %ld\n", n );
 	return 0;
}
