#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int convert(char r[])
{
  int dot = 0;
  int len_r = strlen(r);
	for (int i=0;i<len_r;i++)
	{
		if (r[i] == '.')
		{
			dot = i;
		}
	}
	for(int i= dot;i<len_r-1;i++)
	{
		r[i] = r[i+1];
	}

	r[len_r-1] = 0;
	return atoi(r);
}

int main ()
{

	char input[12];
	while(gets(input))
	{

		char r[8];
		int n;
		sscanf(input,"%s %d",r,&n);
		int result[100];
		int len_r = strlen(r);
		int index = 0;
		while(r[index] == '0')
		{
			for (int i = index + 1;r[i] != 0;i++)
			{
				r[i-1] = r[i];
			}
			r[len_r - 1] = 0;
			len_r --;
		}
		index = 0;

		while(r[len_r - 1] == '0')
		{
			r[len_r - 1] = 0;
			len_r --;
		}
		int dot;
		index = 0;
		for (int i= len_r -1;i>=0;i--)
		{
			if (r[i] == '.')
			{
				dot = len_r - i -1;
			} 
			else
			{
				result[index++] = r[i] -'0';
			}
		}

		int number = convert(r);
		int j;
		for (int i=1;i<n;i++)
		{
			int carry = 0;
			for (j =0;j<index;j++)
			{
				carry = number * result[j] +carry;
				result[j] = carry % 10;
				carry = carry /10;
			}
			while (carry)
			{
				result[j++] = carry%10;
				carry = carry/10;
			}
			index = j;
		}
		dot = dot * n;
		dot = index - dot;
		while(dot < 0)
		{
			result[index++] = 0;
			dot++;
		}

		for ( int i = index - 1; i >= 0; i-- ) {
			if ( dot-- == 0 )
				printf (".");
			printf ("%d", result [i]);
		}
		printf ("\n");

	}
}
