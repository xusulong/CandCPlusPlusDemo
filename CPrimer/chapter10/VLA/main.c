#include <stdio.h>
/**
 * C Primer Program 10.18 vararr2d.c
 *  变长数组中的“变”不是指可以修改已创建数组的大小，一旦创建了变长数组，它的大小则保持不变。这里的变指的是：在创建数组时，可以使用变量指定数组的维度
 **/
 
 #define ROWS 3
 #define COLS 4
 int sum2d(int rows,int cols,int ar[rows][cols]);
int main() {
    int i,j;
	int rs = 3;
	int cs = 10;
	int junk[ROWS][COLS] = {
		{2,4,6,8},
		{3,5,7,9},
		{12,10,8,6}
	};
	int morejunk[ROWS - 1][COLS+2]={
		{20,30,40,50,60,70},
			{5,6,7,8,9,10}
	};
    int varr[rs][cs];//VAL变长数组
	for(i = 0;i < rs;i++)
		for(j = 0; j< cs;j++)
			varr[i][j] = i*j+j;
	printf("3X5 array,junk:\n");
	printf("Sum of all ellements = %d\n",sum2d(ROWS,COLS,junk));
	
	printf("2X6 array,morejunk:\n");	
	printf("Sum of all ellements = %d\n",sum2d(ROWS - 1,COLS + 2,morejunk));
	
	printf("3X10 VLA,varr:\n");	
	printf("Sum of all ellements = %d\n",sum2d(rs,cs,varr));
    return 0;
}

int sum2d(int rows,int cols,int ar[rows][cols])
{
	int r;
	int c;
	int tot = 0;
	for(r = 0;r <rows;r++)
		for(c = 0;c<cols;c++)
			tot += ar[r][c];
		return tot;
}