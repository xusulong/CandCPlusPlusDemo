//
// Created by HZWNB147 on 2017/11/30.
//
#include <stdlib.h>
#include "Stack.h"
#include "fatal.h"

Stack  CreateStack(void)
{
    Stack S;
    S = malloc(sizeof(struct Node));
    if(S == NULL)
        FatalError("Out of space!");
    S->Next = NULL;
    MakeEmpty(S);
    return S;
}
int IsEmpty(Stack S)
{
    return S->Next == NULL;
}
void MakeEmpty(Stack S)
{
    if(S == NULL)
    {
        Error("Must use CreateStack first");
    }
    else
    {
        while(!IsEmpty(S))
            Pop(S);
    }
}
void
Push(ElementType X,Stack S)
{
    PtrToNode TmpCell;
    TmpCell = malloc(sizeof(struct Node));
    if(TmpCell == NULL)
    {
        FatalError("Out of space!!!");
    }
    else
    {
        TmpCell ->Element =X;
        TmpCell->Next= S->Next;
        S->Next = TmpCell;
    }
}
ElementType
Top(Stack S)
{
    if(!IsEmpty(S))
        return S->Next->Element;
    Error("Empty Stack");
    return 0;/* Return value used to avoid warning */
}
ElementType Pop(Stack S)
{
    ElementType ele;
    PtrToNode FirstCell;
    if(IsEmpty(S))
    {
        Error("Empty stack");
    }
    else
    {
        FirstCell = S->Next;
        S->Next = S->Next->Next;
        ele=FirstCell->Element;
        free(FirstCell);
        return ele;
    }
}
