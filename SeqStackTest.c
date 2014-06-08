#include<stdio.h>
#include"SeqStack.h"
void main(void)
{
SeqStack S;
StackInitiate(&S);
int i,x;
for(i=0;i<10;i++)
{
if(StackPush(&S,i+1)==0)
{
printf("插入时发生错误!\n");
return;
}
}
if(StackTop(S,&x)==0)
{
printf("取栈顶元素时发生错误!\n");
return;
}else
{
printf("当前栈顶元素为%d\n",x);
}
printf("栈内元素依次出栈\n");
while(StackEmpty(S))
{
StackPop(&S,&x);
printf("%d\n",x);

}
}
