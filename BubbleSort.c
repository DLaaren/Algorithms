#include <stdio.h>
#include <stdlib.h>

void swap (int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void BubbleSort (int *arr, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = n-1; j > i+1; j--) {
            if (arr[j-1] > arr[j]) {
                swap (&arr[j-1], &arr[j]);
            }
        }
    }
}

int main () {
    int n;
    scanf("%d", &n);
    int *arr = malloc(n*sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    BubbleSort(arr, n); 
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr);
    return 0;
}
