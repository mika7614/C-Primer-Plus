/********************************* 程序清单13.4 ************************************/

/*
#include<stdio.h>
#define MAXLINE 20
int main(void)
	{
	char line[MAXLINE];

	while(fgets(line,MAXLINE,stdin)!=NULL && line[0]!='\n')
		fputs(line,stdout);
	return 0;
	}
*/

/********************************** 复习题 **************************************/

/********************************** (4) 答案 ************************************/

/*
#include<stdio.h>
#include<stdlib.h>

int main(int argc,char * argv[])
	{
	FILE *fp;
	double n;
	double sum=0.0;
	int ct=0;

	if(argc==1)
		fp=stdin;
	else if(argc==2)
		{
		if((fp=fopen(argv[1],"r"))==NULL)
			{
			fprintf(stderr,"Can't open %s\n",argv[1]);
				exit(EXIT_FAILURE);
			}
		}
	else
		{
		fprintf(stderr,"Usage:%s [filename]\n",argv[0]);
		exit(EXIT_FAILURE);
		}
	while(fscanf(fp,"%lf",&n)==1)
		{
		sum += n;
		++ct;
		}
	if(ct>0)
		printf("Average of %d values = %f\n",ct,sum/ct);
	else
		printf("No valid data.\n");
	return 0;
	}
*/

/***************************** (5) 前期自编，后期答案 *****************************/

/*
#include<stdio.h>
#include<stdlib.h>
#define BUF 256

int has_ch(char ch,const char *line);
int main(int argc,char *argv[])
	{
	FILE *fp;
	char ch;
	char line[BUF];

	if(argc==3)
		{
		if((fp=fopen(argv[2],"r"))==NULL)
			{
			fprintf(stderr,"Can't open %s\n",argv[2]);
			exit(EXIT_FAILURE);
			}
		}
	else
		{
		fprintf(stderr,"Usage:%s [filename]\n",argv[0]);
		exit(EXIT_FAILURE);
		}
	ch=argv[1][0];
	while(fgets(line,BUF,fp)!=NULL)//假设BUF够大（大于一行的最大容纳数），一遇到回车就停止输入
		{
		if(has_ch(ch,line))
			fputs(line,stdout);
		}
	fclose(fp);
	return 0;
	}
int has_ch(char ch,const char *line)
	{
	while(*line)//指针line不断检查
		if(ch==*line++)
			return 1;
	return 0;
	}
*/

/*************************** 编程练习 ******************************/

/*************************** (1) ******************************/

/*
#include<stdio.h>
#include<stdlib.h>
int main(void)
	{
	int ch;
	FILE *fp;
	long count=0;
	char filename[20];

	gets(filename);
	if((fp=fopen(filename,"r"))==NULL)
		{
		printf("Can't open %s\n",filename);
		exit(1);
		}
	while((ch=getc(fp))!=EOF)
		{
		putc(ch,stdout);
		count++;
		}
	fclose(fp);
	printf("File %s has %ld characters\n",filename,count);
	return 0;
	}
*/

/************************** (2) ****************************/

/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 1024

int main(int argc,char *argv[])
	{
	FILE *in,*out;
	char source[MAX];
	size_t byte;

	if(argc!=3)
		{
		fprintf(stderr,"Usage:%s [filename]\n",argv[0]);
		exit(EXIT_FAILURE);
		}
	if((in=fopen(argv[1],"r"))==NULL)
		{
		fprintf(stderr,"Can't open file %s\n",argv[1]);
		exit(EXIT_FAILURE);
		}
	byte=fread(source,sizeof(char),MAX,in);//有点儿机械,八成会出问题
	fclose(in);
	if((out=fopen(argv[2],"w"))==NULL)
		{
		fprintf(stderr,"Can't open file %s\n",argv[2]);
		exit(EXIT_FAILURE);
		}
	fwrite(source,sizeof(char),byte,out);//fwrite(source,strlen(source),1,out);（原版本）
	fclose(out);
	return 0;
	}
*/

/*************************** (3) ********************************/

