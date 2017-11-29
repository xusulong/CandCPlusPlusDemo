//
// Created by HZWNB147 on 2017/11/28.
//
/* C Primer Program 17.11 tree.c */
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "tree.h"

/* 局部数据类型 */
/* 该数据类型用于查找项；在AddItem(),InItem()和DeleteItem()这些函数的实现中用到
 * 因为在删除的时候，需要知道待删除节点的父节点，以便更新父节点指向子节点的指针
 * */
typedef  struct pair{
 Trnode * parent;
    Trnode * child;
}Pair;

/* 局部函数的原型 */
static Trnode * MakeNode(const Item * pi);
static bool ToLeft(const Item * i1,const Item * i2);
static bool ToRight(const Item * i1,const Item * i2);
static void AddNode(Trnode * new_node,Trnode * root);
static void InOrder(const Trnode * root,void(*pfun)(Item item));
static Pair SeekItem(const Item *pi,const Tree * ptree);
static void DeleteNode(Trnode **ptr);
static void DeleteAllNodes(Trnode * ptr);
/* 函数定义 */
void InitializeTree(Tree * ptree)
{
	ptree->root = NULL;
	ptree->size = 0;
}
bool TreeIsEmpty(const Tree * ptree)
{
	if(ptree->root == NULL)
		return true;
	else 
		return false;
}
bool TreeIsFull(const Tree * ptree)
{
	if(ptree->size == MAXITEMS)
		return true;
	else
		return false;
}
int TreeItemCount(const Tree * ptree)
{
	return ptree->size;
}
bool AddItem(const Item * pi,Tree * ptree)
{
	Trnode * new_node;
	if(TreeIsFull(ptree))
	{
		fprintf(stderr, "%s\n","Tree is full");
		return false;
	}
	if(SeekItem(pi,ptree).child != NULL)
	{
		fprintf(stderr, "%s\n","Attempt to add duplicate item" );
		return false;
	}
	new_node = MakeNode(pi);/* 指向新节点 */
	if(new_node == NULL)
	{
		fprintf(stderr, "%s\n", "Couldn't Create node\n");
		return false;
	}
	ptree->size++;
	if(ptree->root == NULL)
		ptree->root = new_node;
	else 
		AddNode(new_node,ptree->root);
	return true;
}	
bool InTree(const Item * pi,const Tree * ptree)
{
	return (SeekItem(pi,ptree).child == NULL) ? false : true;
}

bool DeleteItem(const Item * pi,Tree * ptree)
{
	Pair look;
	look = SeekItem(pi,ptree);
	if(look.child == NULL)
		return false;
	if(look.parent == NULL)
		DeleteNode(&ptree->root);
	else if(look.parent->left == look.child)
		DeleteNode(&look.parent->left);
	else 
		DeleteNode(&look.parent->right);
	ptree->size--;
	return true;
}
void Traverse(const Tree * ptree,void(*pfun)(Item item))
{
	if(ptree != NULL)
		InOrder(ptree->root,pfun);
}
void DeleteAll(Tree * ptree)
{
	if(ptree != NULL)
		DeleteAllNodes(ptree->root);
	ptree->root = NULL;
	ptree->size = 0;
}
/* 局部函数 */
static void InOrder(const Trnode * root,void(*pfun)(Item item))
{
	if(root != NULL)
	{
		InOrder(root->left,pfun);
		(*pfun)(root->item);
		InOrder(root->right,pfun);
	}
}

static void DeleteAllNodes(Trnode * root)
{
	Trnode * pright;
	if(root != NULL)
	{
		pright = root->right;
		DeleteAllNodes(root->left);
		free(root);
		DeleteAllNodes(pright);
	}
}
/*
 * 在插入节点时，已经确保左子数的所有元素小于右子数的所有元素
 */
static void AddNode(Trnode * new_node,Trnode * root)
{
	if(ToLeft(&new_node->item,&root->item))
	{
		if(root->left == NULL)
			root->left = new_node;
		else
			AddNode(new_node,root->left);
	}
	else if(ToRight(&new_node->item,&root->item))
	{
		if(root->right == NULL)
			root->right = new_node;
		else 
			AddNode(new_node,root->right);
	}
	else
	{
		fprintf(stderr, "%s\n", "location error in AddNode()\n");
		exit(1);
	}
}
/* 元素i1小于元素i2时返回true */
static bool ToLeft(const Item * i1,const Item * i2)
{
	/*
	* strcmp()中的第一个参数小于第二个参数，返回负数
	*/
	int comp1;
	if((comp1 = strcmp(i1->petname,i2->petname))<0)
		return true;
	else if(comp1 == 0 && strcmp(i1->petkind,i2->petkind)<0)
		return true;
	else 
		return false;
}
/* 元素i1大于i2时，返回true*/
static bool ToRight(const Item * i1,const Item * i2)
{
	int comp1;
	if((comp1 = strcmp(i1->petname,i2->petname))>0)
		return true;
	else if(comp1 == 0 &&strcmp(i1->petkind,i2->petkind)>0)
		return true;
	else return false;
}
/* 根据元素的值，构造一个节点，左右节点指向NULL */
static Trnode * MakeNode(const Item * pi)
{
	Trnode * new_node;
	new_node = (Trnode *)malloc(sizeof(Trnode));
	if(new_node != NULL)
	{
		new_node->item = * pi;
		new_node->left = NULL;
		new_node->right = NULL;
	}
	return new_node;
}
/*
 * 在二叉树中查找元素为pi的节点，返回该节点及其父节点
 * */
static Pair SeekItem(const Item * pi,const Tree * ptree)
{
	Pair look;
	look.parent = NULL;
	look.child = ptree->root;
	if(look.child == NULL)
		return look;
	while(look.child != NULL)
	{
		if(ToLeft(pi,&(look.child->item)))
		{
			look.parent = look.child;
			look.child = look.child->left;
		}
		else if(ToRight(pi,&(look.child->item)))
		{
			look.parent = look.child;
			look.child = look.child->right;
		}
		else /* 如果前两项都不满足，则必定是相等的情况*/
			break; /* look.child 目标项的节点*/
	}
	return look;/* 成功返回*/
}
static void DeleteNode(Trnode **ptr)
{/* ptr 是指向目标节点的父节点指针成员的地址，指向待删除节点 */
	Trnode * temp;
	if((*ptr)->left == NULL)//*ptr指向待删除的节点的地址，并且待删除节点没有左节点
	{
		temp = *ptr;//将待删除节点的指针暂存下来，准备释放
		*ptr = (*ptr)->right;//将指向父节点的子节点（待删除节点）的指针指向右子树
		free(temp);
	}//如果待删除节点没有左节点，那么待删除的节点指向他的右子节点即可。释放他原来指向的空间
	else if((*ptr)->right == NULL)
	{
		temp = *ptr;
		*ptr = (*ptr)->left;//将指向父节点的子节点（待删除节点）的指针指向左子树
		free(temp);
	}//如果待删除节点没有右节点，那么待删除的节点指向他的左子节点即可。释放他原来指向的空间
	else
	{
		for(temp = (*ptr)->left;temp->right != NULL;temp = temp->right)
			continue;
        //循环完毕后，temp指向待删除节点的右枝第一个空位
		temp->right = (*ptr)->right;//将待删除节点的右子树接上
		temp = *ptr;
		*ptr = (*ptr)->left;//连接上左子树
		free(temp);
	}
	/*
	* 如果待删除的节点同时有左右节点，
	* 把左子树连接到被删除节点的父节点，然后沿左子树的右枝查找到第一个空位，把右子树与该空位连接
	*/
	
}