#include <stdio.h>

/*
 *  chapter 8 Program List 8.1 echo.c
 *  单字符I/O.getchar()和putchar()
 *  因为存在缓冲区，所以可以输入很多字符，实际上仍然是单个字符的I/O
 */
int main() {
    char ch;
    while((ch = getchar()) != EOF)
        putchar(ch);
    return 0;
}