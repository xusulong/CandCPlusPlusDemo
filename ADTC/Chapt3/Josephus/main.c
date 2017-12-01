#include <stdio.h>
#include <stdlib.h>

/** Joseph Problem
 *  利用单循环链表解决约瑟夫问题。
 *  问题描述：将n个数链接成一个环，从第m个开始，每次从1计数到s时将s删除。
 *  从下一个开始再次从1计数至s时删除s。直到全部删除为止。
 **/
typedef struct Node{
    int data;
    struct Node * next;
}Node;
typedef struct Node * LinkList;

void CreateJosephLoop(LinkList * L,int length)
{
    //创建Joseph环，在头节点放入元素1
    *L = (LinkList)malloc(sizeof(struct Node));
    if(!(*L))
    {
        printf("Error :malloc 0!\n");
        exit(1);
    }
    (*L) ->next = (*L);
    (*L) ->data = 1;
    int i;
    LinkList newLink;
    LinkList tail = *L;
    for(i =0;i<length;i++)
    {
        newLink =(Node *) malloc(sizeof(Node));
        if(!newLink)
        {
            printf("Error malloc:%d",1+i);
            exit(1);
        }
        newLink ->data = i+1;
        newLink->next = tail->next;
        tail->next = newLink;
        tail = newLink;
    }
}

void JosephProblem(int loopsize,int from,int stepBy)
{
    //

}
int main() {
    printf("Hello, World!\n");
    return 0;
}