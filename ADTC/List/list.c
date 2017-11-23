//
// Created by HZWNB147 on 2017/11/21.
//
#include <stdlib.h>
#include "list.h"
#include "fatal.h"
List
MakeEmpty(List L)
{
    if(L != NULL)
        DeleteList(L);
    L = malloc(sizeof(struct Node));
    if(L == NULL )
        FatalError(" Out of memory");
    L->Next = NULL;
    return L;
}
int
IsEmpty(List L)
{
     return L->Next == NULL;
}
int
IsLast(Position P,List L )
{
    return P->Next == NULL;
}
Position
Find(ElementType X,List L)
{
    Position P;
    P = L->Next;
    while(P != NULL && P->Element !=X)
        P = P->Next;
    return P;
}
void
Delete(ElementType X,List L)
{
    Position P,TmpCell;
    P = FindPrevious(X,L);
    if(!IsLast(P,L))
    {
        TmpCell = P->Next;
        P->Next = TmpCell->Next;
        free(TmpCell);
    }
}
Position
FindPrevious(ElementType X,List L)
{
    Position P;
    P = L;
    while( P->Next != NULL && P->Next->Element != X )
            P = P->Next;
    return P;
}
/* 将指定的值插入节点P的后面 */
void Insert(ElementType X,Position P)
{
    Position TmpCell;
    TmpCell = malloc(sizeof(struct Node));
    if(TmpCell == NULL)
        FatalError("Out of apace");
    TmpCell->Element = X;
    TmpCell->Next = P->Next;
    P->Next = TmpCell;
}


#if 0
/* Incorrect DeleteList algorithm */
void DeleteList(List L)
{
    Position P;
    P = L->Next;
    L ->Next = NULL;
    while(P != NULL)
    {
        free(P);
        P= P->Next;
    }
}
#endif
void DeleteList(List L)
{
    Position P,Tmp;
    P = L->Next;
    while(P != NULL)
    {
        Tmp = P->Next;
        free(P);
        P = Tmp;
    }
}
Position
Header (List L)
{
    return L;
}
Position
First(List L)
{
    return L->Next;
}
Position
Advance(Position P)
{
    return P->Next;
}
ElementType
Retrieve(Position P)
{
    return P->Element;
}
/* print list */
void PrintList(List L)
{
    Position P;
    P = L->Next;
    if(IsEmpty(L))
        Error("The List is Empty");
    else
    {
        while (P!=NULL)
        {
            printf("%d\n",P->Element);
            P = P->Next;
        }
    }
}