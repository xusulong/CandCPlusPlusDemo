#include <stdio.h>
#include<stdlib.h>
#include <mem.h> /* include function  strchr  */
#include "list.h"
/**
*
*program 17.4 films3.c
**/
void showmovies(Item item);
char * s_gets(char * st,int n);
int main() {
    List movies;
    Item temp;
    /*初始化*/
    InitializeList(&movies);
    if(ListIsFull(&movies))
    {
    	fprintf(stderr, "No memory available! Bye!\n");
    	exit(1);
    }
    //结构体初始化
    //Item tempNew = {.title="测试",.rating=9};
    //strcpy(tempNew.title , "哈哈测试");
    //tempNew.rating=8;
    //AddItem(tempNew,&movies);
    puts("Enter first movie tiitle:");
    while(s_gets(temp.title,TSIZE) != NULL && temp.title[0] != '\0')
    {
    	puts("Enter your rating<0-10>");
    	scanf("%d",&temp.rating);
    	while(getchar() != '\n')
    		continue;
    	if(AddItem(temp,&movies) == false)
    	{
    		fprintf(stderr, "program allocating memory\n");
    		break;
    	}
    	if(ListIsFull(&movies))
    	{
    		puts("The list is now full .\n");
    		break;
    	}
    	puts("Enter next movie title (empty line to stop):");

    }
    /*显示*/
    if(ListIsEmpty(&movies))
    	printf("No data entered");
    else
    {
    	printf("Here is the movie list :\n");
    	Traverse(&movies,showmovies);
    }
    printf("You entered %d movies .\n",ListItemCount(&movies));

    /* 清理*/
    EmptyTheList(&movies);
    printf("Bye!\n");
    getchar();
    return 0;
}
void showmovies(Item item )
{
    //中文乱码
	printf("movie: %s rating: %d\n",item.title,item.rating);
}
char * s_gets(char * st,int n)
{
	char * ret_val;
	char * find;
	ret_val = fgets(st,n,stdin);
	if(ret_val)
	{
		find = strchr(st,'\n');
		if(find)
			*find = '\0';
		else while(getchar() != '\n')
			continue; // 处理输入行的剩余内容
	}
	return ret_val;
}