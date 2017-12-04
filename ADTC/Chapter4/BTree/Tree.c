//
// Created by HZWNB147 on 2017/12/4.
//
#include <stdlib.h>
#include "Tree.h"
#include "fatal.h"
SearchTree
MakeEmpty(SearchTree T)
{
    if(T != NULL)
    {
        MakeEmpty(T->Left);
        MakeEmpty(T->Right);
        free(T);
    }
    return NULL;
}
//递归方式实现找最小元素
Position
FindMin(SearchTree T)
{
    if(T == NULL )
        return  NULL;
    else
        if(T->Left == NULL)
            return T;
    return FindMin(T->Left);
}
//非递归方式实现找最小值
Position
FindMax( SearchTree T)
{
    if(T != NULL)
        while(T->Right != NULL)
            T = T->Right;
    return T;
}
//递归方式插入元素到二叉查找树
SearchTree
Insert(ElementType X,SearchTree T)
{
    if(T == NULL)
    {
        T = malloc(sizeof(struct TreeNode));
        if(T == NULL)
        {
            FatalError("Out of space");
        }
        else
        {
            T->Element = X;
            T->Left = T->Right = NULL;
        }
    }
    else
    {
        if(X>T->Element)
            T->Right = Insert(X,T->Right);
        else if(X>T->Element)
            T->Right = Insert(X,T->Right);
        return T;
    }

}