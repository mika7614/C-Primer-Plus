/****************************** 程序清单11.27 *******************************/

/*
#include<stdio.h>
int main(int argc,char *argv[])
	{
	int count;

	printf("The command line has %d arguments:\n",argc-1);
	for(count=1;count<argc;count++)
		printf("%d: %s\n",count,argv[count]);
	printf("\n");
		return 0;
	}
*/

/********************复习题********************/
/******************* (9) ********************/

/*
#include<stdio.h>
#include<string.h>
int main(void)
	{
	char *p="I'm the best.";
	printf("There are %d characters.",strlen(p));
	return 0;
	}
*/

/******************** (10) *********************/

/*
#include<stdio.h>
char *strbik(char *);

int main(void)
	{
	char *p="I'm the best.";
	char *q;

	q=strbik(p);
	printf("0%c0",*q);
	return 0;
	}
char *strbik(char *str)
	{
	while((*str !=' ') && (*str !='\0'))
		str++;
		if(*str=='\0') 
			return NULL;
		else 
			return str;
	}
*/

/******************* (11) **********************/

/*
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define ANSWER "GRANT"
#define MAX 40

int main(void)
	{
	char Try[MAX];
	char *p=Try;

	puts("Who is buried in Grant's tomb?");
	gets(Try);
		while(*p !='\0')
			{
			*p=toupper(*p);
			p++;
			}
	while(strcmp(Try,ANSWER))
		{
		puts("No, that's wrong. Try again.");
		gets(Try);
		p=Try;
		while(*p !='\0')
			{
			*p=toupper(*p);
			p++;
			}
		}
	puts("That's right!");
	return 0;
	}
*/


/****************************** 编程练习 *******************************/
/******************** (1) *********************/

/*
#include<stdio.h>
#include<string.h>
char *deal(const char *,int n);
int main(void)
	{
	char str[81];
	char *p=str;
	char *copy;
	int number;
	
	while((*p=getchar())!=EOF && p<str+80)//注意'\0'
		p++;
	puts("How many characters do you want?");
	scanf("%d",&number);
	putchar('\n');
	p=str;
	copy=deal(p,number);
	puts(copy);
	return 0;
	}
char *deal(const char *ch,int n)
	{
	static char cop[81];
	char *q=cop;
	strncpy(cop,ch,n);
	cop[n+1]='\0';
	return q;
	}
*/

/*************************** (2) ******************************/

/*
#include<stdio.h>
#include<string.h>
char *deal(const char *,int n);
int main(void)
	{
	char str[101];
	char *p=str;
	char *copy;
	int number;
	
	while((*p=getchar())!=EOF && p<str+1003)//注意'\0'
		p++;
	*p='\0';
	puts("How many characters do you want?");
	scanf("%d",&number);
	putchar('\n');
	p=str;
	copy=deal(p,number);
	puts(copy);
	return 0;
	}
char *deal(const char *ch,int n)
	{
	static char cop[101];
	const char *q;
	int after=0;

	strncpy(cop,ch,n);
	q=ch+n-1;
	//printf("%c\n",*q);
	do
		{
		if(q==(ch+100)) break;
		after++;
		q++;
		}while(*q!=' ' && *q!='\n' && *q!='\t');
	//after++;
	strncpy(cop+n,ch+n,after);
	cop[after+n+1]='\0';
	// printf("%d\n",after);
	return cop;
	}
*/	

/********************* (3) **********************/

/*
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define MAX 81
void a_word(char *str,int n);

int main(void)
	{
	char string[MAX];


	printf("Enter the a sentence:\n");
	fgets(string,MAX,stdin);
	a_word(string,MAX);
	return 0;
	}
void a_word(char *str,int n)
	{
	char *find;
	char *first;
	int in_word=0;
	find=strchr(str,'\n');
		if(find)
			*find='\0';
		else
			str[MAX]='\0';

	while(str != NULL)
		{
		if(isalpha(*str)!=0 && in_word==0)
			{
			in_word=1;
			first=str;
			}
		else if(in_word==1 && (isspace(*str)!=0 || ispunct(*str)!=0) )
			break;
		str++;
		}
	*str='\0';
	printf("first word is: ");
	puts(first);
	return;
	}
*/ 

/********************** (4) **********************/

