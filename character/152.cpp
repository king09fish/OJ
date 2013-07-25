#include<stdio.h>
#include<math.h>
#include <string>
#define  max 550
struct treepoint
{
  int x;
	int y;
	int z;
}trees[max];

int caulate(int i,int j);

int result[11];

int main() {

	int a,b,c;
	int count = 0;
	memset(trees,0,sizeof(trees));
	memset(result,0,sizeof(result));

	while(scanf("%d %d %d",&a, &b, &c) == 3 && a+b+c!= 0)
	{
		trees[count].x = a;
		trees[count].y = b;
		trees[count].z = c;
		count++;
	}

	for(int i = count -1;i>=0;i--)
	{
		int min = 500;
		for (int j=count-1;j>=0;j--)
		{
			if (i!=j)
			{
				int distance = caulate(i,j);
				if (distance < min)
				{
					min = distance;
				}
			}


		}
		if(min < 10)  
		 result[min]++;  

	}
	for(int i = 0; i < 10; i++)  
	{  
	printf("%4d", result[i]);  
	}  
	printf("\n");  

	return 0;

}

int caulate(int i, int j)
{
	double x = trees[i].x - trees[j].x;
	double y = trees[i].y - trees[j].y;
	double  z = trees[i].z - trees[j].z;

	float result = sqrt(x*x+y*y+z*z);

	return floor(result);  
}
