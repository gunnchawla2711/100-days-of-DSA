#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;

    scanf("%d", &n);

    int *queue = (int*)malloc(n * sizeof(int));

    int front = 0, rear = -1;

    // Enqueue elements
    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);

        rear++;
        queue[rear] = value;
    }

    // Display queue
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }

    free(queue);

    return 0;
}
