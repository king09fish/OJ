#include<stdio.h>
#include<math.h>
#include <string>
#include <iostream>
using namespace std;

int main()
{
 



  int i,j;

	string str;
	bool isok = true;
	string str1,str2;
	while(getline(cin,str))
	{
		str1 = str.substr(0,6);
		str2 = str.substr(6,12);
		for(i=0;i<3;i++)
		{
			bool result = false;
			for(j=0;j<6;j++)
			{
				if (str1[i] == str2[j] && str1[5-i] == str2[5-j])
				{
					str2[j] ='0';
					str2[5-j] = '0';
					result = true;
					break;
				}
			}
			if (!result)
			{
				isok = false;
				break;
			}

		}

		if (isok)
		{
			printf("ok\n");
		}else
		{
			printf("not\n");
		}
	}

	return 0;
}
