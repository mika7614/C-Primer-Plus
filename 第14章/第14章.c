/**************************** (2) ******************************/

/*
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>


struct common_year
	{
	char fullname[10];
	char abbr[4];
	unsigned int day;
	};

int main(void)
	{
	int ch;
	char str[10];
	unsigned int i;
	unsigned int years;
	unsigned int deadline;
	unsigned int date;
	unsigned int s;
	struct common_year year[12]=
		{
			{"JANUARY","JAN",31},
			{"FEBRUARY","FEB",28},	
			{"MARCH","MAR",31},
			{"APRIL","APR",30},
			{"MAY","MAY",31},
			{"JUNE","JUN",30},
			{"JULY","JUL",31},
			{"AUGUST","AUG",31},
			{"SEPTEMBER","SEP",30},
			{"OCTBER","OCT",31},
			{"NOVEMBER","NOV",30},
			{"DECEMBER","DEC",31}
		};

	printf("Enter date,month,year:\n");
	while((ch=getchar())!=EOF)
		{
		ungetc(ch,stdin);
		i=s=0;
	
		if(scanf("%u",&date)!=1)
			{
			printf("Error in \"day\"\n");
			return 0;
			}

		getchar();
		ch=getchar();
		if(ch<='9' && ch>'0')
			{
			ungetc(ch,stdin);
			if(scanf("%u",&deadline)!=1)
				{
				printf("Error in \"month\"\n");
				return 0;
				}
			}
		else
			{
			ungetc(ch,stdin);
			scanf("%s",str);
			if(strlen(str)==3)
				{
				while(str[i]!='\0')
					{
					str[i]=toupper(str[i]);
					i++;
					}
				
				for(i=0;i<12;i++)
					{
					if(strcmp(str,year[i].abbr)==0)
						break;
					}
				if(i==12)
					{
					printf("Error in month\n");
					return 0;
					}
				}
			else
				{
				while(str[i]!='\0')
					{
					str[i]=toupper(str[i]);
					i++;
					}
	
				for(i=0;i<12;i++)
					{
					if(strcmp(str,year[i].fullname)==0)
						break;
					}
				if(i==12)
					{
					printf("Error in month\n");
					return 0;
					}
				}
			deadline=i+1;
			}
			if(scanf("%u",&years)!=1)
				{
				printf("Error in \"year\"\n");
				return 0;
				}
		if(date>31)
			{
			printf("Error in \"date\"\n");
			return 0;
			}
		else if(deadline==2 && date>29)
			{
			printf("Error in February\n");
			return 0;
			}
		else if((deadline==4 || deadline==6 || deadline==9 || deadline==11) && date>30)
			{
			printf("Error in \"date\"\n");
			return 0;
			}
		if(years%400==0 || years%4==0)
			year[1].day=29;
		for(i=0;i<deadline-1;i++)
			s+=year[i].day;
		s += date;
		printf("Sum = %u\n",s);
		printf("Enter date,month,year:\n");
		while(getchar()!='\n')
			continue;
			}
	return 0;
	}
*/

/************************* (3) ****************************/

/*
#include<stdio.h>
#include<string.h>
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 100
struct book
	{
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
	};
void title_order(struct book library[],int count);
void value_order(struct book library[],int);
int main(void)
	{
	struct book library[MAXBKS];
	int count=0;
	int index;

	printf("Please enter the book title.\n");
	printf("Press [enter] at the start of the line to stop.\n");
	while(count<MAXBKS && gets(library[count].title)!=NULL && library[count].title[0]!='\0')
		{
		printf("Now enter the author.\n");
		gets(library[count].author);
		printf("Now enter the value.\n");
		scanf("%f",&library[count++].value);
		while(getchar()!='\n')
			continue;
		if(count<MAXBKS)
			printf("Enter the next title.\n");
		}
	if(count>0)
		{
		printf("Here is the list of your books:\n");
		for(index=0;index<count;index++)
			printf("%s by %s $%.2f\n",library[index].title,
					library[index].author,library[index].value);
		putchar('\n');
		title_order(library,count);
		putchar('\n');
		value_order(library,count);
		}
	else
		printf("No books?Too bad.\n");
	return 0;
	}
void title_order(struct book library[],int count)
	{
	int i,j;
	struct book temp;
	//冒泡排序
	for(i=0;i<count-1;i++)
		for(j=0;j<count-i-1;j++)
			{
			if(strcmp(library[j].title,library[j+1].title)>0)
				{
				temp=library[j];
				library[j]=library[j+1];
				library[j+1]=temp;
				}
			}
	printf("Ascending order (title):\n");
	for(i=0;i<count;i++)
		printf("%s by %s $%.2f\n",library[i].title,
					library[i].author,library[i].value);
	return;
	}
void value_order(struct book *library,int count)
	{
	int i,j;
	struct book temp;
	//直接排序
	for(i=0;i<count-1;i++)
		for(j=i+1;j<count;j++)
			{
			if(library[i].value>library[j].value)
				{
				temp=library[i];
				library[i]=library[j];
				library[j]=temp;
				}
			}
	printf("Ascending order (value):\n");
	for(i=0;i<count;i++)
		printf("%s by %s $%.2f\n",library[i].title,
					library[i].author,library[i].value);
	return;
	}
*/

