#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define TSIZE 45
/**
 *
 * 使用结构链表
 *program 17.2
 * **/
struct film{
    char title[TSIZE];
    int rating;
    struct film * next;
};
char * s_gets(char * st,int n);
int main() {
    struct film * head = NULL;
    struct film * prev, * current;
    char input[TSIZE];
    /*收集并存储信息*/
    puts("Enter first movie title");
    while(s_gets(input,TSIZE) != NULL && input[0] !='\0')
    {
        current = (struct film *) malloc(sizeof(struct film));
        if(head == NULL)
            head = current;
        else
            prev->next = current;
        current->next = NULL;
        strcpy(current->title,input);//输入的标题赋与当前节点
        puts("Enter your rating<0-10>;");
        scanf("%d",&current->rating);//输入的排名付给当前节点
       while(getchar() != '\n')
            continue;
        puts("Enter next movie title (empty line to stop):");
        prev = current;
    }
    /*显示电影列表*/
    if(head == NULL)
        printf("No data entered");
    else
        printf("Here is the movie list:\n");
    current = head;
    while(current != NULL)
    {
        printf("Movie :%s Rating: %d \n",current->title,current->rating);
        current = current-> next;
    }
    /*释放已分配的内存*/
    while( head!= NULL)
    {
        current = head;
        head = current->next;
        free(current);
        printf("free!\n");
    }
    printf("Bye!\n");
    return 0;
}
char * s_gets(char * st,int n)
{
    char * ret_val;
    char * find;
    ret_val = fgets(st,n,stdin);
    if(ret_val)
    {
        /**
         * strchr
         * 查找字符串s中首次出现字符c的位置(指针)
         * **/
        find = strchr(st,'\n');
        if(find)
            *find = '\0';
        else
            while(getchar() != '\n')
                continue;//处理剩余输入行
    }
    return ret_val;
}