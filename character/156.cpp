
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
char tmp[20];
char str[100][20];
char ret[100][20];
int cmp_str(const void* a,const void* b)
{
  return strcmp((char *)a,(char *)b);
}

int cmp_char(const void *a, const void *b)
{

	return *(char*)a-*(char*)b;
}
int main()
{

	int str_num = 0;
	while(scanf("%s",&tmp) &&tmp[0] != '#')
	{
		strcpy(str[str_num++],tmp);
	}
	qsort(str,str_num,sizeof(str[0]),cmp_str);
		for(int i=0;i<str_num;i++)
	{
		printf("%s\n", str[i]);
	}
	for(int i=0;i<str_num;i++)
	{
		int len = strlen(str[i]);
		for(int j=0;j<len;j++)
		{
			if(str[i][j] >= 'A'&& str[i][j]<='Z')
			{
				ret[i][j] = tolower(str[i][j]);
			}else
			{
				ret[i][j] = str[i][j];
			}
		}
		qsort(ret[i], len, sizeof(char), cmp_char);

	}
		printf("=========");
	for(int i=0;i<str_num;i++)
	{
		printf("%s\n", ret[i]);
	}

	

	printf("the result is ====");

	for(int i=0;i<str_num;i++)
	{
		for(int j=0;j<str_num;j++)
		{
			if(i!=j)
			{
				if(strcmp(ret[i],ret[j]) == 0)
				{
					printf("%s\n",ret[i]);
				}

			}
		}
	}

	return 0;
}