/******************************** (5) *********************************/

/*
#include<stdio.h>
#include<stdlib.h>
#define CSIZE 4

struct name
	{
	char first[20];
	char last[20];
	};
struct student
	{
	struct name info;
	float grade[3];
	float average;
	};
int main(void)
	{
	struct student bor[CSIZE];
	int count;
	int i;
	int ch;

	printf("Enter the information of the student:\n");
	for(count=0;count<CSIZE;count++)
		{
		if((ch=getchar())==EOF)
			break;
		ungetc(ch,stdin);
		if(scanf("%s %s",bor[count].info.first,bor[count].info.last)!=2)
			{
			printf("Error in \"name\",input again\n");
			count--;
			continue;
			}
		if(scanf("%f %f %f",&bor[count].grade[0],&bor[count].grade[1],&bor[count].grade[2])!=3)
			{
			printf("Error in \"score\",input again\n");
			--count;
			continue;
			}
		while(getchar()!='\n')
			continue;
		}
	for(i=0;i<count;i++)
		{
		bor[i].average=0;
		for(ch=0;ch<3;ch++)
			 bor[i].average += bor[i].grade[ch];
		bor[i].average /=3;
		printf("%s %s:",bor[i].info.first,bor[i].info.last);
		printf("%.1f %.1f %.1f average=%.1f\n",bor[i].grade[0],bor[i].grade[1],bor[i].grade[2],bor[i].average);
		}
	return 0;
	}
*/

/******************************** (6) *************************************/

/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 19
struct baseball
	{
	char first[20];
	char last[20];
	size_t field;
	unsigned int beat;
	unsigned int walk;
	unsigned int RBI;
	};
int main(void)
	{
	size_t count=0;
	size_t i;
	size_t beat,walk,RBI,field;
	char first[20];
	char last[20];
	struct baseball player[MAX];
	FILE *fp;

	if((fp=fopen("baseball.txt","r"))==NULL)
		{
		fprintf(stderr,"Error in opening reading file[baseball.txt]\n");
		exit(EXIT_FAILURE);
		}
	for(i=0;i<MAX;i++)
		{
		player[i].beat=0;
		player[i].field=0;
		player[i].RBI=0;
		player[i].walk=0;
		player[i].first[0]='\0';
		}

	while(fscanf(fp,"%u %s %s %u %u %u %u",&i,first,last,&field,&beat,&walk,&RBI)==7)
		{
		player[i].beat +=beat;
		player[i].field += field;
		player[i].RBI += RBI;
		player[i].walk += walk;
		strcpy(player[i].first,first);
		strcpy(player[i].last,last);
		++count;
		}
	if(fclose(fp)!=0)
		fprintf(stderr,"Error in closing reading file [baseball.txt]\n");
	if(count==0)
		printf("Nothing?\n");
	else
		{
		for(i=0;i<MAX;i++)
			{
			if(player[i].first[0]!='\0')
				{
				printf("%u %s %s %u %u %u %u %.2f\n\n",i,player[i].first,
						player[i].last,player[i].field,player[i].beat,
						player[i].walk,player[i].RBI,(float)player[i].beat/player[i].field);
				}
			}
		}
	return 0;
	}
