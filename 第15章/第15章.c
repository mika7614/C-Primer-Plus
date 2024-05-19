/*********************** 编程练习 *************************/

/********************** (1) *************************/

/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int transform(char*,int);
int main(void)
	{
	char *pbin;

	pbin=(char*)malloc(sizeof(double)+1);
	printf("Enter a binary number:\n");
	scanf("%s",pbin);
	printf("The decimal number is %d\n",transform(pbin,strlen(pbin)));
	free(pbin);
	return 0;
	}
int transform(char *p,int n)
	{
	int number;
	int i,j;
	int s=0;

	for(i=0;i<n;i++)
		{
		number=p[i]-'0';
		for(j=1;j<n-i;j++)
			number *= 2;
		s += number;
		}
	return s;
	}
*/

/************************** (2) *****************************/

/*
#include<stdio.h>
#include<string.h>

void deal(char*,char*,int);
int main(int argc,char * argv[])
	{
	printf("~%s=",argv[1]);
	deal(argv[1],NULL,1);
	printf("~%s=",argv[2]);
	deal(argv[2],NULL,1);
	printf("%s & %s =",argv[1],argv[2]);
	deal(argv[1],argv[2],2);
	printf("%s | %s =",argv[1],argv[2]);
	deal(argv[1],argv[2],3);
	printf("%s ^ %s =",argv[1],argv[2]);
	deal(argv[1],argv[2],4);
	return 0;
	}
void deal(char *str1,char* str2,int n)
	{
	int i;
	int size=strlen(str1);
	int number[2];

	if(n==1)
		{
		for(i=0;i<size;i++)
			{
			number[0]=str1[i]-'0';
			printf("%d",number[0]==1?0:1);
			}
		putchar('\n');
		}
	if(n==2)
		{
		for(i=0;i<size;i++)
			{
			number[0]=str1[i] - '0';
			number[1]=str2[i] - '0';
			printf("%d",number[0] & number[1]);
			}
		putchar('\n');
		}
	if(n==3)
		{
		for(i=0;i<size;i++)
			{
			number[0]=str1[i] - '0';
			number[1]=str2[i] - '0';
			printf("%d",number[0] | number[1]);
			}
		putchar('\n');
		}
	if(n==4)
		{
		for(i=0;i<size;i++)
			{
			number[0]=str1[i] - '0';
			number[1]=str2[i] - '0';
			printf("%d",number[0] ^ number[1]);
			}
		putchar('\n');
		}
	}
*/

/****************************** (3) ******************************/

/*
#include<stdio.h>
void bit(int);
int main(void)
	{
	int a;
	

	printf("Enter a number:\n");
	while(scanf("%d",&a)==1)
		bit(a);
	return 0;
	}
void bit(int a)
	{
	int bin=1;
	int count=0;
	int b;
	
	if(a!=0)
		{
		if(a>0)
			{
			b=a;
			while(a>=bin)
				{
				if(b&1==1)
					count++;
				b>>=1;
				bin*=2;
				}
			}
		else
			{
			a &= 0x7fff;
			b=a;
			while(a>=bin)
				{
				if(b&1==1)
					count++;
				b>>=1;
				bin*=2;
				}
			count++;
			}
		}
	printf("Opening bit is %d\n",count);
	}
*/

/*********************** (4) **************************/

/*
#include<stdio.h>
int is_1(int,int);
int main(void)
	{
	int a,n;

	printf("Enter two integer number:\n");
	while(scanf("%d%d",&a,&n)==2)
		{
		if(n>=1)
			{
			printf("%d\n",is_1(a,n));
			}
		else
			printf("Error.\n");
		printf("Enter next number\n");
		}
	return 0;
	}
int is_1(int a,int n)
	{
	if(n>1)
		{
		if(a>>(n-1)&1==1)
			{
			return 1;
			}
		else
			return 0;
		}
	else
		{
		a &= 1;
		if(a==1)
			return 1;
		}
	return 0;
	}
*/

/************************** (5) ***************************/

/*
#include<stdio.h>
void rotate_l(int,int);
int main(void)
	{
	int a,n;
	printf("Enter two integers\n");
	while(scanf("%d%d",&a,&n)==2)
		{
		if(n>0)
			rotate_l(a,n);
		else
			printf("Error.\n");
		printf("Enter next group of integers.\n");
		}
	return 0;
	}
void rotate_l(int a,int n)
	{
	int b;
	int i,j,s;
 
	for(i=15;i>=0;i--)
		printf("%d",(a>>i)&1);
	putchar('\n');
	b=a;

	a<<=n;
	printf("a<<=n:");
	for(i=15;i>=0;i--)
		printf("%d",(a>>i)&1);
	putchar('\n');

	b>>=16-n;
	printf("b>>=16-n:");
	for(i=15;i>=0;i--)
		printf("%d",(b>>i)&1);
	putchar('\n');

	if(b<0)
		{
		for(i=0;i<16-n;i++)
			{
			s=1;
			for(j=i;j<15;j++)
				s*=2;
			b -= s;
			}
		printf("b-(n*2):");
		for(i=15;i>=0;i--)
			printf("%d",(b>>i)&1);
		putchar('\n');
		}
	a |= b;
	for(i=15;i>=0;i--)
		printf("%d",(a>>i)&1);
	putchar('\n');
	printf("After transformation:");
	for(i=15;i>=0;i--)
		printf("%d",(a>>i)&1);
	putchar('\n');
	printf("Or that:%d\n",a);
	}
*/

