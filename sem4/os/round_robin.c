#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 100

typedef struct
{
    int processes[QUEUE_SIZE];
    int front;
    int back;
} queue;

queue getQueue()
{
    queue q;
    q.front = 0;
    q.back = -1;
    return q;
}

int isQueueEmpty(queue *q) { return q->back < q->front; }

void addProcess(queue *q, int processId)
{
    q->processes[++q->back] = processId;
}

int getNextProcessInQueue(queue *q)
{
    // automatically removes from queue
    return q->processes[q->front++];
}

void updateQueue(int *arrivalTimes, int *remainingTimes,
                 int *processAlreadyInQueue, int *clock, queue *q,
                 int numberOfProcesses)
{
    if (*clock == 0)
    {
        int min = 0;
        for (int i = 0; i < numberOfProcesses; i++)
        {
            if (arrivalTimes[i] < arrivalTimes[min])
            {
                min = i;
            }
        }
        addProcess(q, min);
        processAlreadyInQueue[min] = 1;
        *clock = arrivalTimes[min];
        return;
    }
    int i = 0;

    while (processAlreadyInQueue[i] || remainingTimes[i] == 0 ||
           arrivalTimes[i] > *clock)
    {
        i++;
    }

    // add processes to queue
    while (i < numberOfProcesses)
    {
        if (!processAlreadyInQueue[i] && remainingTimes[i] != 0 &&
            arrivalTimes[i] <= *clock)
        {
            addProcess(q, i);
            processAlreadyInQueue[i] = 1;
        }
        i++;
    }
}

void findAverageTimes(int *arrivalTimes, int *burstTimes, int tq,
                      int numberOfProcesses)
{
    int *completionTimes = (int *)calloc(numberOfProcesses, sizeof(int));
    int *turnaroundTimes = (int *)calloc(numberOfProcesses, sizeof(int));
    int *waitingTimes = (int *)calloc(numberOfProcesses, sizeof(int));
    int *remainingTimes = (int *)calloc(numberOfProcesses, sizeof(int));
    // array of flags about processes in queue
    int *processAlreadyInQueue = (int *)calloc(numberOfProcesses, sizeof(int));
    int clock = 0;
    queue q = getQueue();

    // copy all burst times in remaining times
    for (int i = 0; i < numberOfProcesses; i++)
    {
        remainingTimes[i] = burstTimes[i];
    }

    updateQueue(arrivalTimes, remainingTimes, processAlreadyInQueue, &clock, &q,
                numberOfProcesses);

    printf("\n");
    // run the main loop
    while (!isQueueEmpty(&q))
    {
        int process = getNextProcessInQueue(&q);
        printf("| P%d ", process + 1);
        if (remainingTimes[process] <= tq)
        {
            clock += remainingTimes[process];
            remainingTimes[process] = 0;
            completionTimes[process] = clock;
            turnaroundTimes[process] =
                completionTimes[process] - arrivalTimes[process];
            waitingTimes[process] =
                turnaroundTimes[process] - burstTimes[process];
            updateQueue(arrivalTimes, remainingTimes, processAlreadyInQueue,
                        &clock, &q, numberOfProcesses);

        } else
        {
            remainingTimes[process] -= tq;
            clock += tq;
            updateQueue(arrivalTimes, remainingTimes, processAlreadyInQueue,
                        &clock, &q, numberOfProcesses);
            addProcess(&q, process);
        }
    }
    printf("|\n\n");
    float averageWaitingTime = 0;
    float averageTurnaroundTime = 0;
    for (int i = 0; i < numberOfProcesses; i++)
    {
        averageWaitingTime += waitingTimes[i];
        averageTurnaroundTime += turnaroundTimes[i];
    }

    averageTurnaroundTime /= numberOfProcesses;
    averageWaitingTime /= numberOfProcesses;

    // display the data

    printf("PID\tAT\tBT\tComp\tTA\tWT\n");
    for (int i = 0; i < numberOfProcesses; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, arrivalTimes[i],
               burstTimes[i], completionTimes[i], turnaroundTimes[i],
               waitingTimes[i]);
    }
    printf("\nAverage Waiting Time: %0.2f\n", averageWaitingTime);
    printf("Average Turn Around Time: %0.2f\n", averageTurnaroundTime);

    free(completionTimes);
    free(turnaroundTimes);
    free(waitingTimes);
    free(processAlreadyInQueue);
    free(remainingTimes);
}

int main()
{
    // does not work for unsorted arrival times
    int arrivalTimes[6] = {0, 1, 2, 3, 4, 6};
    int burstTimes[6] = {4, 5, 2, 1, 6, 3};
    findAverageTimes(arrivalTimes, burstTimes, 2, 6);
    return 0;
}