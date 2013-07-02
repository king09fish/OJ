#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char d[1000010][210] = {'\0'};
int n = 0, len = 0;

int cmp_string(const void *_a, const void *_b)
{
  char *a = (char *) _a;
	char *b = (char *) _b;
	return strcmp(a, b);
}

int main()
{

	
	char ch;
	while(true)
	{
		if ((ch=getchar()) == EOF)
		break;
		if (isalpha((ch)))
		{
			d[n][len++] = tolower(ch);
		}else
		{
			if (isalpha(d[n][0]))
			{
				d[n++][len] = '\0';
				len = 0;
			}
		}
	}
	
	qsort(d,n,sizeof(d[1]), cmp_string);
	for (int i=0;i<n;i++)
	{
		if (strcmp(d[i],d[i+1]))
		{
			printf("%s\n",d[i]);
		}
	}
	return 0;
}
