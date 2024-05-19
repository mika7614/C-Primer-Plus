/************************************************程序清单7.3***************************************************/

/*
#include<stdio.h>
#include<ctype.h>
int main(void)
	{
	char ch;

	while((ch=getchar())!='\n')
		{

		if(isalpha(ch))
			putchar(ch+1);
		else 
			putchar(ch);
		}
	putchar(ch);
	return 0;
	}
*/

/************************************程序清单7.5**********************************/

/*                    经过试验，不含有头文件<stdbool.h>，不支持_Bool型变量

#include<stdio.h>
#include<stdbool.h>
int main(void)
	{
	unsigned long num;
	unsigned long div;
	bool isPrime;
	
	printf("Please enter an integer for analysis:");
	printf("Enter q to quit.\n");
	while(scanf("%lu",&num)==1)
		{
		for(div=2,isPrime=true;(div*div)<=num;div++)
			{
			if(num % div==0)
				{
				if((div*div)!=num)
					printf("%lu is divisible by %lu and %lu.\n",
					num,div,num/div);
				else 
					printf("%lu is divisible by %lu.\n",num,div);
				isPrime=false;
				}
			}
		if(isPrime)
			printf("%lu is prime.\n",num);
		printf("Please enter an integer for analysis:");
		printf("Enter q to quit.\n");
		}
	printf("Bye!\n");
	return 0;
	}

*/

/********************************7.12 编程练习**********************************/

/*************************************  (1)  ***************************************/

/*

#include<stdio.h>
int main(void)
{
char ch;
int space,newline,others;
space=newline=others=0;
printf("Please enter text to be analyzed( # to be terminate):\n");
while((ch=getchar())!='#')
	{
	if(ch==' ') space++;
	else if(ch=='\n') newline++;
	else others++;
	}
printf("space=%0d  newline=%0d  others=%0d\n",space,newline,others);
printf("Done.\n");
return 0;
}

*/

/****************************** (2) ************************************/

/*
#include<stdio.h>
int main(void)
	{
	char ch;
	int number=0;
	printf("Enter characters to be analyzed( # to be terminate):\n");
	while((ch=getchar())!='#')
		{
		if(number++%8==0)
			printf("\n");
		printf("%c %0d ",ch,ch);
		}
	printf("Done.\n");
	return 0;
	}
*/

/******************************(6)**********************************/

/*
#include<stdio.h>
int main(void)
	{
	char ch,prev=0;
	int num=0;
	printf("Enter characters to be analyzed( # to be terminate):\n");
	while((ch=getchar())!='#')
		{
		if(prev=='e'&&ch=='i') num++;
		prev=ch;
		}
	printf("\"ie\" is %0d\n",num);
	printf("Done.\n");
	return 0;
	}
*/


/******************************(8)****************************/

//若一开始输入空白字符，暂时无法处理
#include<stdio.h>
//#include<ctype.h>//无法使用isblank()
#define CHOICE1 8.75
#define CHOICE2 9.33
#define CHOICE3 10.00 
#define CHOICE4 11.20
#define TAXRATE1 0.15
#define TAXRATE2 0.2
#define TAXRATE3 0.25

void Print(void);

int main(void)
	{
	char choice,ch;
	double hrsalary,sum,tax;
	float hour;
	int i;//参照数
	while(1)
		{
		Print();
		i=0;
		if((choice=getchar())=='5')//输入'5'则结束程序
			{
			printf("Done.\n");
			break;
			}
		if(choice=='\n') i=1;
		if(i!=1)
			{
			while((ch=getchar())!='\n')//剔除错误输入
			continue;
			}
		switch(choice)
			{
			case '1':hrsalary=CHOICE1;
					break;
			case '2':hrsalary=CHOICE2;
					break;
			case '3':hrsalary=CHOICE3;
					break;
			case '4':hrsalary=CHOICE4;
					break;
			default:printf("Only input 1~5.\n");
					choice=0;continue;//数字若非1~5，开始新的循环
			}
			printf("Enter your working hours:____\b\b\b\b");
			/*
			while((ch=getchar())=='\n')
				{
				printf("Only input digit.\n");
				printf("Enter your working hours:____\b\b\b\b");
				}
			*///原用于防止回车键的干扰，但实验发现会影响下一判断语句
			while((scanf("%f",&hour))!=1)//用这个语句，几乎无法排除回车键的干扰
				{
				printf("Only input digit.\n");
				printf("Enter your working hours:____\b\b\b\b");
				//为什么没有以下这句会出现死循环，见C Primer Plus P79
				while((ch=getchar())!='\n')//剔除错误输入
				continue;
				}
			if(hour<=40)
				sum=hour*hrsalary;
			else sum=(40+(hour-40)*1.5)*hrsalary;
			if(sum<=300) tax=sum*TAXRATE1;
			else if(sum<=450) tax=300*TAXRATE1+(sum-300)*TAXRATE2;
			else tax=300*TAXRATE1+150*TAXRATE2+(sum-450)*TAXRATE3;
			printf("sum salary:$%0.2f  tax rate:$%0.2f  net salary;$%0.2f\n",
					sum,tax,sum-tax);
			printf("*******************************************************************\n");
			while((ch=getchar())!='\n')//剔除错误输入
				continue;//若在这儿用putchar(),会将scanf语句的非数字后缀输出
		}
		return 0;
	}
					
void Print(void)
	{
	printf("Enter the number corresponding to"
			" the desired pay rate or action:\n");
	printf("1) $%.2f/hr           ",CHOICE1);
	printf("2) $%.2f/hr\n",CHOICE2);
	printf("3) $%.2f/hr          ",CHOICE3);
	printf("4) $%.2f/hr\n",CHOICE4);
	printf("5) quit\n_\b");
	}


					



		