*/

/**************************** (7) *******************************/

//真正意义的删除是覆盖原有数据
/*
#include<stdio.h>
#include<stdlib.h>
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 10
struct book
	{
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
	};

int main(void)
	{
	struct book library[MAXBKS];
	size_t count=0;
	size_t del,upd;
	size_t index,filecount;
	FILE *pbooks;
	int size=sizeof(struct book);
	int ch,choice;

	if((pbooks=fopen("book.dat","r+b"))==NULL)
		{
		fputs("Can't open book.dat file\n",stderr);
		exit(1);
		}
	rewind(pbooks);
	while(count<MAXBKS && fread(&library[count],size,
			1,pbooks)==1)
		{
		if(count==0)
			puts("Current contents of book.dat: ");
		printf("%d.%s by %s: $%.2f\n",count+1,library[count].title,
			library[count].author,library[count].value);
		count++;
		}
	filecount=count;
	if(count==MAXBKS)
		{
		fputs("The book.dat file is full.",stderr);
		exit(2);
		}

	printf("1.add		2.delete\n");
	printf("3.update\n");
	printf("(Input \"ctrl+Z\" to the end.)\n");
	while((ch=getchar())!=EOF)
		{
		ungetc(ch,stdin);
		if((ch=getchar())=='1')
			{
			while(getchar()!='\n')
				continue;
			puts("Please add new book titles.");
			puts("Press [enter] at the start of a line to stop.");

			//gets()语句会丢弃回车
			while(count<MAXBKS && gets(library[count].title)!=NULL
							   && library[count].title[0]!='\0')
				{
				puts("Now enter the author.");
				gets(library[count].author);
				puts("Now enter the value.");
				scanf("%f",&library[count++].value);
				while(getchar()!='\n')//清除可能存在的错误数据
					continue;
				if(count<MAXBKS)
					puts("Enter the next title.");
				}
			}
		else if(ch=='2')//暂时无法完全删除。最后一个结构数组无法清除（原因，无法以空白覆盖多余项目）
			{
			while(getchar()!='\n')
				continue;
			printf("Input the serial number (you want to delete)\n");
			while(scanf("%u",&del)!=1 && del>count)
				{
				printf("Error.Input the number again.\n");
				while(getchar()!='\n')
					continue;
				}
			if(del<=filecount)
				--filecount;
			if(del<count)
				{
				for(index=del-1;index<count-1;index++)
					library[index]=library[index+1];
				}
			--count;
			}
		else if(ch=='3')
			{
			while(getchar()!='\n')
				continue;
			printf("Input the serial number (you want to update)\n");
			while(scanf("%u",&upd)!=1 || upd>count)
				{
				printf("Error.Input the number again.\n");
				while(getchar()!='\n')
					continue;
				}
			printf("1.title		2.author\n");
			printf("3.value\n");
			scanf("%d",&choice);
			while(getchar()!='\n')
					continue;
			switch(choice)
				{
				case 1:if(gets(library[upd-1].title)==NULL || library[upd-1].title[0]=='\0')
						  printf("Usage:\"title\"\n");
						  break;
				case 2:if(gets(library[upd-1].author)==NULL || library[upd-1].author[0]=='\0')
						  printf("Usage:\"author\"\n");
						  break;
				case 3:if(scanf("%f",&library[upd-1].value)!=1)
						   printf("Usage:\"value\"\n");
						  break;
				default:printf("Error in item\n");
				}
			}
		else
			{
			printf("Error in option.\n");
			printf("1.add		2.delete\n");
			printf("3.update\n");
			printf("(Input \"ctrl+Z\" to the end.)\n");
			if(ch=='\n')
				continue;
			while(getchar()!='\n')
				continue;
			continue;
			}
		if(count>0)
			{
			puts("Here is the list of your books:");
			for(index=0;index<count;index++)
				printf("%d.%s by %s: $%.2f\n",index+1,library[index].title,
						library[index].author,library[index].value);
			printf("1.add		2.delete\n");
			printf("3.update\n");
			printf("(Input \"ctrl+Z\" to the end.)\n");
			
			rewind(pbooks);
			fwrite(&library[0],size,count,pbooks);

			fclose(pbooks);
			if((pbooks=fopen("book.dat","r+b"))==NULL)
				{
				fputs("Can't open book.dat file\n",stderr);
				exit(1);
				}
			if(ch=='2')
				{
				getchar();
				continue;
				}
			continue;
			}
		else
			puts("No books? Too bad.\n");
		}
		puts("Bye.\n");
		fclose(pbooks);
	return 0;
	}
*/

