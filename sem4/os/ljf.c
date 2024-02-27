#include <stdio.h>
#include <stdlib.h>

int getNextProcess(int *arrivalTimes, int *isProcessCompleted, int *burstTimes,
                   int clock, int numberOfProcesses)
{
    if (clock == -1)
    {
        // the first process is the one which arrived first, irrespective of its
        // burst time
        int max = 0;
        for (int i = 0; i < numberOfProcesses; i++)
        {
            if (arrivalTimes[i] < arrivalTimes[max])
            {
                max = i;
            }
        }
        return max;
    }
    int max = 0;
    while (isProcessCompleted[max])
    {
        max++;
    }
    if (max >= numberOfProcesses)
        return -1;
    for (int i = max; i < numberOfProcesses; i++)
    {
        if (isProcessCompleted[i] || arrivalTimes[i] > clock)
        {
            // process has not yet arrived or it is already completed
            continue;
        }
        if (burstTimes[i] > burstTimes[max])
        {
            max = i;
        }
    }
    return max;
}

void findAverageTimes(int *arrivalTimes, int *burstTimes, int numberOfProcesses)
{
    int *completionTimes = (int *)calloc(numberOfProcesses, sizeof(int));
    int *turnAroundTimes = (int *)calloc(numberOfProcesses, sizeof(int));
    int *waitingTimes = (int *)calloc(numberOfProcesses, sizeof(int));
    int *isProcessCompleted = (int *)calloc(numberOfProcesses, sizeof(int));
    int clock = -1;
    int process = getNextProcess(arrivalTimes, isProcessCompleted, burstTimes,
                                 clock, numberOfProcesses);
    clock = arrivalTimes[process];
    printf("\n");
    while (process != -1)
    {

        waitingTimes[process] = clock - arrivalTimes[process];

        clock += burstTimes[process];

        completionTimes[process] = clock;

        turnAroundTimes[process] = waitingTimes[process] + burstTimes[process];

        isProcessCompleted[process] = 1;

        process = getNextProcess(arrivalTimes, isProcessCompleted, burstTimes,
                                 clock, numberOfProcesses);
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
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, arrivalTimes[i], burstTimes[i],
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
    int arrivalTime[5] = {0, 1, 2, 3, 4};
    int burstTime[5] = {3, 2, 4, 5, 6};
    findAverageTimes(arrivalTime, burstTime, 5);

    return 0;
}