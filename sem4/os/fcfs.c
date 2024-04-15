#include <stdio.h>
#include <stdlib.h>

int getNextProcess(int* processCompletion, int* arrivalTime,
                   int numberOfProcesses) {
    int min = 0;
    // find the first process not yer
    while (processCompletion[min] == 1)
        min++;
    // all processes are completed then return -1
    if (min >= numberOfProcesses)
        return -1;
    // find minimum
    for (int i = 0; i < numberOfProcesses; i++) {
        if (processCompletion[i] == 1)
            continue;
        if (arrivalTime[i] < arrivalTime[min])
            min = i;
    }
    return min;
}

void findAverageTimes(int* arrivalTime, int* burstTime, int numberOfProcesses) {
    int* processCompletion = (int*)calloc(numberOfProcesses, sizeof(int));
    int* serviceStart = (int*)calloc(numberOfProcesses, sizeof(int));
    int* turnAroundTimes = (int*)calloc(numberOfProcesses, sizeof(int));
    int* completionTime = (int*)calloc(numberOfProcesses, sizeof(int));
    int* waitingTimes = (int*)calloc(numberOfProcesses, sizeof(int));

    int process =
        getNextProcess(processCompletion, arrivalTime, numberOfProcesses);
    // start from first arrival
    int clock = arrivalTime[process];
    printf("\nGantt Chart: ");
    while (process != -1) {
        // service starts at clock time
        serviceStart[process] = clock;

        // it had to wait for some time
        waitingTimes[process] = serviceStart[process] - arrivalTime[process];

        // clock increments till process executes
        clock += burstTime[process];

        // Process Completed
        completionTime[process] = clock;

        // turnaraound time is total time spent by process
        turnAroundTimes[process] = waitingTimes[process] + burstTime[process];

        // mark process complete and go to next process
        processCompletion[process] = 1;
        process =
            getNextProcess(processCompletion, arrivalTime, numberOfProcesses);
        // print out which process was executed
        printf("| P%d ", process + 1);
    }
    printf("|\n\n");
    float averageWaitingTime = 0;
    float averageTurnaroundTime = 0;
    for (int i = 0; i < numberOfProcesses; i++) {
        averageWaitingTime += waitingTimes[i];
        averageTurnaroundTime += turnAroundTimes[i];
    }
    averageWaitingTime /= numberOfProcesses;
    averageTurnaroundTime /= numberOfProcesses;

    // display the data

    printf("PID\tA.T.\tB.T.\tStart\tComp\tT.A.\tW.T.\n");
    for (int i = 0; i < numberOfProcesses; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, arrivalTime[i],
               burstTime[i], serviceStart[i], completionTime[i],
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

int main() {
    int arrivalTime[6] = {11, 12, 3, 3, 4, 5};
    int burstTime[6] = {4, 5, 3, 7, 1, 6};
    findAverageTimes(arrivalTime, burstTime, 6);
    return 0;
}
