#include <stdio.h>

int main() {
    int n, k, i, temp;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter elements: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter K: ");
    scanf("%d", &k);

    k = k % n;

    for(i = 0; i < n / 2; i++) {
        temp = a[i];
        a[i] = a[n - 1 - i];
        a[n - 1 - i] = temp;
    }

    for(i = 0; i < k / 2; i++) {
        temp = a[i];
        a[i] = a[k - 1 - i];
        a[k - 1 - i] = temp;
    }

    for(i = k; i < k + (n - k) / 2; i++) {
        temp = a[i];
        a[i] = a[n - 1 - (i - k)];
        a[n - 1 - (i - k)] = temp;
    }

    printf("Array after rotation: ");

    for(i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}