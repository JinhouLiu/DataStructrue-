#include<stdio.h>

#define MAXSIZE 100      

typedef int DataType;
  
/*

*数据结构构造

*/

typedef struct 
{

DataType list[MAXSIZE];
  
int  size;

}SeqList;

/*


＊初始化

*/

void ListInitiate(SeqList  *L)
{


 L->size=0;

}     
   
/*

*返回列表长度
*/

int  ListLength(SeqList L)
{

return   L.size;

}     

/*

*向顺序表中插入元素

*/

int ListInsert(SeqList *L,int i, DataType  x)
{


int  j; 

if(L->size>MAXSIZE)
{

printf("队列已满无法插入!\n");
return  0; 

}  

if(i<0||i>MAXSIZE)
{


printf("参数i错误!\n");
return  0;

}

for(j=L->size;j>i;j--)
{


L->list[j]=L->list[j+1];


} 

L->list[i]=x;

L->size++;
  
return 1;


} 

    
/*


*删除一个元素

*/
int   ListDelete(SeqList *L,int i,DataType  *x)
{


/*删除在队列位置ｉ上的元素并且将元素存储在x中*/ 


int  j;

if(L->size<=0)
{

printf("队列以空不能删除元素！\n");

return   0;
}

if(i<0||i>MAXSIZE)
{

printf("参数i错误!\n");

return 0;

}


*x=L->list[i];

for(j=i;j<L->size;j++)
{

L->list[j]=L->list[j+1];

}

L->size--; 

return 1;

}

/*


*取数据元素


*/
 
int ListGet(SeqList L,int i,DataType *x)
{

/*取队列中位置为i的元素的值并且将值存储到x中*/


if(i<0||i>MAXSIZE)
{


printf("参数i错误\n");

return  0;


}

*x=L.list[i];

return 1;

}
