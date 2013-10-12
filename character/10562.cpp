#include<stdio.h>
#include<string>

char str[205][205];
int t;

void dfs(int x, int y)
{
	int i,j;
	for(i=y;str[x][i] =='-';i++)
	{
		if(str[x+1][i] != '-'&&str[x+1][i] != '\0')
		{
			printf("%c(", str[x+1][i]);
			if(x+1<t &&str[x+2][i] == '|')
			{
				for(j=i;j&&str[x+3][j-1] == '-';j--);
				dfs(x+3,j);
			}
			printf(")");


		}


	}


}

int main()
{
	int n;
	scanf("%d", &n);
	getchar();

	while(n--)
	{
		t = 1;
		memset(str,0,sizeof(str));
		while(1)
		{

			gets(str[t++]);
			if(str[t-1][0]  =='#') break;
		}

		t--;
		if(t== 1)
		{
			printf("()");
		}
		else 
		{
			int i,len =strlen(str[1]);
			for(i=0;i<len;i++)str[0][i] = '-';

			printf("(");
			dfs(0,0);
			printf(")");

		}


	}
	return 0;
}


