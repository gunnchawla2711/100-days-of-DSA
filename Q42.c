#include <stdio.h>
#define MAX 1000

// Stack
int stack[MAX];
int top = -1;

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int isEmpty() {
    return top == -1;
}

int main() {
    int n;
    scanf("%d", &n);

    int queue[MAX];

    // Input queue
    for (int i = 0; i < n; i++) {
        scanf("%d", &queue[i]);
    }

    // Step 1: Push all elements into stack
    for (int i = 0; i < n; i++) {
        push(queue[i]);
    }

    // Step 2: Pop from stack (reversed order)
    while (!isEmpty()) {
        printf("%d ", pop());
    }

    return 0;
}
