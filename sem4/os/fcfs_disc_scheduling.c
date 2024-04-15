#include <stdio.h>
#include <stdlib.h>

void fcfs(int* requests, int num_requests, int initial_position) {
    int pointer = initial_position;
    int* positions = malloc((num_requests + 1) * sizeof(int));
    positions[0] = initial_position;

    int seek_count = 0;

    for (int i = 1; i <= num_requests; i++) {
        positions[i] = requests[i - 1];
        seek_count += abs(requests[i - 1] - positions[i - 1]);
    }

    printf("Seek sequence: ");
    for (int i = 0; i <= num_requests; i++) {
        printf("%d ", requests[i]);
    }
    printf("\nTotal seek count: %d\n", seek_count);

    free(positions);
}

int main() {
    int requests_array[8] = {176, 79, 34, 60, 92, 11, 41, 114};
    int num_requests = 8;
    int* requests = malloc(num_requests * sizeof(int));
    for (int i = 0; i < num_requests; i++) {
        requests[i] = requests_array[i];
    }
    int initial_postion = 50;
    fcfs(requests, num_requests, initial_postion);
    free(requests);
    return 0;
}
