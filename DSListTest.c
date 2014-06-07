#include<stdio.h>
#include<stdlib.h>
#include"DSList.h"
void main()
{
DSLNode  *head; 
int i,x;
ListInitiate(&head);
for(i=0;i<10;i++)
{
if(ListInsert(head,i,i+1)==0)
{

return;
}
}
if(ListDelete(head,4,&x)==0)
{
printf("删除时发生错误!");
return;
}
for(i=0;i<ListLength(head);i++)
{
if(ListGet(head,i,&x)==0)
{
printf("取数据时发生错误!");
return;
}
else  
printf("%d\n",x);
}
}
