#include <stdio.h>
int no_of_frames, no_of_pages, frames[10], pages[30], temp[10];
void tab()
{
    for (int z = 0; z <= no_of_frames; z++)
    {
        printf("------");
    }
    printf("\n");
}
void print()
{
    printf("\n");
    for (int j = 0; j < no_of_frames; ++j)
    {
        printf("%d\t", frames[j]);
    }
    printf("\n");
}
int main()
{
    int flag1, flag2, flag3, i, j, k, pos, max, no_of_hit = 0, no_of_miss = 0;
    printf("\n-------------------------------");
    printf("\nPROGRAM  :OPTIMAL PAGE REPLACEMENT ALGORITHM \n\n");
    printf("---------------------------------\n");
    printf("enter the  number of frames  :");
    scanf("%d", &no_of_frames);
    printf("enter number of pages :");
    scanf("%d", &no_of_pages);
    printf("\nEnter the pages referring in order \n\n");
    for (i = 0; i < no_of_pages; ++i)
    {
        printf("reference string  %d :  ", i + 1);
        scanf("%d", &pages[i]);
        if (i <= no_of_frames)
            frames[i] = -1;
    }
    for (i = 0; i < no_of_pages; ++i)
    {
        flag1 = flag2 = 0;

        for (j = 0; j < no_of_frames; ++j)
        {
            if (frames[j] == pages[i])
            {
                tab();
                printf("HIT\n");
                ++no_of_hit;
                flag1 = flag2 = 1;
                break;
            }
        }

        if (flag1 == 0) //initial frames
        {
            for (j = 0; j < no_of_frames; ++j)
            {
                if (frames[j] == -1)
                {
                    tab();
                    printf("MISS\n");

                    no_of_miss++;
                    frames[j] = pages[i];
                    flag2 = 1;
                    break;
                }
            }
        }

        if (flag2 == 0)
        {
            flag3 = 0;

            for (j = 0; j < no_of_frames; ++j)
            {
                temp[j] = -1;

                for (k = i + 1; k < no_of_pages; ++k)
                {
                    if (frames[j] == pages[k])
                    {
                        temp[j] = k;
                        break;
                    }
                }
            }

            for (j = 0; j < no_of_frames; ++j)
            {
                if (temp[j] == -1)
                {
                    pos = j;
                    flag3 = 1;
                    break;
                }
            }

            if (flag3 == 0)
            {
                max = temp[0];
                pos = 0;

                for (j = 1; j < no_of_frames; ++j)
                {
                    if (temp[j] > max)
                    {
                        max = temp[j];
                        pos = j;
                    }
                }
            }
            frames[pos] = pages[i];
            tab();
            printf("MISS\n");
            no_of_miss++;
        }

        print();
    }
    tab();
    tab();
    printf("\nPage Fault : %d   \n", no_of_miss);
    printf("\nNo of hit : %d   \n", no_of_hit);
    printf("\nHit Ratio : %.2f\n", (float)no_of_hit / (float)no_of_pages);

    return 0;
}

