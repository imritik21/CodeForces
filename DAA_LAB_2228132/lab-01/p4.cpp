#include <stdio.h>

void print(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void exchange(int *p, int *q) {
    int temp = *p;
    *p = *q;
    *q = temp;
}

int main() {
    // Your code here
    int n, k;
    scanf("%d", &n);
    scanf("%d", &k);

    if (n == 1 && k > 1) {
        printf("Not valid k\n");
        return 0;
    }

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < k; i++) {
        exchange(&arr[i], &arr[k-1]);
    }

    print(arr, n);
    return 0;
}
