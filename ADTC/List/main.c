#include <stdio.h>
#include <stdlib.h>
#include "list.h"
int main()
{
    //Node的结构定义在list.h中则下面语句可以执行，否则不可以
    struct Node node = {.Element=3000,.Next=NULL};
    List  list = malloc(sizeof(struct Node)) ;
    list->Next=NULL;
    Insert(3,list);
    Insert(30,list);
    Insert(300,list);
    PrintList(list);
    return 0;
}
