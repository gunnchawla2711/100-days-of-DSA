#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int prefix = 0;
    int count = 0;

    // Since constraints are not given, using large static array
    // Adjust size if needed
    int freq[200001] = {0};
    int offset = 100000;  // to handle negative prefix sums

    freq[offset] = 1;  // prefix sum 0 seen once

    for(int i = 0; i < n; i++) {
        prefix += arr[i];

        count += freq[prefix + offset];
        freq[prefix + offset]++;
    }

    printf("%d", count);

    return 0;
}
