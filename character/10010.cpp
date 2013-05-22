#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char map[60][60];
char aim[30][60];
int dir[8][2]={ {1,0},{-1,0},{0,1},{0,-1},{1,1},{-1,1},{1,-1},{-1,-1} };
bool fun(char *,int,int);
int main()
{
	int t,t_cnt = 0;
	scanf("%d",&t);
	while(t--)
	{
		int i,j,m,n;
		if (++t_cnt == 1)
		{
			printf("\n");
		}
		scanf("%d %d",&n,&m);
		for(i=0;i<n;i++)
		{
			scanf("%s",map[i]);
			for(j=0;j<m;j++)
			{
				map[i][j] = tolower(map[i][j]);
			}
		}
		int k ;
		scanf("%d",&k);
		for (i=0;i<k;i++)
		{
			scanf("%s", aim[i]);
			int len = strlen(aim[i]);
			for (j=0;j<len;j++)
			{
				aim[i][j] = tolower(aim[i][j]);
			}
			
		}

		for (i=0;i<k;i++)
		{
			bool flag = false;
			for (int x=0;x<n&&!flag;x++)
			{
				for (int y=0;y<m&&!flag;y++)
				{
					if (fun(aim[i],x,y))
					{ 
						flag = true;  
						printf("%d %d\n",x+1,y+1);  
					}
					
				}
				
			}
			
		}
		
		
		
	}
	

return 0;
}

bool fun(char *a,int x,int y)
{

	int len = strlen(a);
	if (map[x][y] != a[0])
	{
		return false;
	}
	for ( int i=0;i<8;i++)
	{
       int xx = x;
	   int yy = y;
	   bool flag = true;
	   for (int j=1;j<len;j++)
	   {
		   xx += dir[i][0];
		   yy += dir[i][1];
		   if (map[xx][yy] != a[j])
		   {
			   flag = false;
			   break;
		   }		
			
	   }
	   if (flag)
	   {
		   return true;
	   }
	   
	}
	return false;	
}