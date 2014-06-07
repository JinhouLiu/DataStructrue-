#include<stdio.h>
#include<stdlib.h>
typedef int DataType; 
typedef struct Node
{
DataType data;
struct Node *pre,*next;
}DSLNode;
void ListInitiate(DSLNode **head)
{
if(((*head)=(DSLNode*)malloc(sizeof(DSLNode)))==NULL) exit(1);
(*head)->pre=*head;
(*head)->next=*head;
}
/*
*求链表长度函数
*/
int ListLength(DSLNode *head)
{
int size=0;
DSLNode *p=head;
while(p->next!=head)
{
p=p->next;
size++;
}
return size;
}  
int ListInsert(DSLNode *head,int i,DataType x)
{
//在节点i之前插入
int j=-1;
DSLNode *p,*s;
p=head;
while(p->next!=head&&j<i-1)
{
p=p->next;
j++;
}
if(j!=i-1)
{
printf("插入位置出错!\n");
return 0;
}
if((s=(DSLNode*)malloc(sizeof(DSLNode)))==NULL) exit(1);
s->data=x;
s->next=p->next;
s->pre=p;
p->next=s;
return 1;
}
int ListDelete(DSLNode *head,int i,DataType *x)
{
int j=-1;
DSLNode *p,*s;
p=head;

//定位到i-1节点
while(p->next!=head&&p->next->next!=head&&j<i-1)
{
p=p->next;
j++;
}
if(j!=i-1)
{
printf("删除位置出错!\n");
