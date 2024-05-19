#include<stdio.h>
#include<stdlib.h>
#include"list.h"

/*�ֲ�����ԭ��*/
static void CopyToNode(Item item,Node * pnode);

/*�ӿں���					*/
/*���б�����Ϊ���б�		*/
void InitializeList(List *plist)
	{
	plist->head=NULL;
	plist->end=NULL;
	}
size_t ListIsEmpty(const List * plist)
	{
	if(plist->head==NULL)
		return 1;
	else
		return 0;
	}
size_t ListIsFull(const List * plist)
	{
	Node * pt;
	size_t full;

	pt=(Node*)malloc(sizeof(Node));
	if(pt==NULL)
		full=1;
	else
		full=0;
	free(pt);
	return full;
	}
size_t ListItemCount(const List * plist)
	{
	size_t count=0;
	Node * pnode=plist->head;

	while(NULL != pnode)
		{
		++count;
		pnode=pnode->next;
		}
	return count;
	}
size_t AddItem(Item item,List * plist)
	{
	Node * pnew;
	pnew = (Node *)malloc(sizeof(Node));
	if(pnew == NULL)
		return 0;
	
	CopyToNode(item,pnew);
	pnew->next=NULL;
	if(plist->head==NULL)
		{
		plist->head=pnew;
		plist->end=pnew;
		}
	else
		{
		plist->end->next=pnew;
		plist->end=pnew;
		}
	return 1;
	}

void Traverse(const List *plist,void(*pfun)(Item item))
	{
	Node * pnode=plist->head;
	while(pnode!=NULL)
		{
		(*pfun)(pnode->item);
		pnode=pnode->next;
		}
	}

void EmptyTheList(List * plist)
	{
	Node * psave;
	
	while(plist->head!=NULL)//������ָ��ָ��ͬһ�����ٵĴ洢�ռ䣨malloc()��������һ���ͷţ���һ��ָ��ͱ�Ϊ��ָ�롣
		{
		psave=plist->head->next;
		free(plist->head);
		plist->head=psave;
		}
	printf("%p",psave);
	}
static void CopyToNode(Item item,Node * pnode)
	{
	pnode->item=item;
	}