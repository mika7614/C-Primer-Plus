#ifndef LIST_H_
#define LIST_H_
#define TSIZE 45
struct film
	{
	char title[TSIZE];
	int rating;
	};

typedef struct film Item;

typedef struct node
	{
	Item item;
	struct node * next;
	}Node;
typedef struct list
	{
	Node * head;
	Node * end;
	}List;

/* ����ԭ��                                                  */
/* ������      ��ʼ��һ���б�                                */
/* ����ǰ��    plistָ��һ���б�    				         */
/* ������	   ���б���ʼ��Ϊ���б�                        */
void InitializeList (List * plist);

/* ������      ���б��Ƿ�Ϊ���б�					         */
/* ����ǰ��    plistָ��һ���ѳ�ʼ�����б�			         */
/* ������    ������б�Ϊ���򷵻�ture�����򷵻�false       */
unsigned int ListIsEmpty (const List * plist);

/* ������	   ȷ���б��Ƿ�����								 */
/* ����ǰ��    plistָ��һ���ѳ�ʼ�����б�					 */
/* ������    ������б���������true�����򷵻�false		 */
unsigned int ListIsFull (const List * plist);

/* ������      ȷ���б�����Ŀ�ĸ���							 */
/* ����ǰ��    plistָ��һ���ѳ�ʼ�����б�					 */
/* ������    ���ظ��б�����Ŀ�ĸ���						 */
unsigned int ListItemCount (const List * plist);

/* ������      ���б�β�����һ����Ŀ						 */
/* ����ǰ��    item��Ҫ�����ӵ��б����Ŀ					 */
/*			   plistָ��һ���ѳ�ʼ�����б�					 */
/* ������    ������ܵĻ������б�β�����һ������Ŀ		 */
/*			   ��������true������������false				 */
unsigned int AddItem (Item item , List * plist);

/* ������	   �Ѻ����������б��е�ÿһ����Ŀ				 */
/* ����ǰ��    plistָ��һ���ѳ�ʼ�����б�					 */
/*			   pfunָ��һ������								 */
/*			   ����һ��Item���������޷���ֵ					 */
/* ������    pfunָ��ĺ��������õ��б��ÿһ����Ŀһ��    */
void Traverse (const List * plist, void (*pfun)(Item item));

/* ������	   �ͷ��ѷ�����ڴ棨����У�					 */
/* ����ǰ��    plistָ��һ���ѳ�ʼ�����б�					 */
/* ������	   Ϊ���б������ڴ��ѱ��ͷ�					 */
/*			   �Ҹ��б���Ϊ���б�							 */
void EmptyTheList (List * plist);

#endif
