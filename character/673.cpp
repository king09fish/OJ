#include<stdio.h>
#include <string>
int top = 0;
char stack[128];

int match(char &a, char &b)
{
	if ( (a == '{' && b == '}') || (a == '[' && b == ']'))
{
	return 1;
}else
	{
		return 0;
	}

}

int main()
{


	char input[128] = {0};
	
	int n;
	scanf("%d\n", &n);
	
	while(n--)
	{
		memset(input,0,sizeof(char)*128);
		gets(input);

		int len = strlen(input);
		printf("%d",len);
		for ( int i=0;i<len;i++)
		{
			if (input[i] == '[' || input[i] == '{')
			{
				stack[top++] = input[i];
			}else
			{	
				if (match(stack[top - 1], input[i]))
				{
					top--;
				}else

				{
					stack[top++] = input[i];
				}
			
			}
				
			}

		
		if (top == 0)
		{
			printf("yes");
		}else
		{
			printf("no");
		}

		}

	

	return 0;


}
