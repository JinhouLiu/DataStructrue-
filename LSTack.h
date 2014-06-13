#include<stdio.h>
#include<stdlib.h>
typedef int DataType;
typedef struct Node
{
DataType data;
struct Node *next;
}LSNode;
/*
*链式堆栈初始化
*/
void StackInitiate(LSNode **head)
{
if(((*head)=(LSNode*)malloc(sizeof(LSNode)))==NULL) exit(1);
(*head)->next=NULL;
}
/*
*求链式堆栈长度
*/
int StackNotEmpty(LSNode *head)
{

if(head->next==NULL) return 0;

return 1; 
}
/*
*由于有头结点，头结点不能算是我们的数据
*/
int StackPush(LSNode *head,DataType x)
{
LSNode *p;
if((p=(LSNode*)malloc(sizeof(LSNode)))==NULL)
{
printf("内存空间不足无法插入!\n");
return 0;
}
p->data=x;
p->next=head->next;
head->next=p;
return 1; 
}

int StackPop(LSNode *head,DataType *x)
{
LSNode *p=head->next;
if(p==NULL)
{
printf("堆栈以空出错!\n");
return 0;
}
head->next=p->next;
*x=p->data;
free(p);
return 1;
}
int StackGet(LSNode *head,DataType  *x)
{
LSNode  *p=head->next;
if(p==NULL)
{
printf("堆栈以空出错!\n");
return 0;
}
*x=p->data;
return  1;
}
/*
*删除链式堆栈空间
*/
void DESTORY(LSNode *head)
{
LSNode *p,*p1;
p=head;
while(p!=NULL)
{
p1=p;
p=p->next;
free(p);
}
} 
