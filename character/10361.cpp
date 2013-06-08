#include<stdio.h>
#include<string.h>
#define  max 110

void getstr(char s[]);
int main()
{

  int n;
	scanf("%d", &n);
	char s1[max],s2[max],s3[max],s4[max],s5[max],secondline[max],c;
	  c = getchar();  
	while(n--)
	{
		getstr(s1);  
		getstr(s2);  
		getstr(s3);  
		getstr(s4);  
		getstr(s5);  
		gets(secondline);  
		secondline[strlen(secondline) - 3] = '\0';  
		printf("%s%s%s%s%s\n",s1,s2,s3,s4,s5);  
		printf("%s%s%s%s%s\n",secondline,s4,s3,s2,s5);  

	}
	return 0;
}




void getstr(char s[])
{
  for (int i=0;i<max;i++)
  {
		if ((s[i] = getchar()) == '<' || s[i] == '>' || s[i] == '\n' )
		{
			s[i] = '\0';
			break;
		}
		
  }
}
