//
// Created by HZWNB147 on 2017/11/23.
//
/**
 *
 * program 17.3 list.h
 *
 * **/
#include <stdbool.h>
#ifndef FILMLIST_LIST_H
#define FILMLIST_LIST_H
#define TSIZE 45
struct film
{
    char title[TSIZE];
    int rating;
};
typedef struct film Item;
typedef struct node
{
    Item item;
    struct node * next;
}Node;

typedef Node * List;
void InitializeList(List * plist);

bool ListIsEmpty(const List *plist);
bool ListIsFull(const List *plist);

unsigned int ListItemCount(const List *plist);

bool AddItem(Item item,List * plist);
/**
 * 把函数作用于链表中的每一项
 *参数pfun只想函数的执政
 * **/
void Traverse(const List *plist,void(*pfun)(Item item));
/**
 * 释放已分配的内存
 * **/
void EmptyTheList(List * plist);
#endif //FILMLIST_LIST_H
