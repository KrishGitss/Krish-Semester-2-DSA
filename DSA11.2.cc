#include <stdio.h>

void countingSort(int arr[], int n) {
    int max = 0;
    for (int i = 0; i < n; i++)
        if (arr[i] > max) max = arr[i];

    int count[max + 1];
    for (int i = 0; i <= max; i++) count[i] = 0;

    for (int i = 0; i < n; i++) count[arr[i]]++;

    int index = 0;
    for (int i = 0; i <= max; i++)
        while (count[i]--) arr[index++] = i;
}

int main() {
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    countingSort(arr, n);

    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    return 0;
}