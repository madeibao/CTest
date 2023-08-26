


 
#include<stdio.h>
#include<malloc.h>
typedef struct LNode{
	int data;
	struct LNode *next;
}LNode,*LinkList;


LinkList Reverse(LinkList &L)
{
	LinkList p,q;
	p=L->next;
	L->next=NULL;   //重新构造单链表
	while(p!=NULL)
	{
		q=p;
		p=p->next;
		
		q->next=L->next;  //头插法 
		L->next=q;
	} 
	return L;
} 
