#include <stdio.h>
#include <stdlib.h>

void Merge (int *arr, int left, int mid, int right) {
    int i = 0, j = 0;
    int *result = malloc((right - left) * sizeof(int));
    while ( (left + i < mid) && (mid + j < right) ) {
        if (arr[left + i] < arr[mid + j]) {
            result[i + j] = arr[left + i];
            i++;
        }
        else {
            result[i + j] = arr[mid + j];
            j++;
        }
    }
    while (left + i < mid) {
        result[i + j] = arr[left + i];
        i++;
    }
    while (mid + j < right) {
        result[i + j] = arr[mid + j];
        j++;
    }
    for (int k = 0; k < i + j; k++) {
        arr[left + k] = result[k];
    }
    free(result);
}

void MergeSort (int *arr, int left, int right) {
    if (left < right - 1) {
        int mid = (left + right) / 2;
        MergeSort(arr, left, mid);
        MergeSort(arr, mid, right);
        Merge(arr, left, mid, right);
    }
}

int main () {
    int n;
    scanf("%d", &n);
    int *arr = malloc(n*sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    MergeSort(arr, 0, n); 
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr);
    return 0;
}
