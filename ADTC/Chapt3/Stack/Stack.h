//
// Created by HZWNB147 on 2017/11/30.
//

#ifndef STACK_STACK_H
#define STACK_STACK_H
typedef int ElementType;

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Stack;

int IsEmpty(Stack S);
Stack CreateStack(void);
void DisposeStack(Stack S);
void MakeEmpty(Stack S);
void Push(ElementType X,Stack S);
ElementType Top(Stack S);
ElementType Pop(Stack S);
struct Node
{
    ElementType  Element;
    PtrToNode Next;
};
#endif //STACK_STACK_Hs
