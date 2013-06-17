#include<stdio.h>
#include<string.h>
#include <ctype.h>
int main()
{
  int num[75];
	int N,K;
	char temp[75];
	char key[30][75],execute[30][75];
	int count = 0,t;
	int i,j,k;
	int max;
	while (scanf("%d%d",&N,&K) != EOF)
	{
		getchar();
		memset(num,0,sizeof(num));
		for (i=0;i<N;i++)
		{
			gets(key[i]);
		}

		for (j=0;j<K;j++)
		{
			gets(execute[j]);
		}
		t = 0;
		for (i=0;i<N;i++)
		{
			for (j=0;j<K;j++)
			{

				for (k=0;k<strlen(execute[j]);k++)
				{
					if (isalpha(execute[j][k]))
					{
						temp[t++] = tolower(execute[j][k]);
					} 
					else
					{
						temp[t] = '\0';
				     //	printf("%s",temp);
						if (!strcmp(key[i],temp))
						{
							num[j]++;
						}
						t= 0;
					}
				}
			}
		}

		max = 1;  
		for( i = 0; i < K; i++ )  
			if( num[i] >= max )  
				max = num[i];  
		printf( "Excuse Set #%d\n", ++count );  
		for( i = 0; i < K; i++ )      
			if( num[i] == max )  
				printf( "%s\n", execute[i] );  
		printf( "\n" );  


	}

	return 0;

}
