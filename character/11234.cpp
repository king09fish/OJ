
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define N 10000+100
char s[N];
int stack[N], l[N],r[N],queue[N];
char re[N];
int main() {
 
  int n;
  scanf("%d", &n);
  getchar();
  int top;
  while(n--)
  {
	gets(s);
	int length = strlen(s);
	top = 0;
	for(int i=0;i<length;i++)
	{
		if(islower(s[i]))
		{
			stack[top++] = i;
			l[i] = -1;
			r[i] = -1;
		}else
		{
			l[i] = stack[top -1];
			r[i] = stack[top-2];
			top-= 2;
			stack[top++] = i;
		}


	}
	re[length--] = '\0';
	int begin = 0;
	queue[begin++] = stack[top-1];
	int head = 0;
	int node = 0;
	while(head != begin)
	{
		node = queue[head];
		re[length--] = s[node];
		if(r[node] != -1)queue[begin++] = r[node];
		if(l[node] != -1)queue[begin++] = l[node];
		head++;
	}

	puts(re);

  }




  return 0;
}
