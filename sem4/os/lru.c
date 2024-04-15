#include <stdio.h>
#include <stdlib.h>

#define PAGES 4

void display_page_table(int pages[PAGES], int queue_incomplete, int queue_pointer) {
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
            return j;
            break;
        }
    }
    return -1;
}

void lru_page_replacement(int* ref_string, int ref_size) {
    int pages[PAGES];
    int* times_used = calloc(PAGES, sizeof(int));
    int page_faults = 0;
    int queue_complete = 0;
    int pointer = 0;

    for (int i = 0; i < ref_size; i++) {
        int page = ref_string[i];
        if (queue_complete) {
            // find if page is already present
            int idx_found = find_page(pages, page);
            if (idx_found == -1) {
                // remove least recently used
                int min = 0;
                for (int i=0; i<PAGES; i++) {
                    if (times_used[i] < times_used[min]) {
                        min = i;
                    }
                }
                // replace
                int removed = pages[min];
                printf("Page fault: removed %d\n", removed);
                pages[min] = page;
                times_used[min] = 1;
                page_faults++;
            } else {
                times_used[idx_found]++;
            }
        } else {
            times_used[pointer] = 1;
            pages[pointer++] = page;
            if (pointer == PAGES) {
                queue_complete = 1;
            }
        }
        display_page_table(pages, !queue_complete, pointer);
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
    lru_page_replacement(ref_string, ref_size);
    free(ref_string);
    return 0;
}
