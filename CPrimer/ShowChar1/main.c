#include <stdio.h>
/**
 *
 * C Primer chapter8 混合数值和字符输入
 * program No.8_5
 * **/
void display(char ch,int lines,int width);

int main() {
    int ch;
    int rows,cols;
    printf("Enter a character and two integers:\n");
    while((ch = getchar()) != '\n')
    {
        scanf("%d %d",&rows,&cols);
        display(ch,rows,cols);
        printf("Enter another character and  two integers;\n");
        printf("Enter a newline to quit .\n");
        //丢弃scanf()输入后面所有字符。否则，后面的回车键让程序直接退出
        while(getchar() != '\n')
            continue;
    }
    printf("Bye.\n");
    return 0;
}
void display(char cr,int lines,int width)
{
    int row,col;
    for(row = 1;row <= lines; row++)
    {
        for(col = 1;col <= width;col++)
            putchar(cr);
        putchar('\n');
    }
}
