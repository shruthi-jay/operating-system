#include <stdio.h>
#include <stdlib.h>
int frame[20], page[20], priority[20], no_of_page, no_of_frame;
int maxPriority()
{
    int max = 0, index;
    for (int i = 0; i < no_of_frame; i++)
    {
        if (max < priority[i])
        {
            max = priority[i];
            index = i;
        }
    }
    return index;
}
void tab()
{
    for (int z = 0; z <= no_of_frame; z++)
    {
        printf("------");
    }

    printf("\n");
}
void increment(int n)
{
    for (int i = 0; i <= n; i++)
    {
        priority[i]++;
    }
}
int find(int val)
{
    for (int i = 0; i < no_of_frame; i++)
    {
        if (frame[i] == val)
        {
            return i;
        }
    }
    return -1;
}
int check(int val)
{
    for (int i = 0; i < no_of_frame; i++)
    {
        if (frame[i] == val)
            return 1;
    }
    return 0;
}
void print()
{
    for (int i = 0; i < no_of_frame; i++)
    {
        printf("%d   ", frame[i]);
    }
    printf("\n");
}
int main()
{
    int index = 0, hit = 0, miss = 0;
    printf("\n-------------------------------");
    printf("\nPROGRAM  : LRU PAGE REPLACEMENT ALGORITHM \n\n");
    printf("---------------------------------\n");
    printf("enter the  number of frames  :");
    scanf("%d", &no_of_frame);
    printf("enter number of pages :");
    scanf("%d", &no_of_page);
    printf("\nEnter the pages referring in order \n\n");

    for (int i = 0; i < no_of_page; i++)
    {
        printf("reference string  %d :  ", i + 1);
        scanf("%d", &page[i]);
        if (i < no_of_frame)
        {
            frame[i] = -1;
            priority[i] = 0;
        }
    }

    for (int i = 0; i < no_of_page; i++)
    {
   
        if (check(page[i]) == 0)
        {
            miss++;
            tab();
            printf("MISS\n");
            if (frame[no_of_frame - 1] == -1)
            {
                frame[index] = page[i];
                increment(index);
                index++;
                print();
            }
            else
            {
                index = maxPriority();
                frame[index] = page[i];
                priority[index] = 0;
                increment(index);
                print();
            }
        }
        else
        {
            hit++;
            tab();
            printf("HIT\n");
            int j = find(page[i]);
            print();
            if (j > 0)
            {
                priority[j] = 1;
            }
        }
    }
    tab();
    tab();
    printf("\nPage Fault = %d \n", miss);
    printf("\nNo of hit : %d   \n",hit);
    printf("Hit Ratio = %.2f\n", (float)hit / (float)no_of_page);
}

