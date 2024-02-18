#include <stdio.h>
#include <stdlib.h>

int getNextProcess(int *arrivalTimes, int *isProcessCompleted, int *priority,
                   int isHighNumberHighPriority, int clock,
                   int numberOfProcesses)
{
    if (clock == -1)
    {
        // the first process is the one which arrived first, irrespective of its
        // priority
        int min = 0;
        for (int i = 0; i < numberOfProcesses; i++)
        {
            if (arrivalTimes[i] < arrivalTimes[min])
            {
                min = i;
            }
        }
        return min;
    }
    int min = 0;
    while (isProcessCompleted[min])
    {
        min++;
    }
    if (min >= numberOfProcesses)
        return -1;
    for (int i = min; i < numberOfProcesses; i++)
    {
        if (isProcessCompleted[i] || arrivalTimes[i] > clock)
        {
            // process has not yet arrived or it is already completed
            continue;
        }
        if (isHighNumberHighPriority)
        {
            if (priority[i] > priority[min])
            {
                min = i;
            }
        } else
        {
            if (priority[i] < priority[min])
            {
                min = i;
            }
        }
    }
    return min;
}

void findAverageTimes(int *arrivalTimes, int *bustTimes, int *priority,
                      int isHighNumberHighPriority, int numberOfProcesses)
{
    int *completionTimes = (int *)calloc(numberOfProcesses, sizeof(int));
    int *turnAroundTimes = (int *)calloc(numberOfProcesses, sizeof(int));
    int *waitingTimes = (int *)calloc(numberOfProcesses, sizeof(int));
    int *isProcessCompleted = (int *)calloc(numberOfProcesses, sizeof(int));
    int clock = -1;
    int process =
        getNextProcess(arrivalTimes, isProcessCompleted, priority,
                       isHighNumberHighPriority, clock, numberOfProcesses);
    clock = arrivalTimes[process];
    printf("\n");
    while (process != -1)
    {

        waitingTimes[process] = clock - arrivalTimes[process];

        clock += bustTimes[process];

        completionTimes[process] = clock;

        turnAroundTimes[process] = waitingTimes[process] + bustTimes[process];

        isProcessCompleted[process] = 1;

        process =
            getNextProcess(arrivalTimes, isProcessCompleted, priority,
                           isHighNumberHighPriority, clock, numberOfProcesses);
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
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, arrivalTimes[i], bustTimes[i],
               completionTimes[i], turnAroundTimes[i], waitingTimes[i]);
    }
    printf("\nAverage Waiting Time: %0.2f\n", averageWaitingTime);
    printf("Average Turn Around Time: %0.2f\n", averageTurnaroundTime);

    free(completionTimes);
    free(turnAroundTimes);
    free(waitingTimes);
    free(isProcessCompleted);
}

int main()
{
    int arrivalTime[6] = {1, 2, 3, 4, 5, 6};
    int bustTime[6] = {4, 5, 1, 2, 3, 6};
    int priority[6] = {4, 5, 7, 2, 1, 6};
    findAverageTimes(arrivalTime, bustTime, priority, 1, 6);

    return 0;
}