/*
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define LIMIT 40

int main(void)
	{
	char src_file[LIMIT];
	char tar_file[LIMIT];
	FILE *in,*out;
	char ch;

	printf("Enter the name of source file:");
	gets(src_file);
	printf("\nEnter the name of target file:");
	gets(tar_file);
	if((in=fopen(src_file,"r"))==NULL)
		{
		printf("\nCan't open file [%s]",src_file);
		exit(EXIT_FAILURE);
		}
	if((out=fopen(tar_file,"w"))==NULL)
		{
		printf("\nCan't open file [%s]",tar_file);
		exit(EXIT_FAILURE);
		}
	while((ch=getc(in))!=EOF)
		putc(toupper(ch),out);
	fclose(in);
	fclose(out);
	return 0;
	}
*/

/*************************** (4) *****************************/

/*
#include<stdio.h>
#include<stdlib.h>
#define MAX 256

int main(int argc,char *argv[])
	{
	FILE *fp;
	int i;
	char temp[MAX];

	if(argc==1)
		{
		printf("Lack of file name.\n");
		exit(EXIT_FAILURE);
		}
	for(i=1;i<argc;i++)
		{
		printf("File[%s]:\n",argv[i]);
		if((fp=fopen(argv[i],"r"))==NULL)
			{
			printf("Can't open file[%s]\n",argv[i]);
			exit(EXIT_FAILURE);
			}
		while(fgets(temp,MAX,fp)!=NULL)
			fputs(temp,stdout);
		putchar('\n');
		fclose(fp);
		}
	return 0;
	}
*/

/******************************* (5) ********************************/

/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define BUFSIZE 1024
#define SLEN 81
void append(FILE *source,FILE *dest);

int main(int argc,char *argv[])
	{
	FILE *fa,*fs;
	int files=0;
	int i;

	if(argc<=2)
		{
		printf("Usage:%s [filename]\n",argv[0]);
		exit(EXIT_FAILURE);
		}
	if((fa=fopen(argv[1],"a"))==NULL)
		{
		fprintf(stderr,"Can't open %s\n",argv[1]);
		exit(EXIT_FAILURE);
		}
	if(setvbuf(fa,NULL,_IOFBF,BUFSIZE)!=0)
		{
		fputs("Can't create output buffer\n",stderr);
		exit(EXIT_FAILURE);
		}
	for(i=2;i<argc;i++)
		{
		if(strcmp(argv[1],argv[i])==0)
			fputs("Can't append file to itself\n",stderr);
		else if((fs=fopen(argv[i],"r"))==NULL)
			fprintf(stderr,"Can't open file %s\n",argv[i]);
		else
			{
			if(setvbuf(fs,NULL,_IOFBF,BUFSIZE)!=0)
				{
				fputs("Can't create input buffer\n",stderr);
				continue;
				}
			append(fs,fa);
			if(ferror(fs)!=0)
				fprintf(stderr,"Error in reading file %s.\n",argv[1]);
			if(ferror(fa)!=0)
				fprintf(stderr,"Error in writing file %s.\n",argv[i]);
			fclose(fs);
			files++;
			printf("File %s appended.\n",argv[i]);
			}
		}
	printf("Done. %d %s appended.\n",files,(files>1)?"files":"file");
	return 0;
	}
void append(FILE *source,FILE *dest)
	{
	size_t bytes;
	static char temp[BUFSIZE];

	while((bytes=fread(temp,sizeof(char),BUFSIZE,source))>0)
		fwrite(temp,sizeof(char),bytes,dest);
	return;
	}
*/

/***************************** (6) *******************************/

/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LEN 40
int main(void)
	{
	FILE *in,*out;
	int ch;
	char target[LEN];
	char source[LEN];
	int count=0;

	puts("Enter the source file name([filename].file format)");
	if(gets(source)==NULL || source[0]=='\0')
		{
		fprintf(stderr,"Syntax error:File name\n");
		exit(EXIT_FAILURE);
		}

	puts("Enter the target file name([filename].file format)");
	if(gets(target)==NULL || target[0]=='\0')
		{
		fprintf(stderr,"Syntax error:File name\n");
		exit(EXIT_FAILURE);
		}
	if((in=fopen(source,"r"))==NULL)
		{
		fprintf(stderr,"I couldn't open the file\"%s\"\n",source);
		exit(EXIT_FAILURE);
		}

	if((out=fopen(target,"w"))==NULL)
		{
		fprintf(stderr,"Can't open output file.\n");
		exit(EXIT_FAILURE);
		}
	while((ch=getc(in))!=EOF)
		if(count++ % 3 ==0)//这个语句不适用于中文
			putc(ch,out);
	if(fclose(in)!=0 || fclose(out)!=0)
		fprintf(stderr,"Error in closing files\n");
	return 0;
	}
