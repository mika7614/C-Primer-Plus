/***************************** 程序清单12.1 *******************************/

/*
#include<stdio.h>
int main(void)
	{
	int x=30;
	printf("x in outer block: %d\n",x);
		{
		int x=7;
		printf("x in inner block: %d\n",x);
		}
	printf("x in outer block: %d\n",x);
	while(x++<33)
		{
		int x=100;
		x++;
		printf("x in while loop: %d\n",x);
		}
	printf("x in outer block: %d\n",x);
	return 0;
	}
*/

/******************************* 程序清单12.2 ***********************************/

//不支持C99特性
/*
#include<stdio.h>
int main(void)
	{
	int n=10;

	printf("Intially, n=%d\n",n);
	for(int n=1;n<3;n++)
		printf("loop 1: n=%d\n",n);
	printf("After loop 1: n=%d\n",n);
	for(int n=1;n<3;n++)
		{
		printf("loop 2: index n=%d\n",n);
		int n=30;
		printf("loop 2: n=%d\n",n);
		n++;
		}
	printf("After loop 2: n=%d\n",n);
	return 0;
	}
*/

/**************************** 自动变量初始化 **********************************/

/*
#include<stdio.h>
int main(void)
	{
	int a=3;
	int b=5*a;
	printf("%d\n",b);
	return 0;
	}
*/

/**************************** 程序清单12.14 ******************************/

/*
#include<stdio.h>
#include<stdlib.h>
int main(void)
	{
	double *ptd;
	int max;
	int number;
	int i=0;

	puts("What is the maximum number of type double entries?");
	scanf("%d",&max);
	ptd=(double *)malloc(max *sizeof(double) );
	if(ptd==NULL)
		{
			puts("Memory allocation failed. Goodbye.");
			exit(EXIT_FAILURE);
		}
	puts("Enter the values: (q to quit)");
	while(i<max && scanf("%lf",&ptd[i])==1)
		i++;
	printf("Here are your %d entries: \n",number=i);
	for(i=0;i<number;i++)
		{
		printf("%7.2f ",ptd[i]);
		if(i % 7 ==6)
			putchar('\n');
		}
	if(i % 7 !=0);
	putchar('\n');
	puts("Done.");
	free(ptd);

	return 0;
	}
*/

/*********************** 类型限定词restrict 例子 **************************/

//怎么解释？
/*
#include<stdio.h>
int main(void)
	{
	int ar[1]={4};
	int *p=ar;
	p[0] += 6;
	ar[0] *= 2;
	p[0] += 3;
	printf("%d",ar[0]);
	return 0;
	}
*/

/***************************** 编程练习 ********************************/

/************************* (1) ***************************/

/*
#include<stdio.h>
int critic(void);
int main(void)
	{
	int units;

	printf("How many pounds to a firkin of butter?\n");
	scanf("%d",&units);
	while(units != 56)
		units=critic();
	printf("You must have looked it up!\n");
	return 0;
	}
int critic(void)
	{
	int units;
	printf("No luck, chummy. Try again.\n");
	scanf("%d",&units);
	return units;
	}
*/

/*************************** (4) ******************************/

/*
#include<stdio.h>
int print(void);
int main(void)
	{
	int i,j;
	for(i=0;i<4;i++)
		j=print();
	printf("Being used %d times\n",j);
	return 0;
	}
int print(void)
	{
	static int calculate;
	calculate++;
	printf("So boring.\n");
	return calculate;
	}
*/

/***************************** (5) **********************************/

/*
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 100

int deal_rand();
int main(void)
	{
	int i;
	int j;
	int temp;
	int random[MAX];
	srand((unsigned int) time(0));
	for(i=0;i<MAX;i++)
		random[i]=deal_rand();
	
	for(i=0;i<MAX-1;i++)
		for(j=0;j<MAX-1-i;j++)
			if(random[j]<random[j+1])
				{
				temp=random[j];
				random[j]=random[j+1];
				random[j+1]=temp;
				}
	
	for(i=0;i<MAX;i++)
		{
		printf("%4d",random[i]);
		if(i%10==9)
			putchar('\n');
		}
	scanf("%*s");
	return 0;
	}
int deal_rand()
	{
	int deal;
	deal=rand()%10+1;
	return deal;
	}
*/

/******************************* (6) *********************************/

