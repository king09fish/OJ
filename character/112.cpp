//利用二叉树的递归定义进行递归访问, AC:0.069s
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>


using namespace std;


int n;
int sum;
bool isfound;
void ignorSpace()
{
	char input;
	while(scanf("%c",&input))
	{
		if(isspace(input))continue;
		return;
	}
}

int get_num()
{
	while(true)
	{
		ignorSpace();
		int value;
		if(scanf("%d", &value) != 1){ ignorSpace();return 0;};
		sum+= value;
		int left = get_num();
		int right = get_num();
		if(!left && !right && sum == n) {isfound = true; return 1;}
		ignorSpace();
		sum -= value;
		return 1;

	}

}
int main()
{
	/*-
	while(scanf("%d",&n) == 1)
	{
		sum = 0;
		isfound = false;
		get_num();
		 if(isfound) printf("yes\n");  
        else printf("no\n");  

	}*/

	int a;
	char b;
	scanf("%d", &a);
	//b = getchar();
	scanf("%c",&b);
	printf("%c",b);
	return 0;

}