/************************* (8) *****************************/

/*
//二进制模式
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define COL 5
#define LIMIT 30
struct flight
	{
	int number;
	char col;
	int empty;
	char first[LIMIT];
	char last[LIMIT];
	};
void menu(void);
void delete_col(void);
void function(char,struct flight [5][12]);
int main(void)
	{
	struct flight giant[COL][12];
	char ch;
	FILE *fp;
	int size,i,j;

	size=sizeof(struct flight);
	for(i=0;i<COL;i++)
		for(j=0;j<12;j++)
		{
		giant[i][j].col='a'+i;
		giant[i][j].empty=1;
		giant[i][j].number=j;
		strcpy(giant[i][j].first,"empty");
		strcpy(giant[i][j].last,"empty");
		}

	if((fp=fopen("giant.dat","r+b"))==NULL)
		{
		fprintf(stderr,"Error in opening file[giant.dat]\n");
		exit(EXIT_FAILURE);
		}
	fread(&giant[0][0],size,12*COL,fp);
	if(fclose(fp)!=0)
			fprintf(stderr,"Error in closing file[giant.dat]\n");

	printf("%12s	  %12s","seat number","rest");
	printf("    %30s %30s\n","first name","last name");			
			for(i=0;i<COL;i++)
				for(j=0;j<12;j++)
					if(giant[i][j].empty==1)
						printf("%5c%c%02d		%6s %30s %30s\n",' ',giant[i][j].col,giant[i][j].number,
						"empty",giant[i][j].first,giant[i][j].last);
	menu();
	while((ch=getchar())!='f')
		{
		if((fp=fopen("giant.dat","r+b"))==NULL)
			{
			fprintf(stderr,"Error in opening file[giant.dat]\n");
			exit(EXIT_FAILURE);
			}
		fread(&giant[0][0],size,12*COL,fp);
		function(ch,giant);
		rewind(fp);
		fwrite(&giant[0][0],size,12*COL,fp);
		if(fclose(fp)!=0)
			fprintf(stderr,"Error in closing file[giant.dat]\n");
		menu();
		}
	return 0;
	}
	void menu(void)
		{
		printf("To choose a function,enter its letter label:\n");
		printf("a) Show number of empty seats\n");
		printf("b) Show list of empty seats\n");
		printf("c) Show alphabetical list of seats\n");
		printf("d) Assign a customer to a seat assignment\n");
		printf("e) Delete a sit assignment\n");
		printf("f) Quit\n");
		return;
		}
	void delete_col(void)
		{
		while(getchar()!='\n')
			continue;
		}
	void function(char ch,struct flight giant[5][12])
		{
		int i,j,number;
		char col,cha;
		if(ch=='a')
			{
			printf("%12s\n","seat number");		
			for(i=0;i<COL;i++)
				for(j=0;j<12;j++)
					if(giant[i][j].empty==1)
					printf("%5c%c%02d\n",' ',giant[i][j].col,giant[i][j].number);
			delete_col();
			}
		if(ch=='b')
			{
			printf("%12s	  %12s","seat number","rest");
			printf("    %30s %30s\n","first name","last name");			
			for(i=0;i<COL;i++)
				for(j=0;j<12;j++)
					if(giant[i][j].empty==1)
						printf("%5c%c%02d		%6s %30s %30s\n",' ',giant[i][j].col,giant[i][j].number,
						"empty",giant[i][j].first,giant[i][j].last);
			delete_col();
			}
		if(ch=='c')
			{
			printf("%12s	  %12s","seat number","rest");
			printf("    %30s %30s\n","first name","last name");			
			for(i=0;i<COL;i++)
				for(j=0;j<12;j++)
					printf("%5c%c%02d		%6s %30s %30s\n",' ',giant[i][j].col,giant[i][j].number,
					giant[i][j].empty==1?"empty":"taken",giant[i][j].first,giant[i][j].last);
			delete_col();
			}
		if(ch=='d')
			{
			delete_col();
			printf("Input the seat you want to reserve(enter 'q' to quit):\n");
			if((cha=getchar())!='q')
				{
				ungetc(cha,stdin);
				scanf("%c%d",&col,&number);
				if(giant[col-'a'][number].empty==1)
					{
					delete_col();
					printf("Input your first name(enter 'q' to quit):\n");
					if((cha=getchar())!='q')
						{
						ungetc(cha,stdin);
						gets(giant[col-'a'][number].first);
						printf("Input your last name(enter 'q' to quit):\n");
						if((cha=getchar())!='q')
							{
							ungetc(cha,stdin);
							gets(giant[col-'a'][number].last);
							giant[col-'a'][number].empty=0;
							}
						else
							delete_col();
						}
					else
						delete_col();
					}
				else
					printf("The number has been reserved\n");
				}
			else
				delete_col();
			}
		if(ch=='e')
			{
			delete_col();
			printf("Input the number of sit assignment to delete(enter 'q' to quit)\n");
			if((cha=getchar())!='q')
				{
				ungetc(cha,stdin);
				scanf("%c%d",&col,&number);
				delete_col();
				if(giant[col-'a'][number].empty==0)
					{
					giant[col-'a'][number].empty=1;
					strcpy(giant[col-'a'][number].first,"empty");
					strcpy(giant[col-'a'][number].last,"empty");
					}
				else
					printf("This number was not be reserved\n");
				}
			}
			
		}
*/

