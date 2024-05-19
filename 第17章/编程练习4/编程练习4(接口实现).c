#include<stdio.h>
#include<stdlib.h>
#include"±à³Ì4½Ó¿Ú.h"

static void CopyToNode(Item item,Node * pn);
static void CopyToItem(Node * pn,Item * pi);

void InitializeQueue(Queue *pq)
	{
	pq->front=pq->rear=NULL;
	pq->items=0;
	}
size_t QueueIsFull(const Queue *pq)
	{
	return pq->items==MAXQUEUE*2;
	}
size_t QueueIsEmpty(const Queue * pq)
	{
	return pq->items==0;
	}
int QueueItemCount(const Queue *pq)
	{
	return pq->items;
	}
size_t EnQueue(Item item,Queue *pq)
	{
	Node * pnew;

	if(QueueIsFull(pq))
		return 0;
	pnew=(Node*)malloc(sizeof(Node));
	if(NULL==pnew)
		{
		fprintf(stderr,"Unable to allocate memory!\n");
		exit(1);
		}
	CopyToNode(item,pnew);
	pnew->next=NULL;
	if(QueueIsEmpty(pq))
		pq->front=pnew;
	else
		pq->rear->next=pnew;
	pq->rear=pnew;
	pq->items++;
	return 1;
	}
size_t DeQueue(Item * pitem,Queue * pq)
	{
	Node *pt;

	if(QueueIsEmpty(pq))
		return 0;
	CopyToItem(pq->front,pitem);
	pt=pq->front;
	pq->front=pq->front->next;
	free(pt);
	pq->items--;

	if(pq->items==0)
		pq->rear=NULL;
	return 1;
	}
void EmptyTheQueue(Queue *pq)
	{
	Item dummy;
	while(!QueueIsEmpty(pq))
		DeQueue(&dummy,pq);
	}
static void CopyToNode(Item item,Node *pn)
	{
	pn->item=item;
	}
static void CopyToItem(Node * pn,Item * pi)
	{
	*pi=pn->item;
	}
