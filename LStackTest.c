#include<stdio.h>
#include"LStack.h"
void main(void)
{
LSNode *head;
int i,x;
StackInitiate(&head);
for(i=0;i<10;i++)
{
StackPush(head,i+1);
}
if(StackGet(head,&x)==0)
{
printf("取栈顶元素出错");
return;
}else
{
printf("当前栈顶元素为%d\n",x);
}
printf("栈内数据依次出栈\n");
while(StackNotEmpty(head))
{
if(StackPop(head,&x)==0)
{
printf("数据出栈时发生错误!\n");
return;
}else
{
printf("当前栈顶元素为%d\n",x);
}
}
DESTORY(&(*head));
}
