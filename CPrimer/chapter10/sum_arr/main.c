#include <stdio.h>
/*
 *
 * C Prime 程序清单10.10
 *
 * */

#define SIZE 10

int sum_a(int ar[],int n);
int sum_b(int ar[],int n);
int main() {
   int marbles[SIZE] = {20,10,5,39,4,16,19,26,31,20};
   long answer_a = sum_a(marbles,SIZE);
    printf("The total number of marbles is %ld.\n",answer_a);
    long answer_b = sum_a(marbles,SIZE);
    printf("The total number of marbles is %ld.\n",answer_b);
    printf("The size of marbles is %2d bytes.\n",sizeof(marbles));//40.因为10个int，每个占4byte.
    return 0;
}
int sum_a(int ar[],int n)
{
    int i;
    int total = 0;
    for(i=0;i<n;i++)
        total += ar[i];
    printf("The size of ar is %d bytes.\n",sizeof(ar));
    return total;
}
int sum_b(int *ar,int n)
{
    int i;
    int total = 0;
    for(i=0;i<n;i++)
        total += ar[i];
    printf("The size of ar is %d bytes.\n",sizeof(ar));
    return total;
}