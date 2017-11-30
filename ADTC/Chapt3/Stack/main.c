#include <stdio.h>
#include "Stack.h"
void int_getchar(int * i_temp);
void showmenu();
int main() {
    char ch;
    Stack stack = CreateStack();
    ElementType e;
    showmenu();
    while((ch=getchar())!='q')
    {
        if(ch!='a'&& ch!='d'&&ch!='q')
        {
            continue;
        }
        if(ch == 'a')
        {
            int_getchar(&e);
            Push(e,stack);
        }
        else if(ch == 'd')
        {
            e = Pop(stack);
            printf("Pop %d\n",e);
        }
        showmenu();
    }
    MakeEmpty(stack);
    puts("Bye!\n");
    return 0;
}

void showmenu()
{
    puts("a to add element; d to delete ,q to quit.");
}
void int_getchar(int * i_temp)
{
    puts("please put an integer");
    scanf("%d",i_temp);
}