*/

/***************************** (7) ******************************/

/*
#include<stdio.h>
#include<stdlib.h>
#define MAX 256

void print(FILE *print1,FILE *print2);
int main(int argc,char *argv[])
	{
	FILE *print1,*print2;

	if(argc!=3)
		{
		fprintf(stderr,"Usage:%s [filename]\n",argv[0]);
		exit(EXIT_FAILURE);
		}
	if((print1=fopen(argv[1],"r"))==NULL)
		{
		fprintf(stderr,"Can't open file [%s]\n",argv[1]);
		exit(EXIT_FAILURE);
		}
	if((print2=fopen(argv[2],"r"))==NULL)
		{
		fprintf(stderr,"Can't open file [%s]\n",argv[2]);
		exit(EXIT_FAILURE);
		}
	print(print1,print2);
	if(ferror(print1)!=0)
			fprintf(stderr,"Error in reading file %s.\n",argv[1]);
	if(ferror(print2)!=0)
			fprintf(stderr,"Error in reading file %s.\n",argv[2]);
	if(fclose(print1)!=0 || fclose(print2)!=0)
		fprintf(stderr,"Error in closing files\n");
	return 0;
	}
void print(FILE *print1,FILE *print2)
	{
	//版本1
	
	int ch1,ch2;

	ch1=getc(print1);
	ch2=getc(print2);
	while(ch1!=EOF || ch2!=EOF)//当第一个条件成立，根本就不检查第二个
		{
		while(ch1 != '\n' && ch1!=EOF)
			{
			putc(ch1,stdout);
			ch1=getc(print1);
			}
		putchar('\n');

		while(ch2 != '\n' && ch2!=EOF)
			{
			putc(ch2,stdout);
			ch2=getc(print2);
			}
		putchar('\n');
		
		if(ch1!=EOF)
			ch1=getc(print1);
		if(ch2!=EOF)
			ch2=getc(print2);
		}
	


	//版本2
	
	char *p1,*p2;
	char str1[MAX];
	char str2[MAX];
	p1=fgets(str1,MAX,print1);
	p2=fgets(str2,MAX,print2);
	while(p1 || p2)
		{
		if(p1)
			{
			fputs(str1,stdout);
			p1=fgets(str1,MAX,print1);
			}
		if(p1==NULL && p2!=NULL)
			putchar('\n');
		if(p2)
			{
			fputs(str2,stdout);
			p2=fgets(str2,MAX,print2);
			}
		if(!p2)
			putchar('\n');
		}
	
	return;
	}
*/

/***************************** (8) ********************************/

/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 512

int main(int argc,char *argv[])
	{
	FILE *fp;
	int i;
	int ch;
	int calculate=0;

	if(argc<2)
		{
		fprintf(stderr,"Usage:%s [filename]\n",argv[0]);
		exit(EXIT_FAILURE);
		}
	if(strlen(argv[1])>1)
		{
		fprintf(stderr,"Usage:%s [character]\n",argv[1]);
		exit(EXIT_FAILURE);
		}
	if(argc==2)
		{
		ch=getc(stdin);
		while(ch!=EOF)
			{
			if(ch==argv[1][0])
				calculate++;
			ch=getc(stdin);
			}
		fprintf(stdout,"\'%c\'in stdin:%d\n",argv[1][0],calculate);
		}
	else
		{
		for(i=2;i<argc;i++)
			{
			if((fp=fopen(argv[i],"r"))==NULL)
				{
				fprintf(stderr,"Can't open file [%s]\n",argv[i]);
				continue;
				}
			else
				{
				calculate=0;
				ch=getc(fp);
				while(ch!=EOF)
					{
					if(ch==argv[1][0])
					calculate++;
					ch=getc(fp);
					}
				fprintf(stdout,"\'%c\'in file[%s]:%d\n",argv[1][0],argv[i],calculate);
				}
			if(ferror(fp)!=0)
				fprintf(stderr,"Error in reading file[%s]\n",argv[i]);
			if(fclose(fp)!=0)
				fprintf(stderr,"Can't close the file[%s]\n",argv[i]);
			}
		}
	return 0;
	}
