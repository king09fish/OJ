#include<stdio.h>
#include <string>

int letter[26][2];
int main()
{


	int n;
	scanf("%d",&n);
	getchar();
	char c;
	for ( int i =0;i<n;i++)
	{
		scanf("%c %d %d",&c, &letter[i][1], &letter[i][2]);
		getchar();
		
	}
	
//	printf("kkkk");
	char str[20] ={0};
	int value[20];
	while(true)
	{
		memset(str,0,sizeof(char));
		memset(value,0,sizeof(int));
		gets(str);
		
		int length = strlen(str);
		if (length == 1)
		{
			printf("the length is zero\n");
			continue;
		}
		int count_times = 0;
		int count = 0;
		printf("%s \n", str);

		for ( int i=0;i<length;i++)
		{
			if (str[i] == '(' || str[i] == ')')
			{
				if (str[i] == ')')
				{

					for ( int j=count_times-1;j>0;j--)
					{
						int tmp = value[j];
						int tmp1 = value[j-1];
						if (letter[tmp1][2] != letter[tmp][1])
						{
							printf("error\n");
							break;
						}
						printf("%d %d %d \n",letter[tmp1][1] , letter[tmp][2] , letter[tmp][2]);
						count +=letter[tmp1][1] * letter[tmp][2] * letter[tmp][1];
						letter[tmp1][2] = letter[tmp][2];
						letter[tmp][2] = 0;
						letter[tmp][1] = 0;
					
			    	}
					count_times = 1;
				}
			}
			else
			{
				value[count_times] = str[i] -'A';
			//	printf("the value is %c \n", str[i]);
				count_times ++;
			}
		}
		

	
		printf("%d", count);
	}
	return 0;


}
