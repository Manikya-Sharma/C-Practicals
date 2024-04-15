#include <stdio.h>
#include <stdlib.h>

#define PAGES 3

void display_page_table(int pages[PAGES], int queue_pointer,
                        int queue_incomplete) {
    printf("Page table: ");
    for (int i = 0; i < PAGES; i++) {
        if (queue_incomplete && i >= queue_pointer)
            continue;
        printf("%d ", pages[i]);
    }
    printf("\n");
}

int find_page(int pages[PAGES], int page) {
    for (int j = 0; j < PAGES; j++) {
        if (pages[j] == page) {
            return 1;
            break;
        }
    }
    return 0;
}

void fifo_page_replacement(int* ref_string, int ref_size) {
    // Queue to maintain fifo
    int pages[PAGES];
    int queue_pointer = 0;
    int queue_incomplete = 1;
    int page_faults = 0;

    for (int i = 0; i < ref_size; i++) {
        int page = ref_string[i];
        if (queue_incomplete) {
            pages[queue_pointer++] = page;
            if (queue_pointer == PAGES) {
                // now implement fifo
                queue_pointer = 0;
                queue_incomplete = 0;
            }
        } else {
            // find if the page is already present in queue
            if (!find_page(pages, page)) {
                printf("Page fault: removed ");
                int removed = pages[queue_pointer];
                printf("%d\n", removed);
                page_faults++;
                pages[queue_pointer] = page;
                queue_pointer = (queue_pointer + 1) % PAGES;
            }
        }
        display_page_table(pages, queue_pointer, queue_incomplete);
    }
    printf("Total number of page faults = %d\n", page_faults);
}

int main() {
    int ref_string_arr[20] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3,
                              0, 3, 2, 1, 2, 0, 1, 7, 0, 1};
    int ref_size = 20;
    int* ref_string = malloc(ref_size * sizeof(int));

    for (int i = 0; i < ref_size; i++) {
        ref_string[i] = ref_string_arr[i];
    }

    // display ref string
    printf("Ref string: ");
    for (int i = 0; i < ref_size; i++) {
        printf("%d ", ref_string[i]);
    }
    printf("\n");
    fifo_page_replacement(ref_string, ref_size);
    free(ref_string);
    return 0;
}
