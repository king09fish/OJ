#include<stdio.h>
#include<math.h>
#include <string>
#define MaxColoum 65
#define MaxRow  100

char filename[MaxRow][MaxColoum];
int cmp_str(const void* a, const void* b)
{
  return strcmp((char *)a,(char *)b);
}
int main() {
  
	int n;
	int maxlength = 0;
	while(scanf("%d", &n) != EOF)
	{
		for (int i=0;i<n;i++)
		{
			scanf("%s", filename[i]);
			if (strlen(filename[i]) > maxlength)
			{
				maxlength = strlen(filename[i]);
			}
		}

		qsort(filename,n ,sizeof(filename[0]), cmp_str);
		for(int i=0;i<60;i++)
		{
			putchar('-');
		}
		putchar('\n');
		int times = 60/(maxlength+2);

		int line = (int)ceil(1.0*n/times);
		printf("times = %d \n", times);
		printf("line = %d \n", line);
		printf("maxlength = %d \n", maxlength);
		printf("n is = %d\n",n);
		for(int i=0;i<line;i++)
		{
			for(int j=0;j<times;j++)
			{
				int t = i + j*line;
				if(t<=n)
				{  
					if(j!=times-1)
					{
						printf("%s",filename[t]);
						int len = maxlength - strlen(filename[t]) + 2;
						while(len--)putchar(' ');
					} else
					{
							printf("%s",filename[t]);
							printf("\n");
					}

				}

			}

		}



	}

	return 0;
}
