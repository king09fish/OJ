#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_INT  2147483647

char c1[100],c2[100];
int main()
{   
   char c;
  while(scanf("%s %c %s",c1,&c,c2) == 3)
	{
		double a, b;

        a = atof(c1);

        b = atof(c2);
		//printf("%f", a);

        if (a > MAX_INT) printf("first number too big\n");

        if (b > MAX_INT) printf("second number too big\n");

        if (c=='+' && a+b > MAX_INT)printf("result too big\n");

        if (c=='*' && a*b > MAX_INT) printf("result too big\n");

	}
		return 0;
}
