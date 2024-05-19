/*****************************程序清单9.12 简约版*********************************/

/*
#include<stdio.h>
int main(void)
	{
	int pooh=5;
	printf("In main(),pooh=%d and &pooh=%p",pooh,&pooh);
	getchar();
	getchar();
	return 0;
	}
*/

/*************************9.11.1 编程****************************/

/*
#include<stdio.h>
double min(double x,double y);


int main(void)
	{
	double a,b;
	a=3.0;
	b=6.0;
	printf("min digit is %.2f\n",min(a,b));
	return 0;
	}
double min(double x,double y)
	{
	return x>y?y:x; 
	}
*/

/**************************9.11.4 编程*****************************/

/*
#include<stdio.h>
double average(double x,double y);
int main(void)
	{
	double a,b;
	b=6.0;
	a=3.0;
	printf("average is %.2f",average(a,b));
	return 0;
	}
double average(double x,double y)
	{
	return(2/(1/x+1/y));
	}
*/

/**************************9.11.6 编程*****************************/

/*
#include<stdio.h>
void alpha(void);
int main(void)
	{
	alpha();
	return 0;
	}
void alpha(void)
	{
	char ch;
	while((ch=getchar())!=EOF)
		{
		if( (ch>='a' && ch<='z') || 
			(ch>='A' && ch<='Z') )
			{
			printf("This is a alpha.");
			printf("Its number in alphabet");
			printf(" is %d\n",ch>='a'?ch+1-'a':ch+1-'A');
			while((ch=getchar())!='\n')
				continue;
			}
		else 
			{
			printf("This is not a alpha\n");
			if(ch=='\n')
				continue;
			while((ch=getchar())!='\n')
				continue;
			}
		}
	}
*/

/**************************9.11.7 编程*******************************/

/*
#include<stdio.h>
double power(double n,int p);
int main(void)
	{
	double x,xpow;
	int exp;

	printf("Enter a number and the positive integer power");
	printf(" to which\nthe number will be raised.Enter q");
	printf(" to quit.\n");
	while(scanf("%lf%d", &x, &exp)==2)
		{
		xpow=power(x,exp);
		printf("%.3g to the power %d is %.5g\n",x,exp,xpow);
		printf("Enter the next pair of numbers or q to quit.\n");
		}
	printf("Hope you enjoyed this power trip --bye!\n");
	return 0;
	}

double power(double n,int p)
	{
	double pow=1;
	int i;
	if(n==0)
		pow=0;
	else 
		if(p>0)
			{
			for(i=0;i<p;i++)
				pow *= n;
			}
		else
			if(p<0)
				{
				for(i=0;i<-p;i++)
					pow *= n;
				pow=1/pow;
				}
	return pow;
	}
*/

/****************************9.11.8 编程*****************************/

/*

#include<stdio.h>
double power(double n,int p);
int main(void)
	{
	double x,xpow;
	int exp;

	printf("Enter a number and the positive integer power");
	printf(" to which\nthe number will be raised.Enter q");
	printf(" to quit.\n");
	while(scanf("%lf%d", &x, &exp)==2)
		{
		xpow=power(x,exp);
		printf("%.3g to the power %d is %.5g\n",x,exp,xpow);
		printf("Enter the next pair of numbers or q to quit.\n");
		}
	printf("Hope you enjoyed this power trip --bye!\n");
	return 0;
	}

double power(double n,int p)
	{
	double pow=1;
	if(n==0)
		pow=0;
	else if(p>0)
		pow=power(n,p-1) * n;
	else if(p<0)
		pow=power(n,-p-1) * n;
	if(p<0)
		pow=1/pow;
	printf("%.5g\n",pow);
	return pow;
	}

*/
/******************************9.11.9 编程*******************************/

/*
#include<stdio.h>
void to_base_n(unsigned long s,unsigned int n);
int main(void)
	{
	unsigned long number;
	unsigned int system;
	printf("Enter two integers (q to quit): \n");
	printf("The first one is the number to be dealt\n");
	printf("The second one is the system(only 2 to 10):\n");
	while(scanf("%lu %u",&number,&system)==2)//只能写成 "%lu",不能写成"%ul".
		{
		printf("%d equivalent: ",system);
		to_base_n(number,system);
		putchar('\n');
		printf("Enter two integers (q to quit): \n");
		printf("The first one is the number to be dealt\n");
		printf("The second one is the system(only 2 to 10):\n");
		}
	printf("Done.\n");
	return 0;
	}
void to_base_n(unsigned long s,unsigned int n)
	{
	int r;
	r = s % n;
	if(s >= n)
		to_base_n(s / n,n);
	putchar('0' + r );
	return;
	}
*/

/****************************9.11.10 编程*****************************/


#include<stdio.h>
void Fibonacci(unsigned int n);
int main(void)
	{
	unsigned int years;
	printf("Enter the years :\n");
	while(scanf("%u",&years)==1)
		{
		if(years==1 || years==2)
			printf("Result is 1\n");
		else if(years==0)
			break;
		else
			Fibonacci(years);
		printf("Enter the years :\n");
		}
	printf("Done.\n");
	return 0;
	}
void Fibonacci(unsigned int n)
	{
	unsigned int i;
	unsigned int first,second,now;
	first=1;
	second=1;
	for(i=0;i<n-2;i++)
		{	
		now = first + second;
		first = second;
		second = now;
		}
	printf("Result is %u\n",now);
	return;
	}
