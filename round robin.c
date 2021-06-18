// 1. Start
// 2. Input the processes, their burst time , arrival time and time quantum
// 3. Create an array remaining time to keep track of remaining burst time of processes, initialize it with the burst time array
// 4. Traverse remaining array until all processes get completely executed
//           a) find process   with minimum arrival time with    remainingTime !=0
//           b)If remainingtime<=Quantum,
//                 a)set current_time +=remainingTime
//                 b)set completionTime = current_time + arrivalTime[1];
//                 c)set remainingTime = 0;
//                 d)set turnaroundTime = completionTime - arrivalTime;
//                 e)set waitingTime = turnaroundTime - burstTime;
//             else
//                 a)current_time += quantum;
//                 b)remainingTime -= quatum;
// 5. Find average waiting time = total_waiting_time / no_of_processes 
// 6. Find average turnaround time = total_turnaround_time / no_of_processes 
// 7. End

#include <stdio.h>
int n, i, j, time, temp = 0, t, count = 0, completionTime[10], tat[10], wt[10], current_time = 0, burst[10] = {0}, left[10] = {0}, order[10] = {0}, arrival[10] = {0};
float total_tat = 0, total_wt = 0;
void swap(int *xp, int *yp)
{
    int t = *xp;
    *xp = *yp;
    *yp = t;
}
void Sort(int arr[], int n)
{
    int i, j;
    for (i = 1; i < n; i++) //j < n-i-1 if using bubble sort
        // Last i elements are already in place
        for (j = i + 1; j <= n; j++)
            if (arr[i] > arr[j])
            {
                swap(&arrival[i], &arrival[j]);
                swap(&burst[i], &burst[j]);
                swap(&left[i], &left[j]);
                swap(&order[i], &order[j]);
            }
}
int main()
{
    printf("\n-------------------------------");
    printf("---ROUND ROBIN SCHEDULING---\n");
    printf("Enter no of process   :  ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        printf("\nArrival time of process %d is  :", i);
        scanf("%d", &arrival[i]);
        printf("\nBurst time of process %d is  :", i);
        scanf("%d", &burst[i]);
        left[i] = burst[i];
        order[i] = i;
    }
    printf("enter time quantum :");
    scanf("%d", &time);
    Sort(arrival, n);
    while (count != n)
    {
        for (i = 1; i <= n; i++)
        {
            if (left[i] == 0)
                continue;
            else
            {
                if (left[i] <= time)
                {
                    current_time += left[i];
                    completionTime[i] = current_time;
                    left[i] = 0;
                    count++;
                }
                else
                {
                    current_time += time;
                    left[i] -= time;
                }
            }
        }
    }

    total_wt = total_wt / n;
    total_tat = total_tat / n;

    printf("\n             arrival_time       Burst_time Turn_around_time waiting_time   completion time");
    for (i = 1; i <= n; i++)
    {
        printf("\nprocess%d            %d             %d           %d                 %d                 %d", order[i], arrival[i], burst[i], tat[i], wt[i], completionTime[i]);
    }
    printf("\n\n Average waiting time is  %.2f", total_wt);
    printf("\n Average turn around time is around time is %.2f", total_tat);
}
