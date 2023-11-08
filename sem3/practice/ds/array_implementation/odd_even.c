#include<stdio.h>

void partition_even_odd(int*arr, int n)
{
    int ptr1 = 0;
    int ptr2 = 0;
    while (ptr2 < n) {
        if (arr[ptr2] % 2 == 0) {
            int temp = arr[ptr1];
            arr[ptr1] = arr[ptr2];
            arr[ptr2] = temp;
            ptr1++;
        }
        ptr2++;
    }
}

int main() {
    int arr[8] = {2, 5, 1, 3, 6, 8, 7, 0};
    partition_even_odd(arr, 8);
    for (int i=0; i<8; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
