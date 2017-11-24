//
// Created by HZWNB147 on 2017/11/23.
//
/* program 17.6 queue.h */

#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H

#include <stdbool.h>
typedef int Item;
#define MAXQUEUE 10

typedef  struct node
{
    Item item;
    struct node * next;
}Node;

typedef struct queue
{
    Node * front;/* 指向队列首项的指针 */
    Node * rear;/*指向队列尾项的指针 */
    int items;/* 队列中的项数*/
}Queue;

/* pq指向一个队列，队列初始化为空 */
void InitializeQueue(Queue * pq);

/* 检查队列是否已满 */
bool QueueIsFull(const Queue * pq);

/*检查队列是否为空*/
bool QueueIsEmpty(const Queue *pq);

/* pq指向已被初始化的队列，后置条件:返回队列中的项数 */
int QueueItemCount(const Queue *pq);

/* 在队列末尾添加项 */
bool EnQueue(Item item,Queue *pq);

/* 从队列的开头删除项 */
bool DeQueue(Item * pitem,Queue * pq);
/* 打印队列元素 */
void PrintQueue(Queue * pq);
/* 清空队列 */
void EmptyTheQueue(Queue * pq);
#endif //QUEUE_QUEUE_H
