#ifndef _QUEUE_H_
#define _QUEUE_H_

typedef struct item
	{
	long arrive;
	int processtime;
	}Item;

#define MAXQUEUE 10

typedef struct node
	{
	Item item;
	struct node *next;
	}Node;

typedef struct queue
	{
	Node *front;
	Node *rear;
	int items;
	}Queue;

void InitializeQueue(Queue *pq);

size_t QueueIsFull(const Queue *pq);

size_t QueueIsEmpty(const Queue *pq);

int QueueItemCount(const Queue *pq);

size_t EnQueue(Item item,Queue *pq);

size_t DeQueue(Item *pitem,Queue *pq);

void EmptyTheQueue(Queue *pq);

#endif