*/

/******************************* (9) ********************************/

/*
#include<stdio.h>
#include<stdlib.h>
#define MAX 40
int main(void)
	{
	FILE *fp;
	char words[MAX];
	int i=0;
	
	if((fp=fopen("words","a+"))==NULL)//若为"w"模式，什么都没显示
		{
		fprintf(stdout,"Can't open \"words\" file.\n");
		exit(1);
		}
	puts("Enter word to add to the file:press the Enter");
	puts("key at the beginning of a line to terminate.");
	while(gets(words)!=NULL && words[0]!='\0')
		fprintf(fp,"%s ",words);
	puts("File contents: ");
	rewind(fp);
	while(fscanf(fp,"%s",words)==1)
		{
		i++;
		printf("%d.",i);
		puts(words);
		}
	if(fclose(fp)!=0)
		fprintf(stderr,"Error in closing file\n");
	return 0;
	}
*/

/************************* (10) **************************/

/*
#include<stdio.h>
#include<string.h>//每当使用strlen()测量文件中字符串（先存到字符数组中）的长度，结果总是过大
#include<stdlib.h>
#define LIMIT 40
#define MAX 256
int main(void)
	{
	long count=1L;
	long max;
	FILE *fp;
	char filename[LIMIT];
	char file[MAX];
	char ch;
	int i=0;
	char *find;

	puts("Enter the file name:");
	while(fgets(filename,LIMIT,stdin)==NULL || filename[0]=='\n')//若按回车，程序异常。原因未知（原因已知，应用"||",而不是"&&"
		{
		fprintf(stdout,"Error in filename.\n");
		printf("Enter again.\n");
		}
	find=strchr(filename,'\n');
	if(find)
		*find='\0';
	if((fp=fopen(filename,"r"))==NULL)
		{
		fprintf(stderr,"Error in opening reading file [%s]\n",filename);
		exit(EXIT_FAILURE);
		}
	printf("Enter a integer\n");

	while((ch=getc(fp))!=EOF)//此处若用'\0'，则程序错误
		{
		file[i]=ch;
		i++;
		}
	max=(long)i;
	while((ch=getchar())<='9' && ch>='0')
		{
		ungetc(ch,stdin);
		while(scanf("%li",&count)!=1)
			{
			printf("Enter again.\n");
			while(getchar()!='\n')
				continue;
			}
		if(count>=max)//check1.txt 在测量中的问题：长度小于实际值
			{
			printf("Too big.(<%d)\n",max);
			continue;
			}
		fseek(fp,count,SEEK_SET);//文件位置指示符八成从非空白字符开始（猜测）
		fgets(file,MAX,fp);//应把最后一个字符置换为'\0'
		fputs(file,stdout);//check1.txt 输出过程中遇到的问题：最开始的空格未输出
		while(getchar()!='\n')
				continue;
		}
		if(fclose(fp)!=0)
			fprintf(stderr,"Error in closing reading file[%s]\n",filename);
	return 0;
	}
*/

/**************************** (11) *****************************/

/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 256

int main(int argc,char *argv[])
	{
	int i=0;
	FILE *fp;
	char str[MAX];

	if(argc<3)
		{
		fprintf(stderr,"Usage:%s[filename]\n",argv[0]);
		exit(EXIT_FAILURE);
		}
	if(strlen(argv[1])<2)
		{
		fprintf(stderr,"Error in %s[string]\n",argv[1]);
		exit(EXIT_FAILURE);
		}
	if((fp=fopen(argv[2],"r"))==NULL)
		{
		fprintf(stderr,"Error in opening file[%s]\n",argv[2]);
		exit(EXIT_FAILURE);
		}
	while(fgets(str,MAX,fp)!=NULL)
		{
		if(strstr(str,argv[1])!=NULL)
			{
			fputs(str,stdout);
			++i;
			}
		}
	if(i==0)
		printf("Not found in the file[%s]\n",argv[2]);
	if(fclose(fp)!=0)
		fprintf(stderr,"Error in closing file[%s]\n",argv[2]);
	return 0;
	}
