//
// Created by HZWNB147 on 2017/11/24.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "queue.h"

#define MIN_PER_HR 60.0

bool newcustomer(double x);//是否有新顾客到来
Item customertime(long when);//设置顾客参数
void InitProgram();
Queue line;
int hours;//模拟的小时数
int perhour;//每小时平均多少位顾客
long cycle,cyclelimit;//循环计数器，计数器的上限
long turnaways = 0;//队列已满被拒绝的顾客数
long customers = 0;//加入队列的顾客数量
long served = 0;//咨询过的顾客数量
long sum_line = 0;//累计的队列总长
int wait_time= 0;//从排队时间
double min_per_cust;//顾客到来的平均时间
long line_wait = 0;//队列累计的等待时间
void int_scanf(int * integer);
int main(void)
{
    char ch;
    Item temp;//新的顾客数据
    printf(" enter 's' to  start; enter 'q' to  quit.\n");
    while((ch = getchar()) != 'q')
    {
        InitProgram();
        while( ch != 's')
            continue;
        srand((unsigned int) time(0));
        puts("Case Study:Sigmund Lander's Advice Booth");
        puts("Enter the number of simulation hours:");
        //scanf("%d",&hours);
        //while(getchar() != '\n')
          //  continue;

        int_scanf(&hours);
        cyclelimit = MIN_PER_HR * hours;
        puts("Enter the average number of customers per hour:");
        scanf("%d",&perhour);
        while(getchar() != '\n')
            continue;
        min_per_cust = MIN_PER_HR / perhour;
        for(cycle = 0; cycle<cyclelimit;cycle++)
        {
            if(newcustomer(min_per_cust))
            {
                if(QueueIsFull(&line))
                    turnaways++;
                else
                {
                    customers++;
                    temp = customertime(cycle);
                    EnQueue(temp,&line);
                }
            }
            if(wait_time <=0 && !QueueIsEmpty(&line))
            {
                DeQueue(&temp,&line);
                wait_time = temp.processtime;
                line_wait += cycle - temp.arrive;
                served++;
            }
            if(wait_time > 0 )
                wait_time--;
            sum_line += QueueItemCount(&line);
        }
        if(customers >0 )
        {
            printf("customers accepted :%ld\n",customers);
            printf("customers served :%ld\n",served);
            printf("turnaways :%ld\n",turnaways);
            printf("average queue size : %.2f\n",(double) sum_line/cyclelimit);
            printf("average wait time :%.2f minutes\n",(double)line_wait/served);
        }
        else
            puts("No customers!");
        EmptyTheQueue(&line);
        printf("enter 's' to  start; enter 'q' to  quitttttt.\n");
    }
    puts("Bye!");
    return 0;
}
bool newcustomer(double x)
{
    if(rand()*x/RAND_MAX<1)
        return true;
    else
        return false;
}
Item customertime(long when)
{
    Item cust;
    cust.processtime = rand()%3 + 1 ;
    cust.arrive = when;
    return cust;
}

void InitProgram()
{
     hours;//模拟的小时数
     perhour;//每小时平均多少位顾客
     cycle,cyclelimit;//循环计数器，计数器的上限
     turnaways = 0;//队列已满被拒绝的顾客数
     customers = 0;//加入队列的顾客数量
     served = 0;//咨询过的顾客数量
     sum_line = 0;//累计的队列总长
     wait_time= 0;//从排队时间
     min_per_cust;//顾客到来的平均时间
     line_wait = 0;//队列累计的等待时间
    InitializeQueue(&line);
}

void char_scanf(char * ch)
{
    //scanf会读取[enter]键的值。而getchar()只会读取一个值
    scanf("%d",ch);
    while(getchar() != '\n')
        continue;
}
void int_scanf(int * integer)
{
    scanf("%d",integer);
    while(getchar() != '\n')
        continue;
}