/*
#include<stdio.h>
#define MAX 81

char *search(const char *source,char target);

int main(void)
	{
	char *find;
	char key;
	char string[MAX];
	int i=0;

	puts("Enter a sentence:");
	while((string[i]=getchar())!=EOF && i<MAX)
		i++;
	string[i]='\0';
	puts("\nEnter the key(Only one character)");
	key=getchar();
	if( (find=search(string,key)) == NULL)
		puts("Not found!");
		else puts(find);
	return 0;
	}
char *search(const char *source,char target)//对于这个函数很好奇。因为编译始终会出现警告。
	{										//不知道编译人员怎么把strchr()写出来的。
	const char *p;//定位指针

	while(*source != target && *source!='\0')
		source++;
	p=source;
	return p;
	}
*/

/*********************** (5) *************************/

/*
#include<stdio.h>
#define MAX 81
int is_within(char target,const char *source);
int main(void)
	{
	char key;
	char string[MAX];
	int i=0;

	puts("Enter a sentence:");
	while((string[i]=getchar())!=EOF && i<MAX)
		i++;
	string[i]='\0';
	puts("\nEnter the key(Only one character)");
	key=getchar();
	if( is_within(key,string))
		puts("Exist.");
		else puts("Not found.");
	return 0;
	}
int is_within(char target,const char *source)
	{
	const char *p;//定位指针

	while(*source != target && *source!='\0')
		source++;
	p=source;
	return(*p=='\0'?0:1);
	}
*/

/************************************** (6) ****************************************/

/*
#include<stdio.h>
#include<string.h>
#define MAX 81
void strn(char *target,const char *source,int max);

int main(void)
	{
	char s2[MAX];
	char s1[MAX];
	int i=0;

	puts("Enter a sentence:");
	while((s2[i]=getchar())!=EOF && i<MAX)
		i++;
	s2[i]='\0';
	strn(s1,s2,i);
	return 0;
	}
void strn(char *target,const char *source,int max)
	{
	int n=max+1;

	do
		{
		puts("How many characters do you want to copy:");
		if(scanf("%d",&n)!=1)
			{
			getchar();
			puts("Only input digits");
			}
		}while(n>max);
	strncpy(target,source,n);
	if(*(source+n)!='\0')
		*(target+n)='\0';
	puts(target);
	return;
	}
*/

/************************ (7) ****************************/

/*
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX 201
const char *string_in(const char *source,const char *code,int length);

int main(void)
	{
	char string[MAX];
	char key[MAX];
	const char *first_appear;
	int i=0;

	puts("Enter a sentence:");
	while((string[i]=getchar())!=EOF && i<MAX)
		i++;
	string[i]='\0';
	puts("Input the key:");
	i=0;
	while(isspace(key[i]=getchar())==0 && i<MAX)
		i++;
	key[i]='\0';
	if((first_appear=string_in(string,key,i)) )
		puts(first_appear);
	else ;
	return 0;
	}
const char *string_in(const char *source,const char *code,int length)
	{
	int exist=0;
	const char *begin;
	if((begin=strchr(source,code[0]))==NULL  || *begin=='\0')
		puts("Not found.");
	else
		{
		exist=1;
		while(strncmp(begin,code,length)!=0)
			{
			begin++;
			exist=0;
			if((begin=strchr(begin,code[0]))==NULL || *begin=='\0')
				{
				puts("Not found.");
				break;
				}
			exist=1;
			}
		}
	return(exist==1 ? begin : 0);
	}
*/

/************************* (8) ***************************/

/*
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX 201
void invert(char *target);
int main(void)
	{
	char string[MAX];
	int i=0;

	puts("Enter a sentence:");
	while((string[i]=getchar())!=EOF && i<MAX)
		i++;
	string[i]='\0';
	invert(string);
	scanf("%*s");
	return 0;
	}

void invert(char *target)
	{
	char *search=target;
	while(*search != '\0')
		search++;
	while(search!=target)
		{
		search--;
		putchar(*search);
		}
	return;
	}
*/

/*************************** (9) *******************************/

