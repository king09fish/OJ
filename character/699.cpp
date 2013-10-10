#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 110;

int pos[MAXN];

/*
5 7 -1 6 -1 -1 3 -1 -1
8 2 9 -1 -1 6 5 -1 -1 12 -1
-1 3 7 -1 -1 -1
-1 699
*/

void dfs(int mid, int n, int *pos)
{
	if(n!=-1)
	{
		pos[mid]+= n;
		scanf("%d",&n);
		dfs(mid-1,n,pos);
		scanf("%d",&n);
		dfs(mid+1,n,pos);
	}
}
int main()
{	
	int n,mid;
	int cnt = 1;
	int left,right;
    while(scanf("%d",&n) != EOF && n>0)
	{
		memset(pos,0, sizeof(pos));
		mid = 50 ;  
        dfs(mid,n,pos);  
        printf("Case %d:\n",cnt++);
		left = 0;right = MAXN;
		while(!pos[left])left++;
		while(!pos[right])right--;

		for(int i=left;i<=right;i++)
		{
			  printf("%d",pos[i]);  
            if (i != right)  
                printf(" ");  
		}
		printf("\n\n");
	}
    return 0;
}
