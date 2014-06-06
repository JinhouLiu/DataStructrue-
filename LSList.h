#include<stdio.h>
#include<stdlib.h>
/*
＊
*带头链表
＊
*/
typedef int DataType;  
typedef struct Node
{
DataType data;
struct Node *next; 
}LSNode;
/*
*链式表初始化
*/
void ListInitiate(LSNode  **head)
{
if((*head=(LSNode*)malloc(sizeof(LSNode)))==NULL) exit(1);
(*head)->next=NULL;
}
/*
*链式表长度
*我们计算的长度不包括头结点，以前理解失误
*/
int ListLength(LSNode *head)
{
LSNode *p=head;
int size=0;
while(p->next!=NULL)
{
/*
*
*当执行完成第一次循环时p此时已经指向了链表中（包括头结点）第三个节点，size=1
*
*/
p=p->next;
size++;
}
return size;
}
/*
*
*在链表第i个节点前插入元素
*
*/
int ListInsert(LSNode *head,int  i,DataType x)
{
int j=-1;
LSNode *p,*q;
p=head;
//最终让p指向第i-1个节点
while(p->next!=NULL&&j<(i-1))
{
p=p->next;
j++;
}
if(j!=i-1)
{
printf("插入位置出错");
return 0;
}
if((q=(LSNode*)malloc(sizeof(LSNode)))==NULL) exit(1);
q->data=x;
q->next=p->next;
p->next=q;
return  1;
}
/*
*
*删除链表中ｉ位置上的节点
*
*/
int ListDelete(LSNode *head,int i,DataType *x)
{
int j;
j=-1;
LSNode *p,*s;
p=head;
//使p指向第i-1个节点
while(p->next!=NULL&&p->next->next!=NULL&&j<(i-1))
{
p=p->next;
j++;
}
if(j!=i-1)
{
printf("删除位置出错");
return 0;
}
s=p->next;
*x=s->data;
p->next=p->next->next;
free(s);//释放内存空间
return 1;
}
/*
*取链表位置为ｉ的元素
*/
int ListGet(LSNode *head,int i,DataType *x)
{
LSNode *p;
int j=-1;
p=head;

//使p定位到i节点
while(p->next!=NULL&&j<i)
{
p=p->next;
j++;
}
if(j!=i)
{
printf("取元素位置出错!");
return 0;
}
*x=p->data;
return 1;
}
void Destory(LSNode **head)
{
LSNode *p,*q;
p=*head;
while(p=NULL)
{
q=p;
p=p->next;
free(q);
}
*head=NULL;
}