*/

/**************************** (12) (13) ******************************/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>

#define LN 20
#define COL 30
#define DEAL_COL 31
#define LIMIT 40

void eliminate_impulse(unsigned int array[][COL]);
void rand_initial(size_t (*array)[COL]);
void str_deal(size_t array[][COL],char (*str)[DEAL_COL]);

int main(void)
	{
	FILE *in,*out;
	char *find;
	unsigned int array[LN][COL];
	unsigned int i,j;
	char str[LN][DEAL_COL];
	char filename1[LIMIT];
	char filename2[LIMIT];

	fputs("Enter the filename(initial):\n",stdout);
	while(fgets(filename1,LIMIT,stdin)==NULL || filename1[0]=='\n')
		{
		fprintf(stderr,"Error in filename[%s]\n",filename1);
		puts("Enter again.");
		}
	find=strchr(filename1,'\n');
	if(find)
		*find='\0';
	if((in=fopen(filename1,"w"))==NULL)
		{
		fprintf(stderr,"Error in opening file[%s]\n",filename1);
		exit(EXIT_FAILURE);
		}
		rand_initial(array);
		for(i=0;i<LN;i++)
			{
			for(j=0;j<COL;j++)
				{
				fprintf(in,"%2d",array[i][j]);
				}
			fprintf(in,"\n");
			}
		if(fclose(in)!=0)
			fprintf(stderr,"Error in closing file[%s]\n",filename1);

		eliminate_impulse(array);

	fputs("Enter the filename(image):\n",stdout);
	while(fgets(filename2,LIMIT,stdin)==NULL || filename2[0]=='\n')
		{
		fprintf(stderr,"Error in filename[%s]\n",filename2);
		puts("Enter again.");
		}
	find=strchr(filename2,'\n');
	if(find)
		*find='\0';
	if((out=fopen(filename2,"w"))==NULL)
		{
		fprintf(stderr,"Error in opening file[%s]\n",filename2);
		exit(EXIT_FAILURE);
		}
		str_deal(array,str);
		for(i=0;i<LN;i++)
			{
			fputs(str[i],out);
			fprintf(out,"\n");
			}
		if(fclose(out)!=0)
			fprintf(stderr,"Error in closing file[%s]\n",filename2);
	return 0;
	}
void rand_initial(unsigned int (*array)[COL])
	{
	unsigned int algorism(void);
	unsigned int i,j;

	srand((unsigned int)time(0));
	for(i=0;i<LN;i++)
		for(j=0;j<COL;j++)
			array[i][j]=algorism();
	return;
	}
unsigned int algorism(void)
	{
	unsigned int al;
	al=rand()%10;
	return al;
	
	}
void str_deal(unsigned int array[][COL],char (*str)[DEAL_COL])
	{
	unsigned int i,j;
	for(i=0;i<LN;i++)
		for(j=0;j<DEAL_COL;j++)
			{
			if(j<COL)
				{
				switch(array[i][j])
					{
					case 0:str[i][j]=' ';
							break;
					case 1:str[i][j]='.';
							break;
					case 2:str[i][j]='\'';
							break;
					case 3:str[i][j]=':';
							break;
					case 4:str[i][j]='_';
							break;
					case 5:str[i][j]='*';
							break;
					case 6:str[i][j]='=';
							break;
					case 7:str[i][j]='~';
							break;
					case 8:str[i][j]='%';
							break;
					case 9:str[i][j]='#';
							break;
					default:fprintf(stderr,"Error in \"array\"\n");
							exit(EXIT_FAILURE);
					}
				}
			else if(j==COL)
				str[i][j]='\0';
			else
				{
				fprintf(stderr,"Error in function \"str_deal\" \n");
				exit(EXIT_FAILURE);
				}
			}
	return;
	}
