#include <stdio.h>

int minn(int a, int b) {
    if (a < b) return a;
    else return b;
}

int maxx(int a, int b) {
    if (a > b) return a;
    else return b;
}

void max_min(int *arr, int l, int h, int *max, int *min) {
    if (l == h) {
        *max = maxx(*max, arr[l]);
        *min = minn(*min, arr[l]);
        return;
    } else if (l == h - 1) {
        
        if (arr[l] < arr[h]) {
            *max = maxx(*max, arr[h]);
            *min = minn(*min, arr[l]);
        } else {
            *max = maxx(*max, arr[l]);
            *min = minn(*min, arr[h]);
        }
        return;
    }

    // divide
    int mid = l + (h - l) / 2;
    max_min(arr, l, mid, max, min);
    max_min(arr, mid + 1, h, max, min);
}

int main() {
    int n;
    printf("Enter size of arr: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int max = (-1LL) * (1e9 + 7);
    int min = 1e9 + 7;

    max_min(arr, 0, n - 1, &max, &min);

    printf("min: %d  max: %d\n", min, max);

    return 0;
}
