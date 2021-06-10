// //// Dynamic memory allocation

#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *ptr;
    int n, p, i;
    printf("\n-------------------------------");
    printf(" \nNAME      :   SRUTHI O T \n");
    printf("\nREGISTER NO :  20352059\n");
    printf("\nDate : 09.06.21 \n");
    printf("\nPROGRAM  :MEMORY MANAGEMENT  \n\n");
    printf("---------------------------------\n");
    printf("\n --------------------\n");
    printf("|       malloc       |\n");
    printf(" --------------------\n");
    printf("Enter number of elements:");
    scanf("%d", &n);
    ptr = (int *)malloc(n * sizeof(int));
    if (ptr == NULL)
    {
        printf("Memory not allocated.\n");
        exit(0);
    }
    else
    {
        printf("Memory successfully allocated using malloc.\n");
        for (i = 0; i < n; ++i)
        {
            printf("enter elements  : ");
            scanf("%d", &p);
            ptr[i] = p;
        }
        printf("The elements of the array are: ");
        for (i = 0; i < n; ++i)
        {
            printf("%d  ", ptr[i]);
        }
    }

    printf("\n\n --------------------\n");
    printf("|       calloc       |\n");
    printf(" --------------------\n");
    printf("Enter number of elements:");
    scanf("%d", &n);
    ptr = (int *)calloc(n, sizeof(int));

    if (ptr == NULL)
    {
        printf("Memory not allocated.\n");
        exit(0);
    }
    else
    {
        printf("Memory successfully allocated using calloc.\n");
        for (i = 0; i < n; ++i)
        {
            printf("enter elements  : ");
            scanf("%d", &p);
            ptr[i] = p;
        }
        printf("The elements of the array are: ");
        for (i = 0; i < n; ++i)
        {
            printf("%d  ", ptr[i]);
        }
        printf("\n\n --------------------\n");
        printf("|       Realloc       |\n");
        printf(" --------------------\n");
        printf("Enter new  number of elements:");
        scanf("%d", &n);
        ptr = realloc(ptr, n * sizeof(int));
        printf("Memory successfully re-allocated using realloc.\n");
        printf("The elements of the array are: ");
        for (i = 0; i < n; ++i)
        {
            printf("%d  ", ptr[i]);
        }
        printf("\n\n --------------------\n");
        printf("|       free         |\n");
        printf(" --------------------\n");
        if (ptr == NULL)
            printf("Memory not allocated in ptr\n");
        else
        {
            free(ptr);
            printf("released memory using free() function\n");
        }

        return 0;
    }
}

