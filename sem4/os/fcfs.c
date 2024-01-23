#include <stdio.h>
#include <stdlib.h>

int getNextProcess(int *processCompletion, int *arrivalTime,
                   int numberOfProcesses)
{
    int min = 0;
    while (processCompletion[min] == 1)
    {
        min++;
    }
    // all processes are completed then return -1
    if (min >= numberOfProcesses)
        return -1;
    // find minimum
    for (int i = 0; i < numberOfProcesses; i++)
    {
        if (processCompletion[i] == 1)
            continue;
        if (arrivalTime[i] < arrivalTime[min])
        {
            min = i;
        }
    }
    return min;
}

void findAverageTimes(int *arrivalTime, int *bustTime, int numberOfProcesses)
{
    int *processCompletion = (int *)calloc(numberOfProcesses, sizeof(int));
    int *serviceStart = (int *)calloc(numberOfProcesses, sizeof(int));
    int *turnAroundTimes = (int *)calloc(numberOfProcesses, sizeof(int));
    int *completionTime = (int *)calloc(numberOfProcesses, sizeof(int));
    int *waitingTimes = (int *)calloc(numberOfProcesses, sizeof(int));

    int process =
        getNextProcess(processCompletion, arrivalTime, numberOfProcesses);
    // start from first arrival
    int clock = arrivalTime[process];
    while (process != -1)
    {
        // service starts at clock time
        serviceStart[process] = clock;

        // it had to wait for some time
        waitingTimes[process] = serviceStart[process] - arrivalTime[process];

        // clock increments till process executes
        clock += bustTime[process];

        // Process Completed
        completionTime[process] = clock;

        // turnaraound time is total time spent by process
        turnAroundTimes[process] = waitingTimes[process] + bustTime[process];

        // mark process complete and go to next process
        processCompletion[process] = 1;
        process =
            getNextProcess(processCompletion, arrivalTime, numberOfProcesses);
    }

    float averageWaitingTime = 0;
    float averageTurnaroundTime = 0;
    for (int i = 0; i < numberOfProcesses; i++)
    {
        averageWaitingTime += waitingTimes[i];
        averageTurnaroundTime += turnAroundTimes[i];
    }
    averageWaitingTime /= numberOfProcesses;
    averageTurnaroundTime /= numberOfProcesses;

    // display the data

    printf("PID\tAT\tBT\tStart\tComp\tTA\tWT\n");
    for (int i = 0; i < numberOfProcesses; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, arrivalTime[i],
               bustTime[i], serviceStart[i], completionTime[i],
               turnAroundTimes[i], waitingTimes[i]);
    }
    printf("\nAverage Waiting Time: %0.2f\n", averageWaitingTime);
    printf("Average Turn Around Time: %0.2f\n", averageTurnaroundTime);

    free(processCompletion);
    free(completionTime);
    free(serviceStart);
    free(turnAroundTimes);
    free(waitingTimes);
}

int main()
{
    int arrivalTime[6] = {16, 2, 3, 1, 4, 5};
    int bustTime[6] = {4, 5, 3, 1, 2, 6};
    findAverageTimes(arrivalTime, bustTime, 6);
    return 0;
}