/*
#include<stdio.h>
#include<string.h>
#define MAX 201
void delete_space(char *str);
int main(void)
	{
	char string[MAX];
	puts("Enter a sentence:");
	while(gets(string)!=NULL && string[0]!='\0')
		{
		delete_space(string);
		putchar('\n');
		puts("Enter a sentence:");
		}
	return 0;
	}
void delete_space(char *str)
	{
	char *find;
	char *p=str;
	while(p)
		{
		find=strchr(p,' ');
		if(find)
			*find='\0';
		//printf("%p %p\n",find,&str[MAX]);
		fputs(p,stdout);
		if(!find)
			break;
		p=find+1;
		}
	return;
	}
*/

/*********************** (10) *************************/


/*
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define GROUPS 10
#define MAX 201
#define STAR "**************************************************"

void menu(char string[][MAX],int n);
void function1(const char *str[],int n);
void function2(const char *str[],int n);
void function3(const char *str[],int n);
void function4(const char *str[],int n);

int main(void)
	{
	int number=0;
	char string[GROUPS][MAX];
	
	puts("Enter 10 strings:");
	while(number<GROUPS && gets(string[number])!=NULL && string[number][0]!='\0')
		number++;
	if(number==0)
		puts("Done.");
	else
		menu(string,number);
	return 0;
	}

void menu(char string[][MAX],int n)
	{
	int i;
	const char *str[GROUPS];
	char ch;

	for(i=0;i<n;i++)
		str[i]=string[i];

	puts(STAR);
	puts("1)function 1        2)function2");
	puts("3)function 3        4)function4");
	puts("5)quit");

	while((ch=getchar())!='5')
		{
		if(ch>'4' || ch<'1')
			{
			if(ch!='\n')
				{
				while(getchar()!='\n')
					continue;
				}
			puts("Only input 1~5.");
			puts(STAR);
			puts("1)function 1        2)function2");
			puts("3)function 3        4)function4");
			puts("5)quit");
			continue;
			}
		else
			while(getchar()!='\n')
					continue;
			switch(ch)
			{
			case'1':function1(str,n);
					break;
			case'2':function2(str,n);
					break;
			case'3':function3(str,n);
					break;
			case'4':function4(str,n);
					break;
			}
		puts(STAR);
		puts("1)function 1        2)function2");
		puts("3)function 3        4)function4");
		puts("5)quit");
		}
	return;
	}
void function1(const char *str[],int n)
	{
	int i;
	for(i=0;i<n;i++)
		puts(str[i]);
	return;
	}
void function2(const char *str[],int n)
	{
	int i,j;
	const char *agency;
	const char *sort[GROUPS];

	if(n>1)//直接排序
		{
		for(i=0;i<n;i++)
			sort[i]=str[i];
		for(i=0;i<n;i++)
			for(j=i+1;j<n;j++)
				if(strcmp(sort[i],sort[j])>0)
					{
					agency=sort[i];
					sort[i]=sort[j];
					sort[j]=agency;
					}
		}
	else
		sort[0]=str[0];
	function1(sort,n);
	return;
	}
void function3(const char *str[],int n)
	{
	int i,j;
	const char *sort[GROUPS];
	const char *agency;

	if(n>1)
		{//冒泡排序
		for(i=0;i<n;i++)
			sort[i]=str[i];
		for(i=0;i<n-1;i++)
			for(j=1;j<n-i;j++)
				if( strlen(sort[j-1])>strlen(sort[j]) )
					{
					agency=sort[j-1];
					sort[j-1]=sort[j];
					sort[j]=agency;
					}
		}
	else
		sort[0]=str[0];
	function1(sort,n);
	return;
	}
void function4(const char *str[],int n)
	{
	int i;
	int j;
	int in_word;
	char *first;
	char *p;
	const char *agency;
	const char *temp[GROUPS];
	char word[GROUPS][MAX];
	const char *sort[GROUPS];

	if(n>1)
		{
		for(i=0;i<n;i++)
			{
			in_word=0;
			strcpy(word[i],str[i]);
			p=word[i];
			while( p!=NULL && *p!='\0')
				{
					if(isalpha(*p)!=0 && in_word==0)
					{
					in_word=1;
					first=p;
					}
				else if(in_word==1 && (isspace(*p)!=0 || ispunct(*p)!=0) )
					break;
				p++;
				}
			*p='\0';
			strcpy(word[i],first);
			}
		for(i=0;i<n;i++)
			{
			sort[i]=str[i];
			temp[i]=word[i];
			}
		for(i=0;i<n-1;i++)
			for(j=1;j<n-i;j++)
				if( strlen(temp[j-1]) > strlen(temp[j]) )
					{
					agency=sort[j-1];
					sort[j-1]=sort[j];
					sort[j]=agency;
					agency=temp[j-1];
					temp[j-1]=temp[j];
					temp[j]=agency;
					}
		}
	else
		sort[0]=str[0];
	function1(sort,n);
	return;
	}
*/


