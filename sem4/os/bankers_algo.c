#include <stdio.h>
#include <stdlib.h>

int completed(int* finished, int num_processes) {
    for (int i = 0; i < num_processes; i++) {
        if (!finished[i])
            return 0;
    }
    return 1;
}

int* determine_safe_sequence(int* resources, int** allocation,
                             int** max_allocation, int num_processes,
                             int num_resources) {
    // determine the available resources
    int* available = (int*)malloc(num_resources * sizeof(int));
    for (int i = 0; i < num_resources; i++) {
        available[i] = resources[i];
    }
    for (int i = 0; i < num_processes; i++) {
        for (int j = 0; j < num_resources; j++) {
            available[j] -= allocation[i][j];
        }
    }
    // determine the need for each process
    int** need = (int**)malloc(num_processes * sizeof(int*));
    for (int i = 0; i < num_processes; i++) {
        need[i] = (int*)malloc(num_resources * sizeof(int));
        for (int j = 0; j < num_resources; j++) {
            need[i][j] = max_allocation[i][j] - allocation[i][j];
        }
    }
    // determine the safe sequence
    int* safe_sequence = (int*)malloc(num_processes * sizeof(int));
    int* finished = (int*)calloc(num_processes, sizeof(int));
    int k = 0;
    while (1) {
        // check if all processes are completed
        if (completed(finished, num_processes))
            break;
        // this flag remains 0 if no safe sequence exists
        int process_possible = 0;
        for (int i = 0; i < num_processes; i++) {
            if (finished[i])
                continue;
            int can_be_completed = 1;
            for (int j = 0; j < num_processes; j++) {
                if (need[i][j] > available[j]) {
                    can_be_completed = 0;
                    break;
                }
            }
            if (can_be_completed) {
                process_possible = 1;
                // mark the process completed
                finished[i] = 1;
                // release its resources
                for (int j = 0; j < num_resources; j++) {
                    available[j] += allocation[i][j];
                }
                // add it to safe sequence
                safe_sequence[k++] = i;
            }
        }
        if (!process_possible) {
            printf("No safe seqeunce exists\n");
            break;
        }
    }
    return safe_sequence;
}

int main() {
    int num_processes = 5;
    int num_resources = 3;
    int resources_raw[3] = {10, 5, 7};
    int allocation_raw[5][3] = {
        {0, 1, 0}, {2, 0, 0}, {3, 0, 2}, {2, 1, 1}, {0, 0, 2}};
    int max_allocation_raw[5][3] = {
        {7, 5, 3}, {3, 2, 2}, {9, 0, 2}, {2, 2, 2}, {4, 3, 3}};

    // prepare parameters for function call
    int* resources = (int*)malloc(num_resources * sizeof(int));
    for (int i = 0; i < num_resources; i++) {
        resources[i] = resources_raw[i];
    }
    int** allocation = (int**)malloc(num_processes * sizeof(int*));
    for (int i = 0; i < num_processes; i++) {
        allocation[i] = (int*)malloc(num_resources * sizeof(int));
        for (int j = 0; j < num_resources; j++) {
            allocation[i][j] = allocation_raw[i][j];
        }
    }
    int** max_allocation = (int**)malloc(num_processes * sizeof(int*));
    for (int i = 0; i < num_processes; i++) {
        max_allocation[i] = (int*)malloc(num_resources * sizeof(int));
        for (int j = 0; j < num_resources; j++) {
            max_allocation[i][j] = max_allocation_raw[i][j];
        }
    }
    int* sequence = determine_safe_sequence(
        resources, allocation, max_allocation, num_processes, num_resources);
    for (int i = 0; i < num_processes; i++) {
        printf("%d ", sequence[i]);
    }
    printf("\n");
    return 0;
}