/*************************** (9) *****************************/


//文本模式


//本计算机上（或是本软件？未知原因！），在初始化过程中（对于ptr_last或ptr_first），若每次循环后都释放内存，那么下次
//重新划分的内存依然是先前那一块
/*
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define LINE 5
#define COL 12
struct flight 
	{
	int empty;
	int number;
	char seat;
	char *first;
	char *last;
	};
//函数声明
void delete_line(void);
int menu_judge(char begin,char end,char option);
void str(struct flight *ptr,char option,int,FILE *);
void free_str(struct flight *ptr);
void first_menu(void);
void second_menu(void);
void function(int,struct flight [LINE][COL]);
void build_filename(char *const p);
void initialise(struct flight giant[LINE][COL]);
void second_menu(void);
//主函数
int main(void)
	{
	char filename[16];
	FILE *fp;
	struct flight giant[LINE][COL];
	int i,j,ch;

	initialise(giant);
	while(menu_judge('a','b','f'))
		{
		printf("Enter the flight number:\n");
		build_filename(filename);
		if( (fp=fopen(filename,"r+"))==NULL)
			{
			fprintf(stderr,"Error in opening file[%s]\n",filename);
			exit(EXIT_FAILURE);
			}
		
		for(i=0;i<LINE;i++)
			for(j=0;j<COL;j++)
				{
				fscanf(fp,"%d%c%d",&giant[i][j].number,&giant[i][j].seat,&giant[i][j].empty);
				str(&giant[i][j],'f',0,fp);
				str(&giant[i][j],'l',0,fp);
				}
		
		
		while(ch=menu_judge('a','g','s'))
			{
			printf("YOU ARE OPERATING FLIGHT %c%c%c:\n",filename[6],filename[7],filename[8]);
 			function(ch,giant);
			if(ch=='e')
				{
				rewind(fp);//回到文件开头位置
				for(i=0;i<LINE;i++)
					for(j=0;j<COL;j++)
						fprintf(fp,"%d%c %d %s %s\n",giant[i][j].number,giant[i][j].seat,
										  giant[i][j].empty,giant[i][j].first,giant[i][j].last);
				if(fclose(fp)!=0)
					fprintf(stderr,"Error in closing file[%s]\n",filename);
				printf("Successfully confirm.\n");
	
				if( (fp=fopen(filename,"r+"))==NULL)
					{
					fprintf(stderr,"Error in opening file[%s]\n",filename);
					exit(EXIT_FAILURE);
					}
				}
			}

		
		if(fclose(fp)!=0)
			fprintf(stderr,"Error in closing file[%s]\n",filename);
		getchar();//删去回车(直接按'g'产生的）
		}
	return 0;
	}
//子函数
void delete_line(void)
	{
	while(getchar()!='\n')
		continue;
	}
int menu_judge(char begin,char end,char option)
	{
	char choice;

	if(option=='f')
		first_menu();
	if(option=='s')
		second_menu();
	while((choice=getchar())!=end)
		{
		if(choice>=begin && choice<end)
			{
			if(getchar()=='\n')
				{
				return choice;
				}
			else
				{
				printf("Error.Only one alphabet\n");
				if(choice=='\n')
					continue;
				delete_line();
				continue;
				}
			}
		else
			{
			printf("Error.Enter again\n");
			if(choice=='\n')
				continue;
			delete_line();
			continue;
			}
		
		}
	return 0;
	}

void first_menu(void)
	{
	printf("To choose a function,enter its letter label:\n");
	printf("a)Choose the flight	b)Quit\n");
	}
void second_menu(void)
	{
	printf("To choose a function,enter its letter label:\n");
	printf("a) Show number of empty seats\n");
	printf("b) Show list of empty seats\n");
	printf("c) Show alphabetical list of seats\n");
	printf("d) Assign a customer to a seat assignment\n");
	printf("e) Confirm the seat arrangment(Very important.)\n");
	printf("f) Delete a sit assignment\n");
	printf("g) Return to superior menu\n");
	}
void function(int ch,struct flight giant[LINE][COL])
	{
		int i,j;
		int number;
		char seat;
		char cha;

*/		//这个语句暂时想不出哪里可以放
		/*
		if(number<6 && seat<'m')
			free_str(&giant[number-1][seat-'a']);//在写入文件后释放内存
		*/