void eliminate_impulse(unsigned int array[][COL])
	{
	size_t judge(double average);
	unsigned int i,j;
	FILE *fp;

	for(i=0;i<LN;i++)
		for(j=0;j<COL;j++)
			{
			if(i!=0 && i!=LN-1 && j!=0 && j!=COL-1)
				{
				if(abs(array[i][j]-array[i-1][j])>1 &&
					abs(array[i][j]-array[i][j-1])>1 &&
					abs(array[i][j]-array[i+1][j])>1 &&
					abs(array[i][j]-array[i][j+1])>1)
					array[i][j]=judge((double)(array[i-1][j]+array[i][j-1]
					+array[i+1][j]+array[i][j+1])/4);
				continue;
				}
			if(j!=0 && j!=COL-1 && i==0)
				{
				if(abs(array[i][j]-array[i+1][j])>1 &&
					abs(array[i][j]-array[i][j-1])>1 &&
					abs(array[i][j]-array[i][j+1])>1)
					array[i][j]=judge((double)(array[i+1][j]+array[i][j-1]
					+array[i][j+1])/3);
				continue;
				}
			if(j!=0 && j!=COL-1 && i==LN-1)
				{
				if(abs(array[i][j]-array[i-1][j])>1 &&
					abs(array[i][j]-array[i][j-1])>1 &&
					abs(array[i][j]-array[i][j+1])>1)
					array[i][j]=judge((double)(array[i-1][j]+array[i][j-1]
					+array[i][j+1])/3);
				continue;
				}
			if(i!=0 && i!=LN-1 && j==0)
				{
				if(abs(array[i][j]-array[i-1][j])>1 &&
					abs(array[i][j]-array[i+1][j])>1 &&
					abs(array[i][j]-array[i][j+1])>1)
					array[i][j]=judge((double)(array[i-1][j]
					+array[i+1][j]+array[i][j+1])/3);
				continue;
				}
			if(i!=0 && i!=LN-1 && j==COL-1)
				{
				if(abs(array[i][j]-array[i-1][j])>1 &&
					abs(array[i][j]-array[i][j-1])>1 &&
					abs(array[i][j]-array[i+1][j])>1)
					array[i][j]=judge((double)(array[i-1][j]+array[i][j-1]
					+array[i+1][j])/3);
				continue;
				}
			if(i==0 && j==0)
				{
				if(abs(array[i][j]-array[i+1][j])>1 &&
					abs(array[i][j]-array[i][j+1])>1)
					array[i][j]=judge((double)(array[i+1][j]+array[i][j+1])/2);
				continue;
				}
			if(i==0 && j==COL-1)
				{
				if(abs(array[i][j]-array[i][j-1])>1 &&
					abs(array[i][j]-array[i+1][j])>1)
					array[i][j]=judge((double)(array[i][j-1]+array[i+1][j])/2);
				continue;
				}
			if(i==LN-1 && j==0)
				{
				if(abs(array[i][j]-array[i-1][j])>1 &&
					abs(array[i][j]-array[i][j+1])>1)
					array[i][j]=judge((double)(array[i-1][j]+array[i][j+1])/2);
				continue;
				}
			if(i==LN-1 && j==COL-1)
				{
				if(abs(array[i][j]-array[i-1][j])>1 &&
					abs(array[i][j]-array[i][j-1])>1)
					array[i][j]=judge((double)(array[i-1][j]+array[i][j-1])/2);
				continue;
				}
			}
		if((fp=fopen("eliminate_impulse.txt","w"))==NULL)
			{
			fprintf(stderr,"Error in opening file[eliminate_impulse.txt]\n");
			exit(EXIT_FAILURE);
			}

		for(i=0;i<LN;i++)
			{
			for(j=0;j<COL;j++)
				{
				fprintf(fp,"%2d",array[i][j]);
				}
			fprintf(fp,"\n");
			}
		if(fclose(fp)!=0)
			fprintf(stderr,"Error in closing file[eliminate_impulse.txt]\n");
	return;
	}
size_t judge(double average)
	{
	if(average-(size_t)average>0.5)
		return ( (size_t)average+1);
	else
		return ( (size_t)average);
	}
