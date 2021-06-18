// ALGORITHM:
// 1. Start
// 2. Input the processes, their burst time (bt) and arrival time (at)
// 3 Set currentTime=arrivalTime of smallest process
// 4. Sort the processes according to burst time
// 5. Create an array remaining time to keep track of remaining burst time of processes, initialize it with the burst time array
// 6. Traverse until all processes get completely executed
//    a) From remaining array,find process   with minimum remaining time whose current_time >= arrival and completed=0 
//    b) Reduce its remaining time by 1 and increment current_time
//    c)  if its remaining time becomes 0 then,
//             1) set completed=1
//             2)completionTime=current_time
//             3)Find turn around time and waiting time  
//              	  turnaroundtime = completionTime - arrivalTime;
//              	  waitingTime = turnaroundTime - burst[i];
//    d)sort  the remaining time array
// 7. Find average waiting time = total_waiting_time / no_of_processes
// 8. Find average turnaround time = total_turnaround_time / no_of_processes
// 9. End

#include <stdio.h>
int n, i, o = 1, j = 0, temp, store = 0, completionTime = 0, proc[10], loop, smallest, remaining[10], current_time, arrival[10] = {0}, completed[10] = {0}, tat, order[30], wt, burst[10] = {0}, chart[50] = {0};
float total_tat = 0, total_wt = 0;
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void Sort(int arr[], int n)
{
    int i, j;
    for (i = 1; i < n; i++)
        for (j = i + 1; j <= n; j++)
            if (arr[i] > arr[j])
            {
                swap(&proc[i], &proc[j]);
                swap(&arrival[i], &arrival[j]);
                swap(&burst[i], &burst[j]);
                swap(&remaining[i], &remaining[j]);
            }
}

int main()
{
    printf("\n-------------------------------");
    printf("\nPROGRAM  : SHORTEST REMAINING TIME FIRST\n\n");
    printf("---------------------------------\n");
    printf("Enter no of process : ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        printf("\nArrival time of process %d is :", i);
        scanf("%d", &arrival[i]);
        printf("\nBurst time of process %d is :", i);
        scanf("%d", &burst[i]);
        remaining[i] = burst[i];
        proc[i] = i;
        completed[i] = 0;
    }
    Sort(burst, n);
    smallest = arrival[1];
    j = smallest;
    for (loop = 1; loop <= n; loop++)
    {
        if (smallest > arrival[loop])
        {
            smallest = arrival[loop];
            j = loop;
        }
    }
    current_time = smallest;
    j = 0;
    printf("\n\n             arrival_time       Burst_time    Turn_around_time    waiting_time     completion time\n");
    while (j != n)
    {

        for (i = 1; i <= n; i++)
        {
            if (current_time >= arrival[i] && completed[i] == 0)
            {
                remaining[i] = remaining[i] - 1;
                ++current_time;
                chart[o] = proc[i];
                ++o;
                if (remaining[i] == 0)
                {
                    completed[i] = 1;
                    completionTime = current_time;
                    tat = completionTime - arrival[i];
                    wt = tat - burst[i];
                    total_wt += wt;
                    total_tat += tat;
                    j++;
                    printf("\nprocess%d            %d             %d                  %d                 %d               %d", proc[i], arrival[i], burst[i], tat, wt, completionTime);
                }
                i = 0;
            }
        }
        Sort(remaining, n);
    }

    total_wt = total_wt / n;
    total_tat = total_tat / n;
    printf("\n\nChart :\t");
    for (i = 1; i < o; i++)
    {
        if (store == chart[i])
            continue;
        printf("->%d ", chart[i]);
        store = chart[i];
    }
    // printf("\ncomplete order of execution:\t");
    // for(i=1;i<o;i++)
    // {
    //     printf("->%d ",chart[i]);
    // }
    printf("\n\n Average waiting time is %.2f", total_wt);
    printf("\n Average turn around time is around time is %.2f", total_tat);
}