/**************************** (6) *****************************/

/*
#include<stdio.h>
#include<string.h>
struct style
	{
	unsigned int Font_ID  :8;
	unsigned int          :0;
	unsigned int Font_Size:4;
	unsigned int		  :1;
	unsigned int Bold	  :1;
	unsigned int Italic   :1;
	unsigned int Underline:1;
	};
int menu(void);
void output(struct style *,char);
int main(void)
	{
	while(menu())
		continue;
	return 0;
	}
int menu(void)
	{
	static int b=1;
	char ch;
	int a;
	static char align='l';
	static struct style operate={
		1,
		12,
		0,
		0,
		0,
		};
	if(b)
		output(&operate,align);
	printf("f)change font      s)change size      a)change alignment\n");
	printf("b)toggle bold      i)toggle italic    u)toggle underline\n");
	printf("q)quit\n");

	ch=getchar();
	getchar();//删掉回车
	if(ch=='s')
		{
		printf("Enter font size (0-127):");
		scanf("%u",&a);
		getchar();//删掉回车
		a &= 0x7f;
		operate.Font_Size=a;
		output(&operate,align);
		b=0;
		}
	if(ch=='a')
		{
		printf("Select alignment:\n");
		printf("l)left c)center r)right\n");
		ch=getchar();
		getchar();
		align=ch;
		output(&operate,align);
		b=0;
		}
	if(ch=='b')
		{
		operate.Bold=~operate.Bold;
		output(&operate,align);
		b=0;
		}
	if(ch=='i')
		{
		operate.Italic=~operate.Italic;
		output(&operate,align);
		b=0;
		}
	if(ch=='u')
		{
		operate.Underline=~operate.Underline;
		output(&operate,align);
		b=0;
		}
	if(ch=='f')
		{
		printf("Enter font size (0-255):");
		scanf("%u",&a);
		getchar();//删掉回车
		a &= 0xff;
		operate.Font_ID=a;
		output(&operate,align);
		b=0;
		}
	if(ch=='q')
		return 0;
	else
		return 1;
	}
void output(struct style *p,char ch)
	{
	char cha[7];
	if(ch=='l')
		strcpy(cha,"left");
	if(ch=='c')
		strcpy(cha,"center");
	if(ch=='r')
		strcpy(cha,"right");
	printf("ID SIZE ALIGNMENT B I U\n");
	printf("%u %u %s %s %s %s\n",p->Font_ID,p->Font_Size,cha,
		p->Bold==0?"off":"on",
		p->Italic==0?"off":"on",
		p->Underline==0?"off":"on");
	return;
	}
*/			

/************************* (7) ***************************/


#include<stdio.h>
//假设从右至左排列
//1-8位：ID 9-16位：size 17-18位：alignment(0:left;1:center;2;right) 21位：Bold 25位：Italic 29位：Underline 
#define initial 0xc01
int menu(void);
void output(unsigned long);
int main(void)
	{
	unsigned long ch=0ul;
	ch |= initial;//初始化
	output(ch);
	while(menu());
	return 0;
	}
int menu(void)
	{
	static int b=1;
	char ch;
	unsigned int a;
	static unsigned long word=0ul;

	if(b)
		word |= initial;
	printf("f)change font      s)change size      a)change alignment\n");
	printf("b)toggle bold      i)toggle italic    u)toggle underline\n");
	printf("q)quit\n");
	ch=getchar();
	getchar();//删掉回车
	if(ch=='s')
		{
		printf("Enter font size (0-127):");
		scanf("%u",&a);
		getchar();//删掉回车
		a &= 0x7f;//保证范围0-127
		a <<= 8;
		word &= 0xffff00ff;
		word |= a; 
		output(word);
		b=0;
		}
	if(ch=='a')
		{
		printf("Select alignment:\n");
		printf("l)left c)center r)right\n");
		a=getchar();
		getchar();
		a &= 3;
		a <<= 16;
		word &= 0xfff3ffff;
		word |=a;
		output(word);
		b=0;
		}
	if(ch=='b')
		{
		word ^= 1<<20;
		output(word);
		b=0;
		}
	if(ch=='i')
		{
		word ^= 1<<24;
		output(word);
		b=0;
		}
	if(ch=='u')
		{
		word ^= 1<<28;
		output(word);
		b=0;
		}
	if(ch=='f')
		{
		printf("Enter font size (0-255):");
		scanf("%u",&a);
		getchar();//删掉回车
		a &= 0xff;//保证范围0-255
		word &= 0xffffff00;
		word |= a; 
		output(word);
		b=0;
		}
	if(ch=='q')
		return 0;
	else
		return 1;
	}
void output(unsigned long word)
	{
	printf("ID SIZE ALIGNMENT B I U\n");
	printf("%d ",word & 0xff);
	printf("%d ",(word & 0x7f00)>>8);
	if(word & 0x30000 == 0)
		printf("left ");
	if(word & 0x30000 == 1)
		printf("center ");
	if(word & 0x30000 == 2)
		printf("right ");
	printf("%s ",(word & 04000000)>>20 ==1?"on":"off");
	printf("%s ",(word & 0x1000000)>>24 ==1?"on":"off");
	printf("%s\n",(word & 0x10000000)>>28 ==1?"on":"off");
	}
