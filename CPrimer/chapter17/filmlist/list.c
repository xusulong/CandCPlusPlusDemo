/**
 *  program 17.5 list.c
 * **/

#include <stdio.h>
#include <stdlib.h>
#include "list.h"
/* 局部函数原型 */
static void CopyToNode(Item item,Node *pnode);

/* 接口函数 */
/*把链表设置为空*/
void InitializeList(List * plist)
{
    *plist = NULL;
}

bool ListIsEmpty(const List * plist)
{
    if(*plist == NULL)
        return true;
    else 
        return false;
}

/* 如果链表已满，返回true */
bool ListIsFull(const List * plist)
{
    Node * pt;
    bool full;
    pt = (Node*)malloc(sizeof(Node));
    if(pt == NULL)
        full = true;
    else 
        full = false;
    free(pt);
    return full;
}
//返回节点的数量
unsigned int ListItemCount(const List * plist)
{
    unsigned int count = 0;
    Node * pnode = *plist;
    while(pnode != NULL)
    {
        ++count;
        pnode = pnode->next;
    }
    return count;
}

bool AddItem(Item item,List * plist)
{
    Node * pnew;
    Node * scan = *plist;
    pnew = (Node *)malloc(sizeof(Node));
    if(pnew == NULL)
        return false;
    CopyToNode(item,pnew);
    pnew->next = NULL;
    if(scan == NULL)
        *plist = pnew;
    else 
    {
        while(scan->next != NULL)
            scan = scan->next;
        scan ->next = pnew;/* 添加到链表的末尾 */
    }
    return true;
}
void Traverse(const List * plist,void (*pfun)(Item item))
{
    Node * pnode = *plist;
    while(pnode != NULL)
    {
        (*pfun)(pnode->item);
        pnode = pnode->next;
    }
}

void EmptyTheList(List * plist)
{
    Node * psave;
    while(*plist != NULL)
    {
        psave = (*plist)->next;
        free(*plist);
        *plist =  psave;
    }
}

static void CopyToNode(Item item,Node * pnode)
{
    pnode->item = item;/*拷贝结构*/
}