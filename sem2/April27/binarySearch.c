#include <stdio.h>

int main()
{
    int n, item, res=-1;
    printf("size?");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i <= n - 1; i = i + 1)
    {
        scanf("%d", &arr[i]);
    }

    printf("Item to search?");
    scanf("%d", &item);

    int lo=0, hi=n-1;

    while (lo<hi)
    {
        int mid = (lo+hi)/2;
        if (arr[mid] < item)
            lo=mid+1;
        else if (arr[mid]>item)
            hi=mid-1;
        else
        {
            res=mid;
            break;
        }
    }
    printf("The index of %d in array is %d\n", item, res);
    return 0;
}