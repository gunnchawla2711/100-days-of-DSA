#include <stdio.h>
#define MAX 100

int deque[MAX];
int front = -1, rear = -1;

// Check empty
int empty() {
    return front == -1;
}

// Check full
int full() {
    return (rear + 1) % MAX == front;
}

// push_front
void push_front(int x) {
    if (full()) {
        printf("Deque Overflow\n");
        return;
    }

    if (empty()) {
        front = rear = 0;
    } else {
        front = (front - 1 + MAX) % MAX;
    }

    deque[front] = x;
}

// push_back
void push_back(int x) {
    if (full()) {
        printf("Deque Overflow\n");
        return;
    }

    if (empty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }

    deque[rear] = x;
}

// pop_front
void pop_front() {
    if (empty()) {
        printf("-1\n");
        return;
    }

    printf("%d\n", deque[front]);

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

// pop_back
void pop_back() {
    if (empty()) {
        printf("-1\n");
        return;
    }

    printf("%d\n", deque[rear]);

    if (front == rear) {
        front = rear = -1;
    } else {
        rear = (rear - 1 + MAX) % MAX;
    }
}

// front element
void getFront() {
    if (empty()) printf("-1\n");
    else printf("%d\n", deque[front]);
}

// rear element
void getBack() {
    if (empty()) printf("-1\n");
    else printf("%d\n", deque[rear]);
}

// size
int size() {
    if (empty()) return 0;
    return (rear - front + MAX) % MAX + 1;
}

// clear
void clear() {
    front = rear = -1;
}

// display
void display() {
    if (empty()) {
        printf("Empty\n");
        return;
    }

    int i = front;
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}