/*
		if(ch=='a')
			{
			printf("%12s\n","seat number");		
			for(i=0;i<LINE;i++)
				for(j=0;j<COL;j++)
					if(giant[i][j].empty==1)
					printf("%5c%02d%c\n",' ',giant[i][j].number,giant[i][j].seat);
			}
		if(ch=='b')
			{
			printf("%12s	  %12s","seat number","rest");
			printf("    %30s %30s\n","first name","last name");			
			for(i=0;i<LINE;i++)
				for(j=0;j<COL;j++)
					if(giant[i][j].empty==1)
						printf("%5c%02d%c		%6s %30s %30s\n",' ',giant[i][j].number,giant[i][j].seat,
						"empty",giant[i][j].first,giant[i][j].last);
			}
		if(ch=='c')
			{
			printf("%12s	  %12s","seat number","rest");
			printf("    %30s %30s\n","first name","last name");			
			for(i=0;i<LINE;i++)
				for(j=0;j<COL;j++)
					printf("%5c%02d%c		%6s %30s %30s\n",' ',giant[i][j].number,giant[i][j].seat,
					giant[i][j].empty==1?"empty":"taken",giant[i][j].first,giant[i][j].last);
			}
		if(ch=='d')
			{
			printf("Input the seat you want to reserve(enter 'q' to quit):\n");
			//若此时输入字母，显示出现错误
			if((cha=getchar())!='q')
				{
				ungetc(cha,stdin);
				scanf("%d%c",&number,&seat);
				if(giant[number-1][seat-'a'].empty==1)
					{
					delete_line();
					printf("Input your first name(enter 'q' to quit):\n");
					if((cha=getchar())!='q')
						{
						ungetc(cha,stdin);
						str(&giant[number-1][seat-'a'],'f',0,stdin);
						printf("Input your last name(enter 'q' to quit):\n");
						if((cha=getchar())!='q')
							{
							ungetc(cha,stdin);
							str(&giant[number-1][seat-'a'],'l',0,stdin);
							giant[number-1][seat-'a'].empty=0;
							delete_line();//消除last_name的回车号
							}
						else
							delete_line();
						}
					else
						delete_line();
					}
				else
					{
					if(giant[number-1][seat-'a'].empty==0)
						printf("The number has been reserved\n");
					else
						printf("The number don't exist\n");
					delete_line();//消除输入错误的座位号
					}
				}
			else
				delete_line();
			}
		if(ch=='f')
			{
			printf("Input the number of sit assignment to delete(enter 'q' to quit)\n");
			if((cha=getchar())!='q')
				{
				ungetc(cha,stdin);
				scanf("%d%c",&number,&seat);
				delete_line();
				if(giant[number-1][seat-'a'].empty==0)
					{
					giant[number-1][seat-'a'].empty=1;
					str(&giant[number-1][seat-'a'],'f',1,stdin);
					str(&giant[number-1][seat-'a'],'l',1,stdin);
					}
				else
					{
					if(giant[number-1][seat-'a'].empty==1)
						printf("This number was not be reserved\n");
					else
						printf("The number don't exist\n");
					}
				}
			delete_line();//删除直接输入'q'的响应
			}
		return;
		}
void str(struct flight *ptr,char option,int initial,FILE *sort)
	{
	char temp[20];
	
	if(initial==0)//读写文件信息
		{
		if(fscanf(sort,"%s",&temp)==1)
			{
			if(option=='f')
				{
				ptr->first=(char *)malloc(strlen(temp)+1);
				strcpy(ptr->first,temp);
				}
			if(option=='l')
				{
				ptr->last=(char *)malloc(strlen(temp)+1);
				strcpy(ptr->last,temp);
				}
			}
		}
	else
		{
		strcpy(temp,"empty");
		if(option=='f')
			{
			ptr->first=(char *)malloc(strlen(temp)+1);
			strcpy(ptr->first,temp);
			}
		if(option=='l')
			{
			ptr->last=(char *)malloc(strlen(temp)+1);
			strcpy(ptr->last,temp);
			}
		
		}
	}
void initialise(struct flight giant[LINE][COL])
	{
	int i,j;
	for(i=0;i<LINE;i++)
		for(j=0;j<COL;j++)
			{
			giant[i][j].seat='a'+j;
			giant[i][j].empty=1;
			giant[i][j].number=i+1;
			str(&giant[i][j],'f',1,stdin);
			str(&giant[i][j],'l',1,stdin);
			}
	}
void build_filename(char * const p)
	{
	char number[5];
	strcpy(p,"flight");
	gets(number);
	strcat(p,number);
	strcat(p,".txt");
	}
void free_str(struct flight *ptr)
	{
	free(ptr->first);
	free(ptr->last);
	}
*/

