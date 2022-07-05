#include <stdio.h>
#include <stdlib.h>

void InsertionSort (int *arr, int n) {
    for (int j = 1; j < n; j++) {
        int key = arr[j];
        int i = j - 1;
        while (i >= 0 && arr[i] > key) {
            arr[i+1] = arr[i];
            i--;
        }
        arr[i+1] = key; 
    }
}

int main () {
    int n;
    scanf("%d", &n);
    int *arr = malloc(n*sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    InsertionSort(arr, n); 
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr);
    return 0;
}
