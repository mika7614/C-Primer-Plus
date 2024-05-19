/***************************** ±‡≥Ã¡∑œ∞ **********************************/

/***************************** (1) ******************************/

/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define TSIZE 45
struct film {
	char title[TSIZE];
	int rating;
	struct film *next;

//	struct film *previous;

	};
void output(struct film *);

int main(void)
	{
	struct film *head=NULL;
	struct film *current;
	struct film *prev=NULL;
	
	struct film *temp;

	char input[TSIZE];

	puts("Enter first movie title:");
	while(gets(input)!=NULL && input[0]!='\0')
		{
		current=(struct film *)malloc(sizeof(struct film));
		if(head==NULL)
			head=current;
		else
			prev->next=current;
		current->next=NULL;

//		if(prev!=NULL)
//			current->previous=prev;
//		else
//			current->previous=NULL;

		strcpy(current->title,input);
		puts("Enter your rating<0-10>:");
		scanf("%d",&current->rating);
		while(getchar()!='\n')
			continue;
		puts("Enter next movie title(empty line to stop):");
		prev=current;
		}
	if(head==NULL)
		printf("No data entered.");
	else
		printf("Here is the movie list:\n");
	current=head;
	while(current!=NULL)
		{
		printf("Movie:%s Rating:%d\n",current->title,current->rating);

//		temp=current;

		current=current->next;
		}

//	current=temp;
	putchar('\n');

//	while(current!=NULL)
//		{
//		printf("Movie:%s Rating:%d\n",current->title,current->rating);
//		current=current->previous;
//		}

	output(head);
	printf("Movie:%s Rating:%d\n",head->title,head->rating);

	current=head;
	while(current!=NULL)
		{
		temp=current;
		current=current->next;
		free(temp);
		}
	printf("Bye!\n");
	return 0;
	}
void output(struct film *p)
	{
	if(p!=NULL)
		{
		p=p->next;
		output(p);
		}
	if(p!=NULL)
		printf("Movie:%s Rating:%d\n",p->title,p->rating);
	}
*/

/**************************** (4) *****************************/
