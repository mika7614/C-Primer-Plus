/**********************************8.11�����ϰ************************************/

/***********************************�ڣ�1����************************************/

/*
#include<stdio.h>
int main(void)
	{
	char ch;
	int n=0;
	while((ch=getchar())!=EOF)
		{
		putchar(ch);
		n++;
		}
	printf("Characters is %0d\n",n);
	return 0;
	}
*/

/******************************��(2)��**********************************/


#include<stdio.h>
int main(void)
	{
	char ch;
	int n=0;//'n'����forѭ��
	while((ch=getchar())!=EOF)
		{
		if(ch=='\n') printf("\'\\n\'");
			else if(ch=='\t') printf("\'\\t\'");
			else if(ch>=32&&ch<=126) putchar(ch);
		else printf("^%c",ch+64);
		printf(" %0d  ",ch);
		if(++n%10==0) printf("\n");
		}
	return 0;
	}


/*****************************��(3)��*****************************/

/*
#include<stdio.h>
#include<ctype.h>
int main(void)
	{
	char ch;
	int small,big;
	small=big=0;
	while((ch=getchar())!=EOF)
		{
		if(islower(ch)!=0) small++;
		if(isupper(ch)!=0) big++;
		}
	printf("Capital is %0d," ,big);
	printf("lowcase is %0d\n",small);
	return 0;
	}
*/

/*****************************��(4)��*******************************/

/*
#include<stdio.h>
#include<ctype.h>
int main(void)
	{
	int n;//ͳ����ĸ����
	int logic=1;//�Ƿ��ڵ�����
	int words;//ͳ�Ƶ��ʸ���
	char prev=' ';//ǰһ������
	char ch;
	n=words=0;
	while((ch=getchar())!=EOF)
			{
			if(isalpha(prev)!=0 && isalpha(ch)==0)
				words++;
			if(isalpha(ch)==0)
				logic=0;
			else n++;
			prev=ch;
			}
		printf("\nNumber of letters is %0d\n",n);
		printf("Number of words is %0d\n",words);
		printf("Average number of letters is %.2f\n",(float)n/words);
		return 0;
	}
*/

/**********************��(5)��**********************/

/*
#include<ctype.h>
#include<stdio.h>
int main(void)
	{
	int guess=50;
	int n=0;
	int lowline,highline;
	int prel,prem,preh;//��¼��������ǰһ�ε����޵㡢�м�㡢���޵�
	char response;
	printf("Pick an integer from 1 to 100.I will try to guess ");
	printf("it.\nRespond with a y if my guess is right and with");
	printf("an n if it is wrong.\n");
	printf("Uh...is your number %d?\n",guess);
	while((response=getchar())!='y')//���뷵������
		{
		if(response=='n')
			{
			printf("If the guess's bigger,input \"b\"\n");
			printf("If the guess's smaller,input \"s\"\n");
			while(getchar()!='\n')//�޳�"n"��Ķ�������
					continue;
			while((response=getchar())!='b' && response!='s')//�����ǡ�b����s����ѭ��Ҫ������
				{
				printf("Sorry,I understand only b or s.\n");
				if(response=='\n') continue;//�������س���ֱ��ѭ��
				while(getchar()!='\n')//�޳��������루���س��⣩
					continue;
				}
			if(response=='b')
				{
				if(n==0)
					{
					highline=50;
					lowline=1;
					}
				else
					{
					lowline=prel;
					highline=prem;
					}
				}
			if(response=='s')
				{
				if(n==0)
					{
					highline=100;
					lowline=50;
					}
				else
					{
					lowline=prem;
					highline=preh;
					}
				}
			guess=(highline+lowline)/2;
				{//��¼3�����ֵ
				prel=lowline;
				prem=guess;
				preh=highline;
				}
			n++;
			printf("Well,then,is it %d?\n",guess);
			}
		else
			printf("Sorry,I understand only y or n.\n");
		if(response=='\n') continue;//�������س���ֱ��ѭ��
		while(getchar()!='\n')//�޳��������루���س��⣩
			continue;
		}
	printf("I knew I could do it!\n");
	getchar();
	getchar();
	return 0;
	}
*/		 

