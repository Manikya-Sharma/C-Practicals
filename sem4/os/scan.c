#include <stdio.h>
#include <stdlib.h>

int find_next(int* requests, int* completed, int num_requests, int position,
              int* direction) {
    int next = 0;
    if (*direction == 0) {
        // move backward
        while (completed[next] || requests[next] > position)
            next++;
        int flag = 0;
        for (int i = next; i < num_requests; i++) {
            if (!completed[i] && requests[i] >= requests[next] &&
                requests[i] < position) {
                flag = 1;
                next = i;
            }
        }
        if (!flag) {
            *direction = 1;
        }
    } else {
        // move forward
        while (completed[next] || requests[next] <= position)
            next++;
        int flag = 0;
        for (int i = next; i < num_requests; i++) {
            if (!completed[i] && requests[i] < requests[next]) {
                flag = 1;
                next = i;
            }
        }
        if (!flag) {
            *direction = 1;
        }
    }
    return next;
}

void scan(int* requests, int num_requests, int initial_position) {
    // implement SCAN algorithm
    int* completed = malloc(num_requests * sizeof(int));
    for (int i = 0; i < num_requests; i++) {
        completed[i] = 0;
    }
    int position = initial_position;
    int direction = 0;
    int seek_count = 0;
    int distance, cur_track;
    int* left = malloc(num_requests * sizeof(int));
    int* right = malloc(num_requests * sizeof(int));
}

int main() {
    int requests_array[8] = {176, 79, 34, 60, 92, 11, 41, 114};
    int num_requests = 8;
    int* requests = malloc(num_requests * sizeof(int));
    for (int i = 0; i < num_requests; i++) {
        requests[i] = requests_array[i];
    }
    int initial_postion = 50;
    scan(requests, num_requests, initial_postion);
    free(requests);
}
