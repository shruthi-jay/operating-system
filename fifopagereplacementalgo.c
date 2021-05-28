#include <stdio.h>
#include <stdlib.h>
int n, j, z, page, pages[20], frames[20], try = 0, hit = 0, no_of_miss = 0, no_of_hits = 0;
void print()
{
    int i;
    for (i = 1; i <= n; i++)
        printf("%d     ", frames[i]);
    printf("\n");
}
void tab()
{
    for (int z = 0; z <= n; z++)
    {
        printf("------");
    }

    printf("\n");
}
void replace(int a)
{
    int i;
    for (i = 2, j = 1; j != n; i++, j++)
    {
        frames[j] = frames[i];
    }
    frames[n] = a;
}
void check(int a)
{
    int i;
    for (i = 1; i <= n; i++)
    {
        if (frames[i] == a)
        {
            tab();
            printf("HIT\n");
            hit = 1;
            no_of_hits++;
        }
    }
    if (hit == 0)
    {
        tab();
        printf("MISS\n");
        no_of_miss++;
        replace(a);
    }
    hit = 0;
}
int main()
{
    int i;
    int a, k, ptr, same = 0;
    printf("\n-------------------------------");
    printf("\nPROGRAM  :FIFO PAGE REPLACEMENT ALGORITHM  \n\n");
    printf("---------------------------------\n");
    printf("Enter the  number of frames  :");
    scanf("%d", &n);
    printf("Enter number of pages :");
    scanf("%d", &page);
    printf("\nEnter the pages referring in order \n\n");
    for (i = 1; i <= page; i++)
    {
        printf("reference string  %d :  ", i);
        scanf("%d", &a);
        pages[i] = a;
        if (i <= n)
            frames[i] = -1;
    }
    printf("\n");
    tab();
    printf("MISS\n");
    frames[1] = pages[1];
    print();

    ptr = 2;
    for (i = 2; ptr <= n; i++)
    {
        same = 0;
        for (k = i; k >= 1; k--)
        {
            if (pages[i] == frames[k])
            {
                same = 1;
                break;
            }
        }

        if (same == 0)
        {
            tab();
            printf("MISS\n");
            frames[ptr] = pages[i];
            print();
            ptr++;
        }
        else
        {
            tab();
            printf("HIT\n");
            print();
            no_of_hits++;
        }
    }
    no_of_miss = n;
    try = n;
    while (page != try)
    {
        check(pages[try + 1]);
        print();
        ++try;
    }
    tab();
    tab();
    printf("\nPage Fault : %d   \n", no_of_miss);
    printf("\nNo of hit : %d   \n", no_of_hits);
    printf("\nHit Ratio : %.2f\n", (float)no_of_hits / (float)page);
}




