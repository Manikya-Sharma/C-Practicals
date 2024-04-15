#include <stdio.h>
#include <stdlib.h>

int find_next(int* requests, int* completed, int num, int position) {
    int min = 0;
    while (min < num && completed[min])
        min++;
    // all requests have been served
    if (min == num)
        return -1;

    for (int i = min; i < num; i++) {
        if (!completed[i] &&
            (abs(requests[i] - position) < abs(requests[min] - position))) {
            min = i;
        }
    }
    return min;
}

void sstf(int* requests, int num_requests, int initial_position) {
    int* positions = malloc((num_requests + 1) * sizeof(int));
    positions[0] = initial_position;
    int seek_count = 0;
    int* completed_requests = (int*)calloc(num_requests, sizeof(int));
    completed_requests[0] = 1;

    for (int i = 1; i < num_requests; i++) {
        int next_position = find_next(requests, completed_requests,
                                      num_requests, positions[i - 1]);
        seek_count += abs(positions[i - 1] - requests[next_position]);
        positions[i] = requests[next_position];
        completed_requests[next_position] = 1;
    }

    printf("Seek sequence: ");
    for (int i = 0; i <= num_requests; i++) {
        printf("%d ", positions[i]);
    }
    printf("\nTotal seek count: %d\n", seek_count);
    free(positions);
    free(completed_requests);
}

int main() {
    int requests_array[7] = {82, 170, 43, 140, 24, 16, 190};
    int num_requests = 7;
    int* requests = malloc(num_requests * sizeof(int));
    for (int i = 0; i < num_requests; i++) {
        requests[i] = requests_array[i];
    }
    int initial_postion = 50;
    sstf(requests, num_requests, initial_postion);
    free(requests);
    return 0;
}
