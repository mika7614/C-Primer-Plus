/*****************************程序清单10.5*************************************/

//该编译器不支持C99
/*
#include<stdio.h>
#define MONTHS 12
int main(void)
	{
	int days[MONTHS]={31, 28, [4] = 31, 30, 31,[1] = 29};
	int i;
	for(i=0;i<MONTHS;i++)
		printf("%2d %d\n",i+1,days[i]);
	return 0;
	}
*/

/****************************10.13 编程练习*******************************/

/**************************** (2) *******************************/

/*
#include<stdio.h>
#define NUMBER 5
void copy_arr(double ar[],double cop[],int n);
void copy_ptr(double *ar,double *cop,int n);

int main(void)
	{
	int i;
	double target1[NUMBER],target2[NUMBER];
	double source[5]={1.1,2.2,3.3,4.4,5.5};
	copy_arr(source,target1,5);
	copy_ptr(source,target2,5);
	for(i=0;i<NUMBER;i++)
		printf("%.1f ",target1[i]);
	printf("\n");
	for(i=0;i<NUMBER;i++)
		printf("%.1f ",target2[i]);
	putchar('\n');
	return 0;
	}

void copy_arr(double ar[],double cop[],int n)
	{
	int i;
	for(i=0;i<n;i++)
		cop[i]=ar[i];
	return;
	}

void copy_ptr(double *ar,double *cop,int n)
	{
	double *p;
	printf("%p %p\n",&p,ar);
	p=ar+n;
	for( ;ar<p;ar++,cop++)
		*cop=*ar;
	return;
	}
*/



/**************************** (6) *******************************/

/*
#include<stdio.h>
void copy_arr(double ar[],double cop[],int n);
void copy_ptr(double *ar,double *cop,int n);

int main(void)
	{
	double *p;
	double a[3][3]={{5.7,2,9.8},{4.6,1.4,2.3},{4.0}};
	double target[3][3];//变量的定义一定要放前面

	p=a[0];
	copy_arr(p,target[0],3);
	//printf("p=%p ",p);
	copy_arr(p+3,target[1],3);
	copy_arr(p+6,target[2],3);
	p=target[0];
	for( ;p<target[0]+9;p++)
		{
		printf("%.1f ",*p);
		if((p-target[0])%3==2)
			putchar('\n');
		}
	return 0;
	}

void copy_arr(double ar[],double cop[],int n)
	{
	int i;
	for(i=0;i<n;i++)
		cop[i]=ar[i];
	//printf("ar=%p ",ar);
	return;
	}
*/

/*************************** (7) ****************************/

/*
#include<stdio.h>
void copy_ptr(double *ar,double *cop,int n);
int main(void)
	{
	int i;
	double array[7]={7.5,4.3,5.2,11.4,2.1};
	double target[3];
		
	copy_ptr(array+2,target,3);
	for(i=0;i<3;i++)
		printf("%.1f ",target[i] );
	return 0;
	}
void copy_ptr(double *ar,double *cop,int n)
	{
	double *p;
	printf("%p %p\n",&p,ar);
	p=ar+n;
	for( ;ar<p;ar++,cop++)
		*cop=*ar;
	return;
	}
*/

/************************* (8) ***************************/

/*
#include<stdio.h>
void copy(int ar[][5],int br[][5],int n);
void output(int ar[][5],int br[][5],int n);

int main(void)
	{
	int a[][5]={{3,7,13,6},{36,23,17,4},{31,37,84,26}};
	int b[3][5];

	copy(a,b,3);
	output(a,b,3);
	
	return 0;
	}

void copy(int ar[][5],int br[][5],int n)
	{
	int *p,*q;
	p=ar[0];
	q=br[0];
	for( ;p<ar[0]+n*5;p++,q++)
		*q=*p;
	return;
	}
void output(int (*ar)[5],int br[][5],int n)
	{
	int i,j;
	printf("Primary array:\n");
	for(i=0;i<n;i++)
		{
		for(j=0;j<5;j++)
			printf("%3d ",ar[i][j]);
		printf("\n");
		}

	printf("Array be copied:\n");
	for(i=0;i<n;i++)
		{
		for(j=0;j<5;j++)
			printf("%3d ",br[i][j]);
	printf("\n");
		}
	}
*/

/************************** (10) *****************************/

/*
#include<stdio.h>
void doub(int ar[][5],int n);
void output(int (*ar)[5],int n);
int main(void)
	{
	int array[3][5]={1,124,5,261,713,284,138,135,121,26,3,450,
		12,524,56};
	output(array,3);
	printf("After being dealt:\n\n");
	doub(array,3);
	output(array,3);
	return 0;
	}
void doub(int ar[][5],int n)
	{
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<5;j++)
			ar[i][j]*=2;
		return;
	}
void output(int ar[][5],int n)
	{
	int i,j;
	for(i=0;i<n;i++)
		{
		for(j=0;j<5;j++)
			printf("%3d ",ar[i][j]);
		putchar('\n');
		}
		return;
	}
*/

/************************** (12) *****************************/


#include<stdio.h>
//#include<stdlib.h>

void task_a(double ar[][5],int n);
double task_b(double ar[],int n);
double task_c(double ar[][5],int n);
double task_d(double (*ar)[5],int n);
void task_e(double average_groups[],double average,double max,int n);

int main(void)
	{
	int i;
	double average;
	double max;
	double average_groups[3];
	double array[3][5];
	double *p=array[0];

	task_a(array,3);
	for(i=0;i<3;i++,p+=5)
		average_groups[i]=task_b(p,5);
	average=task_c(array,3);
	max=task_d(array,3);
	task_e(average_groups,average,max,3);
	
	scanf("%*s");
	return 0;
	}

void task_a(double ar[][5],int n)
	{
	//FILE *fp;
	double *p=ar[0];
	int i,j;
	
	printf("Enter 15 numbers:\n");

	/*
	fp=fopen("array(3_5).txt","r");
	if(fp==NULL)
		{
		printf("Failed to open file.\n");
		exit(1);
		}
	while(fscanf(fp,"%lf",p)!=EOF)
		{
		printf("p=%p\n",p);
		p++;
		i++;
		}
	fclose(fp);
	*/
	
	for(j=1;j<4;j++)
		{
		printf("Group%d(including 5 members):\n",j);
		for(i=0;i<5;i++,p++)
			scanf("%lf",p);
		}
	return;
	}
double task_b(double *ar,int n)
	{
	int i;
	double ave=0.0;

	for(i=0;i<n;i++)
		ave+=*(ar+i);
	ave/=n;
	return ave;
	}
double task_c(double ar[][5],int n)
	{
	int i;
	double average=0.0;

	for(i=0;i<n*5;i++)
		average+=*(ar[0]+i);
	average/=(n*5);
	return average;
	}
double task_d(double ar[][5],int n)
	{
	int i;
	double max;

	max=*ar[0];
	for(i=0;i<n*5;i++)
		if(max<*(ar[0]+i)) max=*(ar[0]+i);
	return max;
	}
void task_e(double average_groups[],double average,double max,int n)
	{
	int i;
	putchar('\n');
	for(i=0;i<n;i++)
		printf("The average of group%d is %.2f\n",i+1,average_groups[i]);
	printf("Average is %.2f\n",average);
	printf("Max number is %.2f\n",max);
	printf("Done.\n");
	return;
	}

		