/*************************** (11) ******************************/

/*
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX 201

int main(void)
	{
	int in_word=0;
	int record[5]={0};
	char string[MAX];
	int i=0;

	puts("Enter a sentence:");
	while((string[i]=getchar())!=EOF && i<MAX)
		{
		if(ispunct(string[i])!=0)
			record[3]++;
		if(isdigit(string[i])!=0)
			record[4]++;
		if(islower(string[i])!=0)
			record[2]++;
		if(isupper(string[i])!=0)
			record[1]++;
		if(isalpha(string[i])!=0 && in_word==0)
			in_word=1;
		else if(in_word==1 && (isspace(string[i])!=0 || ispunct(string[i])!=0 || isdigit(string[i])!=0) )
			{
			in_word=0;
			record[0]++;
			}
		}
	string[i]='\0';
	printf("%s %s %d\n",record[0]>1? "Words" : "word",record[0]>1? "have" : "has",record[0]);
	printf("%s %s %d\n",record[1]>1? "Capital letters" : "Capital letter",record[1]>1? "have" : "has",record[1]);
	printf("%s %s %d\n",record[2]>1? "Lower-case letters" : "Lower-case letter",record[2]>1? "have" : "has",record[2]);
	printf("%s %s %d\n",record[3]>1? "Punctuations" : "Punctuation",record[3]>1? "have" : "has",record[3]);
	printf("%s %s %d\n",record[4]>1? "Digits" : "Digit",record[4]>1? "have" : "has",record[4]);
	return 0;
	}
*/

/******************************** (12) *********************************/

/*
#include<stdio.h>
int main(char argc,char * argv[])
	{
	int count;
	for(count=argc-1;count>0;count--)
		printf("%s ",argv[count]);
	putchar('\n');
	return 0;
	}
*/

/******************************** (13) **********************************/

/*
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(char argc,char *argv[])
	{
	int i;
	double s=1;
	double base_number;
	int power;

	if( (base_number=atol(argv[1])) <= 0)
		puts("Error.Input again");
		else
			{
			if( (power=atoi(argv[2]))!=0)
				{
				for(i=0;i<abs(power);i++)
					s *= atol(argv[1]);
				if(power<0)
					s = 1/s;
				}
			}
	puts(argv[1]);
	printf("%.2f to the %d power = %.4f\n",base_number,power,s);
	return 0;
	}
*/

/***************************** (14) ********************************/

/*
#include<stdio.h>
int main(int argc,char * argv[])
	{
	char *p=argv[1];
	int i=0;
	int j;
	int k;
	int s=0;
	int a[10];
	
	while(p[i]<='9' && p[i]>='0')
		i++;
	if(i>0)
		{
		for(j=0;j<i;j++)
			a[j] =p[j] - '0';

		for(j=0;j<i;j++)
			{
			if(j!=i-1)
				for(k=j;k<i-1;k++)
					a[j] *= 10;
			s += a[j];
			}
		printf("From character to integer:%d\n",s);
		}
	printf("Done.\n");
	return 0;
	}
*/

/**************************** (15) ********************************/

/*
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#define MAX 201

int main(int argc,char * argv[])
	{
	int i=0;
	char capital[MAX];
	char lowercase[MAX];

	if(argc!=3)
		{
		printf("Error.\n");
		exit(0);
		}

	while(argv[1][0]!='\0' && argv[1] != NULL && i<MAX)
		{
		capital[i]=toupper(argv[1][i]);
		lowercase[i]=tolower(argv[1][i]);
		i++;
		}
	capital[i]=lowercase[i]='\0';
	if(strcmp("-p",argv[2])==0)
		puts(argv[1]);
	if(strcmp("-u",argv[2])==0)
		puts(capital);
	if(strcmp("-l",argv[2])==0)
		puts(lowercase);
	return 0;
	}
*/