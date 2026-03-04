#include <stdio.h>
#define MAX 1000

int stack[MAX];
int top = -1;

// Push operation
void push(int value) {
    if (top < MAX - 1) {
        stack[++top] = value;
    }
}

// Pop operation
void pop() {
    if (top >= 0) {
        top--;
    }
}

// Display stack from top to bottom
void display() {
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
}

int main() {
    int n, m, value;

    scanf("%d", &n);

    // Push n elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        push(value);
    }

    scanf("%d", &m);

    // Perform m pops
    for (int i = 0; i < m; i++) {
        if (top >= 0)
            pop();
    }

    // Display remaining elements
    display();

    return 0;
}
