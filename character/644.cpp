#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int num;
char ch[100][11];
int comp(const void* a, const void* b )
{
  return strlen((char *)a) - strlen((char *)b);
}

bool find()
{
	qsort(ch,num,sizeof(ch[0]),comp);

	for(int i=0;i<num;i++)
	{

		for(int j=i;j<num;j++)
		{
			if(i == j)continue;
			if(strstr(ch[j],ch[i])-ch[j] == 0)
			return false;
		}
	}
	return true;
}

int main()
{
	num = 0;
	int cas = 1;
	while(scanf("%s",ch[num]) != EOF)
	{
		if(ch[num][0] == '9')  
       {  
                        
          if(find())  
             printf("Set %d is immediately decodable\n",cas++);  
          else  
             printf("Set %d is not immediately decodable\n",cas++);  
          num=0;                 
       }  
   else  {
          num++;    
   }

	}
	return 0;
}
