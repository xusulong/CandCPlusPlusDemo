//
// Created by HZWNB147 on 2017/12/4.
//

#ifndef BTREE_TREE_H
#define BTREE_TREE_H
struct ThreeNode;
typedef struct TreeNode *Position;
typedef struct TreeNode *SearchTree;
typedef int ElementType;

SearchTree MakeEmpty(SearchTree T);
Position Find(ElementType X,SearchTree T);
Position FindMin(SearchTree T);
Position FindMax(SearchTree T);
SearchTree Insert(ElementType X,SearchTree T);
SearchTree Delete(ElementType X,SearchTree T);
ElementType Retrieve(Position P);

struct  TreeNode
{
    ElementType Element;
    SearchTree Left;
    SearchTree Right;
};

#endif //BTREE_TREE_H
