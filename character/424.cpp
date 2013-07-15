#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char ch[110];
int a[110];
int s[110];

int main()
{   
  memset(s,0,sizeof(s));
    while(scanf("%s",&ch) && strcmp(ch,"0"))
	{
		for(int i=0;i<106;i++)
		{
			a[i] = 0;
		}
		int l = strlen(ch);
		for(int i=0;i<l;i++)
		{
			a[i] = ch[l-i-1] - '0';
		}

		for(int i=0;i<106;i++)
		{
			s[i] += a[i];
		}
		for(int i=0;i<106;i++)
		{
			s[i+1] += s[i] / 10;
			s[i] %= 10; 
		}

	}
	 int end = 105;  
    while ( end >= 1 && !s[end] ) end --;  
    while ( end >= 0 ) printf("%d",s[end --]);  
    printf("\n");  
	return 0;
}
