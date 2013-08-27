#include<stdio.h>
#include <string>
#include<cstring>
#include<map>
#include<list>
#define  Max 1010
using namespace std;

map<int,int> teammap;
list<int> ls;
list<int>::iterator it[Max];
int cnt[Max];
void insert(int x)
{
	if (ls.size() == 0)
	{
		ls.push_back(x);
		it[teammap[x]] = ls.begin();
	}else{
        

		int index = teammap[x];

		if (it[index] == ls.end())
		{
			ls.push_back(x);
			it[index] = ls.end();
			it[index]--;
		}else
		{
			list<int>::iterator iter = it[index];
			ls.insert(++iter,x);
			it[index]++;
		}
	}
}

int main()
{


	

    int n;
	int Case =0;
	int x,m;
	char str[15];
	while(scanf("%d",&n) && n)
	{
		ls.clear();
		teammap.clear();
		printf( "Scenario #%d\n", ++Case);
		for ( int i=1;i<Max;i++)
		{
			it[i] = ls.end();
		}
	
		memset(cnt,0, sizeof(cnt));
		for (int i=1;i<=n;i++)
		{
			scanf("%d", &m);
			while (m--)
			{
				scanf("%d", &x);
				teammap[x] = i;
			}
			
		}
		while (scanf("%s", str) && str[0] != 'S')
		{
			if (str[0] == 'E')
			{
				scanf("%d", &x);
				insert(x);
				cnt[teammap[x]]++;

			}else
			{
				int front = ls.front();
				ls.pop_front();
				printf("%d \n", front);
				cnt[teammap[front]]--;
				if (cnt[teammap[front]] == 0)
				{
					it[teammap[front]] = ls.end();
				}
			}
		}


	puts("");
	}
	return 0;


}