/*************************** (10) *****************************/

/*
#include<stdio.h>
void add(int,int);
void subtract(int,int);
void multiply(int,int);
void divide(int,int);

int main(void)
	{
	int a,b,c;
	void (*p[4])(int,int);
	p[0]=add;
	p[1]=subtract;
	p[2]=multiply;
	p[3]=divide;
	
	printf("Enter two integers:\n");
	scanf("%d %d",&a,&b);
	printf("0) add		    1)subtract\n");
	printf("2) multiply	    3)divide\n");
	scanf("%d",&c);
	p[c](a,b);
	}
void add(int a,int b)
	{
	printf("%d\n",a+b);
	}
void subtract(int a,int b)
	{
	printf("%d\n",a-b);
	}
void multiply(int a,int b)
	{
	printf("%d\n",a*b);
	}
void divide(int a,int b)
	{
	printf("%d\n",a/b);
	}
*/

/****************************** (11) ********************************/
#include<stdio.h>
#include<math.h>
void transform(double *,double *,int,double(double));
double mysin(double);
int main(void)
	{
	double source[100];
	double target[100];
	int i;

	for(i=0;i<100;i++)
		source[i]=i;
	transform(source,target,100,sin);
	printf("\n\n");
	transform(source,target,100,mysin);
	return 0;
	}
void transform(double *source,double *target,int n,double function(double))
	{
	int i;
	for(i=0;i<n;i++)
		{
		target[i]=function(source[i]);
		printf("%6.2f",target[i]);
		if(i&8==7)
			putchar('\n');
		}
	}
double mysin(double source)
	{
	double target;

	target=sqrt(1-pow(cos(source),2));
	if((cos(source)>0 && tan(source)>0) || (cos(source)<0 && tan(source)<0))
		return target;
	else
		return -target;
	}

