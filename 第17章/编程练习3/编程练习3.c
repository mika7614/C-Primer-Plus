#include<stdio.h>
#include<stdlib.h>
#include"list.h"


/*接口函数					*/
/*把列表设置为空列表		*/
void InitializeList(List *plist)
	{
	plist->items=0;
	}
size_t ListIsEmpty(const List * plist)
	{
	if(plist->items==0)
		return 1;
	else
		return 0;
	}
size_t ListIsFull(const List * plist)
	{
	size_t full;

	if(plist->items==MAXSIZE)
		full=1;
	else
		full=0;
	return full;
	}
int ListItemCount(const List * plist)
	{
	return plist->items;
	}
size_t AddItem(Item item,List * plist)
	{
	plist->entries[plist->items]=item;
	plist->items++;
	return 1;
	}

void Traverse(const List *plist,void(*pfun)(Item item))
	{
	int i;
	for(i=0;i<plist->items;i++)
		pfun(plist->entries[i]);
	}

void EmptyTheList(List * plist)
	{
	plist=NULL;
	}
