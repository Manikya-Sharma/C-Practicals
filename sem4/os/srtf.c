#include <stdio.h>
#include <stdlib.h>

int getNextProcess(int *arrivalTimes, int *isProcessCompleted, int *remainingTimes,
                   int clock, int numberOfProcesses)
{
    if (clock == -1)
    {
        // the first process is the one which arrived first, irrespective of its burst time
        int min = 0;
        for (int i = 0; i < numberOfProcesses; i++)
        {
            if (arrivalTimes[i] < arrivalTimes[min])
                min = i;
        }
        return min;
    }
    int min = 0;
    while (isProcessCompleted[min])
        min++;
    if (min >= numberOfProcesses)
        return -1;
    for (int i = min; i < numberOfProcesses; i++)
    {
        // process has not yet arrived or it is already completed
        if (isProcessCompleted[i] || arrivalTimes[i] > clock)
            continue;
        if (remainingTimes[i] < remainingTimes[min])
            min = i;
    }
    return min;
}

void findAverageTimes(int *arrivalTimes, int *burstTimes, int numberOfProcesses)
{
    int *completionTimes = (int *)calloc(numberOfProcesses, sizeof(int));
    int *turnAroundTimes = (int *)calloc(numberOfProcesses, sizeof(int));
    int *waitingTimes = (int *)calloc(numberOfProcesses, sizeof(int));
    int *isProcessCompleted = (int *)calloc(numberOfProcesses, sizeof(int));
    int *remainingTimes = (int *)calloc(numberOfProcesses, sizeof(int));
    // assign burst times to remaining times
    for (int i = 0; i < numberOfProcesses; i++)
        remainingTimes[i] = burstTimes[i];
    int clock = -1;
    int process = getNextProcess(arrivalTimes, isProcessCompleted, burstTimes,
                                 clock, numberOfProcesses);
    clock = arrivalTimes[process];
    printf("\nGantt Chart: ");
    while (process != -1)
    {
        // update waiting time for rest of processes
        for (int i = 0; i < numberOfProcesses; i++)
        {
            if (i == process || isProcessCompleted[i] ||
                clock < arrivalTimes[i])
                // these processes have not waited
                continue;
            waitingTimes[i]++;
        }
        // update current process
        clock += 1;
        remainingTimes[process] -= 1;
        turnAroundTimes[process] = waitingTimes[process] + burstTimes[process];
        if (remainingTimes[process] == 0)
        {
            completionTimes[process] = clock;
            isProcessCompleted[process] = 1;
        }
        process = getNextProcess(arrivalTimes, isProcessCompleted,
                                 remainingTimes, clock, numberOfProcesses);
        // print out which process was executed
        printf("| P%d ", process + 1);
    }
    printf("|\n\n");
    float averageWaitingTime = 0;
    float averageTurnaroundTime = 0;
    for (int i = 0; i < numberOfProcesses; i++)
    {
        averageWaitingTime += waitingTimes[i];
        averageTurnaroundTime += turnAroundTimes[i];
    }
    averageTurnaroundTime /= numberOfProcesses;
    averageWaitingTime /= numberOfProcesses;
    // display the data
    printf("PID\tAT\tBT\tComp\tTA\tWT\n");
    for (int i = 0; i < numberOfProcesses; i++)
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, arrivalTimes[i], burstTimes[i],
               completionTimes[i], turnAroundTimes[i], waitingTimes[i]);
    printf("\nAverage Waiting Time: %0.2f\n", averageWaitingTime);
    printf("Average Turn Around Time: %0.2f\n", averageTurnaroundTime);
    free(completionTimes);
    free(turnAroundTimes);
    free(waitingTimes);
    free(isProcessCompleted);
    free(remainingTimes);
}

int main()
{
    int arrivalTime[6] = {0, 1, 2, 3, 4, 5};
    int burstTime[6] = {7, 5, 3, 1, 2, 1};
    findAverageTimes(arrivalTime, burstTime, 6);
    return 0;
}
