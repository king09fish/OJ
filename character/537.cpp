#include<stdio.h>
#include<string.h>

int main()
{
  int n;
  double P,U,I,C;
  int i =0;
  int index = 1;
  char str[1001];
  while (scanf("%d\n", &n) != EOF)
  {
    while(n--)
	  {

		P = 0;
		U =0;
		I = 0;
		C= 1;
		gets(str);
		for (i=0;i<strlen(str);)
		{
			 
			if (str[i] == 'P' && str[i+1] == '=')
			{
				i = i + 2;
				while (str[i] >= '0' && str[i] <= '9')
				{
					P = P * 10 + str[i] - '0';
					i++;
				}
				if (str[i] == '.')
				{
					i++;
					while (str[i] >= '0' && str[i] <= '9')
					{
						C = C * 0.1;
						P = P + C * (str[i] - '0');
						i++;
					}
				}
				C = 1;
				
				if(str[i] == 'k'){  
					P *= 1000;  
					i++;  
				}  
				else if(str[i] == 'm'){  
					P /= 1000;  
					i++;  
				}  
				else if(str[i] == 'M'){  
					P *= 1000000;   
					i++;  
				}  


			}




			if (str[i] == 'I' && str[i+1] == '=')
			{
				i = i + 2;
				while (str[i] >= '0' && str[i] <= '9')
				{
					I = I * 10 + str[i] - '0';
					i++;
				}
				if (str[i] == '.')
				{
					i++;
					while (str[i] >= '0' && str[i] <= '9')
					{
						C = C * 0.1;
						I = I + C * (str[i] - '0');
						i++;
					}
				}
				C = 1;

				if(str[i] == 'k'){  
					I *= 1000;  
					i++;  
				}  
				else if(str[i] == 'm'){  
					I /= 1000;  
					i++;  
				}  
				else if(str[i] == 'M'){  
					I *= 1000000;   
					i++;  
				}  


			}

			


			if (str[i] == 'U' && str[i+1] == '=')
			{
				i = i + 2;
				while (str[i] >= '0' && str[i] <= '9')
				{
					U = U * 10 + str[i] - '0';
					i++;
				}
				if (str[i] == '.')
				{
					i++;
					while (str[i] >= '0' && str[i] <= '9')
					{
						C = C * 0.1;
						U = U + C * (str[i] - '0');
						i++;
					}
				}
				C = 1;

				if(str[i] == 'k'){  
					U *= 1000;  
					i++;  
				}  
				else if(str[i] == 'm'){  
					U/= 1000;  
					i++;  
				}  
				else if(str[i] == 'M'){  
					U *= 1000000;   
					i++;  
				}  


			}

			i++;
		}


		printf("Problem #%d\n",index);  
		if(P > 0 && I > 0){  
			printf("U=%.2lfV\n",P / I);  
		}  
		else if(P > 0 && U > 0){  
			printf("I=%.2lfA\n",P / U);  
		}  
		else if(U > 0 && I > 0){  
			printf("P=%.2lfW\n",U * I);  
		}  
		printf("\n");  

		index++;  

	  }
  }

return 0;
}