/*
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 1000
#define DIVISOR 10

int deal_rand();
int main(void)
	{
	int i;
	int j=0;
	int k;
	unsigned int count[DIVISOR]={0};//数组只有定义过程才能以这种形式初始化
	
	srand( (unsigned int)time(0) );
	printf("Seed is %u:\n\n",(unsigned int)time(0) );
	while(j<10)
		{
		for(i=0;i<MAX;i++)
			{
			switch(deal_rand())
				{
				case 1:count[0]++;
						break;
				case 2:count[1]++;
						break;
				case 3:count[2]++;
						break;
				case 4:count[3]++;
						break;
				case 5:count[4]++;
						break;
				case 6:count[5]++;
						break;
				case 7:count[6]++;
						break;
				case 8:count[7]++;
						break;
				case 9:count[8]++;
						break;
				case 10:count[9]++;
						break;
				}
			}
		for(i=0;i<DIVISOR;i++)
			printf("%2d:%-4u ",i+1,count[i]);
		printf("\n\n");
		for(k=0;k<DIVISOR;k++)
				count[k]=0;
		j++;
		}
	scanf("%*s");
	return 0;
	}
int deal_rand()
	{
	int deal;
	deal=rand()%DIVISOR+1;
	return deal;
	}
*/

/******************************* (7) **********************************/

/*
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define LIM 5

void roll_dice(unsigned int sets,unsigned int sides,unsigned int dice);

int main(void)
	{
	unsigned int index;
	unsigned int i=0;
	unsigned int j;
	unsigned int transform[LIM];
	unsigned int a[3];
	char str[LIM];

	a[0]=0;
	printf("Enter the number of sets: enter q to stop.\n");
	while((str[i]=getchar()) != 'q')
		{
		if(i==0 && str[i]=='\n')
			{
			printf("Enter the number of sets: enter q to stop.\n");
			continue;
			}
		if(str[i] >= '0' &&  str[i] <= '9')
			{
			transform[i]=str[i]-'0';
			i++;
			continue;
			}
		
		if(!(str[i] >= '0' &&  str[i] <= '9'))
			{
			if(i==0)
				{
				printf("Enter the number of sets: enter q to stop.\n");
				while(getchar()!='\n')//删去多余数据
					continue;
				continue;
				}
			else
				{
				for(index=0;index<i;index++)
					{
					if(index!=i-1)
						{
						for(j=0;j<i-1-index;j++)
							transform[index]*=10;
						}
					a[0]+=transform[index];
					}
				}
			if(str[i]!='\n')
				while(getchar()!='\n')//删去多余数据
					continue;
			}
		printf("How many sides and how many dice?\n");
		
		while(scanf("%u%u",&a[1],&a[2])!=2)
			{
			printf("How many sides and how many dice?\n");
			scanf("%*s");
			}
		roll_dice(a[0],a[1],a[2]);
		getchar();
		printf("How many sets? Enter q to stop.\n");
		a[0]=i=0;
		}
	printf("Done.\n");
	scanf("%*s");
	return 0;
	}
void roll_dice(unsigned int sets,unsigned int sides,unsigned int dice)
	{
	unsigned int execute(unsigned int sides);
	unsigned int i;
	unsigned int j;
	unsigned int a;
	srand( (unsigned int)time(0) );
	if( sets>0 && sides>1 && dice>0)
		{
		printf("Here are %5u sets of %u %u-sides throws.\n	",sets,dice,sides);
		for(i=0;i<sets;i++)
			{
			a=0;
			for(j=0;j<dice;j++)
				a += execute(sides);
			printf("%3u",a);
			if(i%15==14)
				printf("\n	");
			}
		printf("\n");
		}
	else
		printf("Error.Enter the date again\n");
	}
unsigned int execute(unsigned int sides)
	{
	unsigned int answer;
	answer=rand()%sides+1;
	return answer;
	}
*/

/************************* (8) **************************/

#include<stdio.h>
#include<stdlib.h>
int * make_array (int elem,int val);
void show_array(const int ar[],int n);
int main(void)
	{
	int *pa;
	int size;
	int value;

	printf("Enter the number of elements: ");
	scanf("%d",&size);
	while(size>0)
		{
		printf("Enter the initialization value: ");
		scanf("%d",&value);
		pa = make_array(size,value);
		if(pa)
			{
			show_array(pa,size);
				free(pa);
			}
		printf("Enter the number of elements ( <1 to quit):");
		scanf("%d",&size);
		}
	printf("Done.\n");
	return 0;
	}
int * make_array (int elem,int val)
	{
	int i;
	int *p;
	p=(int *)malloc(elem * sizeof(int));
	if(p==NULL)
		{
			puts("Memory allocation failed. Goodbye.");
			exit(EXIT_FAILURE);
		}
	for(i=0;i<elem;i++)
		p[i]=val;
	return p;
	}
void show_array(const int ar[],int n)
	{
	int i;
	for(i=0;i<n;i++)
		{
		printf("%5d",ar[i]);
		if(i%8==7)
			putchar('\n');
		}
	putchar('\n');
	return;
	}