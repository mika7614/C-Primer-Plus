/***************************** 程序清单16.12 *******************************/

/*
#include<stdio.h>
void why_me();
int main(void)
	{

	printf("The file is %s.\n",__FILE__);
	printf("The data is %s.\n",__DATE__);
	printf("The time is %s.\n",__TIME__);
	//printf("The version is %ld.\n",__STDC_VERSION__);不存在
	printf("This is lind %d.\n",__LINE__);
	//printf("This function is %s\n",__func__);不存在
	why_me();
	return 0;
	}
void why_me()
	{
	//printf("This function is %s\n",__func__);
	printf("This is line %d.\n",__LINE__);
	}
*/

/******************************** 程序清单16.16 ***********************************/

/*
#include<stdio.h>
#include<math.h>
#include<assert.h>
int main(void)
	{
	double x=-1;
	assert(x>0);
	sqrt(x);
	return 0;
	}
*/

/****************************** 复习题（4）*********************************/

/*
#include<stdio.h>
#define EVEN_GT(X,Y) ((X)>(Y) && (X) % 2 == 0 ? 1 : 0)
int main(void)
	{
	printf("%d\n",EVEN_GT(4,3));
	return 0;
	}
*/

/***************************** 复习题（5）(8) **********************************/

/*
#include<stdio.h>
#define PR(X,Y) printf(#X" is %d and "#Y" is %d\n",X,Y)
//#define __SKIP__
int main(void)
	{
#ifndef __SKIP__
	printf("Hello,world!\n");
#endif
	PR(3 + 4,4 * 12);
	return 0;
	}
*/

/************************* 编程练习 *****************************/

/**************************** (2) ***************************/

/*
#include<stdio.h>
#define AVERAGE(X,Y) (2*(X)*(Y)/((X)+(Y)))
int main(void)
	{
	double x,y;
	while(scanf("%lf%lf",&x,&y)==2)
		printf("Average is %.2f\n",AVERAGE(x,y));
	return 0;
	}
*/

/**************************** (3) *****************************/

/*
#include<stdio.h>
#include<math.h>
#define MATRIX (180/(4*atan(1)))
struct polar
	{
	double p;
	double q;
	};
struct rect
	{
	double x;
	double y;
	};
struct rect transform(struct polar);
int main(void)
	{
	struct rect result;
	struct polar source;
	
	printf("Enter the polar:(p,q)\n");
	while(scanf("%lf%lf",&source.p,&source.q)==2)
		{
		result=transform(source);
		printf("The rect is %.2f %.2f\n",result.x,result.y);
		}
	return 0;
	}
struct rect transform(struct polar source)
	{
	struct rect result;

	result.x=source.p*cos(source.q/MATRIX);
	result.y=source.p*sin(source.q/MATRIX);

	return result;
	}
*/

/**************************** (4) *******************************/

/*
#include<stdio.h>
#include<time.h>
#include<math.h>
void clock_mine(double);
int main(void)
	{
	double delay;
	printf("Enter the delay:\n");
	while(scanf("%lf",&delay)==1)
		clock_mine(delay);
	return 0;
	}
void clock_mine(double total)
	{
	double diff,initial,next;
	while(floor(initial)!=total && floor(next)!=total)
		{
		initial=(double)clock()/CLOCKS_PER_SEC;
		printf("initial=%f ",initial);
		next=(double)clock()/CLOCKS_PER_SEC;
		printf("next=%f ",next);
		diff=(next-initial);
		printf("diff=%f\n",diff);
		}
	return;
	}
*/

/*************************** (5) **************************/

/*
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define LIMIT 100
#define NAME_LENGTH 10
#define PR printf("Enter the number of people you want to choose:\n")
#define __SKIP__
void raffle(int*,int,int);
int deal_rand(int);
int main(void)
	{
	int n,i;
	int a[LIMIT];
	
	for(i=0;i<LIMIT;i++)
		a[i]=i+1;
	PR;
	scanf("%d",&n);
	raffle(a,LIMIT,n);
	return 0;
	}
void raffle(int *a,int spec,int n)
	{
	int i;
	int order;
	int record[LIMIT]={0};

	srand(time(0));
	printf("Here is the list:\n");
	for(i=0;i<n;i++)
		{
		do
			{
			order=deal_rand(rand());
			}while(record[order]==1);
		printf("%4d",a[order]);
			record[order]=1;
		if(i%9==8)
			putchar('\n');
		}
	putchar('\n');
	}
int deal_rand(int number)
	{
	int r;
	r=number % LIMIT;
	return r;
	}
*/

/****************************** (6) *********************************/

/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define NUM 4
#define LIMIT 40
struct names
	{
	char first[LIMIT];
	char last[LIMIT];
	};
void fillarray(struct names*,int);
void showarray(const struct names*,int);
int mycomp(const void *p1,const void *p2);

int main(void)
	{
	struct names book[NUM];
	fillarray(book,NUM);
	puts("Random list:");
	showarray(book,NUM);
	qsort(book,NUM,sizeof(struct names),mycomp);
	puts("\nSorted list: ");
	showarray(book,NUM);
	return 0;
	}
void fillarray(struct names *p ,int n)
	{
	int index;

	for(index=0;index<n;index++)
		{
		printf("%d.\n",index);
		printf("Enter your first name:\n");
		gets(p[index].first);
		printf("Enter your last name\n");
		gets(p[index].last);
		printf("Next one:\n");
		}
	}
void showarray(const struct names *p,int n)
	{
	int index;

	for(index=0;index<n;index++)
		{
		printf("%s ",p[index].first);
		printf("%s	",p[index].last);
		if(index % 6 == 5)
			putchar('\n');
		}
	if(index % 6 != 0)
		putchar('\n');
	}
int mycomp(const void *p1,const void *p2)
	{
	const struct names *a1=(const struct names*)p1;
	const struct names *a2=(const struct names*)p2;
	int res;

	res=strcmp(a1->last,a2->last);

	if(res !=0 )
		return res;
	else
		return strcmp(a1->first,a2->first);
	}
*/

/**************************** (7) ******************************/


#include<stdio.h>
#include<stdarg.h>
#include<stdlib.h>
void show_array(const double ar[],int n);
double *new_d_array(int n,...);
int main()
	{
	double *p1;
	double *p2;

	p1=new_d_array(5,1.2,2.3,3.4,4.5,5.6);
	p2=new_d_array(4,100.0,20.00,8.08,-1890.0);
	show_array(p1,5);
	show_array(p2,4);
	free(p1);
	free(p2);

	return 0;
	}
void show_array(const double ar[],int n)
	{
	int i;

	for(i=0;i<n;i++)
		printf("%.2f	",ar[i]);
	putchar('\n');
	}
double *new_d_array(int n,...)
	{
	va_list ap;
	double *p;
	int i;
	va_start(ap,n);

	p=(double*)(malloc(n*sizeof(double)));
	for(i=0;i<n;i++)
		{
		p[i]=va_arg(ap,double);
		}
	va_end(ap);
	return p;
	}


