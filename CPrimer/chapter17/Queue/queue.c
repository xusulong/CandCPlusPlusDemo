//
// Created by HZWNB147 on 2017/11/24.
//

/* C Primer program 17.7 queue.c  */
#include<stdio.h>
#include <stdlib.h>
#include "queue.h"

/* 局部函数 */
static void CopyToNode(Item item,Node * pn);
static void CopyToItem(Node * pn,Item * pi);

/* 初始化队列为空，把指向队列首项和尾项的指针设置为空，并把项数设置为0 */
void InitializeQueue(Queue *pq)
{
    pq->front = pq->rear = NULL;
    pq->items = 0;
}
/*检查items的值，了解队列是否已满，为空，及确定队列项数*/
bool QueueIsFull(const Queue * pq)
{
    return pq->items == MAXQUEUE;
}

bool QueueIsEmpty(const Queue *pq)
{
    return pq->items == 0;
}

int QueueItemCount(const Queue * pq)
{
    return pq->items;
}
/* 入队，新节点放到队列的尾部
*
* 1、创建一个新节点
* 2、把项拷贝到节点中
* 3、设置节点的next指针为NULL，表明该节点是最后一个节点
* 4、设置当前尾节点的next指针指向新节点，把新节点链接到队列中
* 5、把rear指针指向新节点，以便找到最后的节点
* 6、项数加1
*
 */
bool EnQueue(Item item,Queue *pq)
{
    Node * pnew;
    if(QueueIsFull(pq))
        return false;
    pnew = (Node *)malloc(sizeof(Node));
    if(pnew == NULL)
    {
        fprintf(stderr,"Unable to allocate memory!\n");
        exit(1);
    }
    CopyToNode(item,pnew);
    pnew ->next = NULL;
    if(QueueIsEmpty(pq))
        pq->front = pnew;/* 项位于队列的首端*/
    else
        pq->rear->next = pnew;
    pq->rear = pnew;
    pq ->items++;
    return true;
}
/* * 出队。从队列pq中删除首端节点，并将该节点的值拷贝到指定的变量pitem中
 * 从队列的首端删除项
 * 1、把项拷贝到给定的变量中
 * 2、释放空出的节点使用的内存空间
 * 3、重置首指针指向队列中的下一个项
 * 4、如果删除最后一项，把首指针和尾指针都重置为NULL；
 * 5、项数减1
 * */
bool DeQueue(Item * pitem,Queue * pq)
{
    Node *pt;
    if(QueueIsEmpty(pq))
        return false;
    CopyToItem(pq->front,pitem);
    pt = pq->front;
    pq->front = pq->front->next;
    free(pt);
    pq->items--;
    if(pq->items == 0)
        pq->rear=NULL;
    return true;
}
/* 清空队列 */
void EmptyTheQueue(Queue *pq)
{
    Item dummy;
    while(!QueueIsEmpty(pq))
        DeQueue(&dummy,pq);
}

/* 局部函数，传入值，赋值给节点 */
static void CopyToNode(Item item,Node *pn)
{
    pn->item = item;
}
/* 节点的值拷贝 */
static void CopyToItem(Node * pn,Item * pi)
{
    *pi = pn->item;
}
void PrintQueue(Queue * pq)
{
    int i =1;
    Node * current = pq->front;
    printf("Now,The Queue'items is :\n");
    while(current)
    {
        printf("No.%d :%d \n",i,current->item);
        current = current->next;
        i++;
    }
    printf("Here is the Queue End. \n");
}




