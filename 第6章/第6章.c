/***************************************�����嵥6.4****************************************/
#include<stdio.h>
int main(void)
/*
	{
	int n;
	while(scanf("%d",&n)==1)
			;
	printf("%d\n",n);
	return 0;
	}
*/

/****************************************����***********************************************/

/*
	{
	int num;
	scanf("%d",&num);
	while(num++<8)
		printf("\nnum=%d",num);
	return 0;
	}
*/   

/****************************************6.15 ��ϰ��*****************************************/
/*
	{
	char ch;
	scanf("%c",&ch);
	for(ch='$';ch!='g';scanf("%c",&ch))
		putchar(ch);
	return 0;
	}
*/

/*****************************************6.16 �����ϰ***************************************/


/*****************************************��11��**********************************************/

/*
	{
	int Pow(int x);
	double i,s;
	int n,j;
	printf("Enter the number of terms you want ______\b\b\b\b\b\b:");
	while(scanf("%d",&n)==1)
		{
		for(i=1.0,j=0,s=0;j<n;j++,i=1.0/(j+1))
			{
			i*=Pow(j);
			s+=i;
			}
		printf("sum=%.12f when term=%d",s,n);
		printf("\n");
		printf("q(to quit)\n");
		printf("Enter the number of terms you want ______\b\b\b\b\b\b:");
		}
	printf("Done!");
	getchar();
	getchar();
	getchar();
	return 0;
	}

	int Pow(int x)
	{
	int m,power=1;
	x%=2;
	for(m=0;m<x;m++,power*=-1)
		     ;
	return power;
	}
*/


/******************************************��15��*********************************************/

	
	{
	const double PRINCIPAL=100.0;
	double s1=PRINCIPAL;           //double s1,s2;
	double s2=PRINCIPAL;
	int i=1;
	/*s1=s2=PRINCIPAL;(����˫�ظ�ֵֻ����"int i=1;"�²ſɱ���ɹ���������)*/
	printf("           Daphne                Deirdre\n");
	printf("Year\n\n");
	
	do{
		s1+=0.1*PRINCIPAL;
		s2*=1.05;
		printf("%02d",i);
		printf("        %.2f$               %.2f$\n",s1,s2);
		i++;
		}while(s1>s2);
	
	getchar();
	getchar();
	getchar();
	return 0;
	}


/******************************************��16��*********************************************/

/*
	{
	const double PRINCIPAL=1000000.0;
	const double PAY=100000.0;
	double sum=PRINCIPAL;
	int n=1;
	printf("Year       Chuckie Lucky's account          payment          remaining sum\n");
	printf("%2d              %13.2f       %13.2f          %13.2f\n",0,sum,0.0,sum);
	while(sum>PAY)
		{
		sum*=1.08;
		printf("%2d              %13.2f          ",n,sum);
		sum-=PAY;
		printf("%13.2f       %13.2f\n",PAY,sum);
		n++;
		}
	printf("%2d              %13.2f          ",n,sum*1.08);
	printf("%13.2f       %13.2f\n",sum*1.08,0.0);
	getchar();
	getchar();
	getchar();
	return 0;
	}
		
*/