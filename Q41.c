#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

struct Node *front = NULL, *rear = NULL;

// Enqueue
void enqueue(int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;

    if (rear == NULL) {
        front = rear = temp;
    } else {
        rear->next = temp;
        rear = temp;
    }
}

// Dequeue
void dequeue() {
    if (front == NULL) {
        printf("-1\n");
        return;
    }

    struct Node* temp = front;
    printf("%d\n", front->data);

    front = front->next;

    if (front == NULL) {
        rear = NULL;
    }

    free(temp);
}

int main() {
    int N;
    scanf("%d", &N);

    while (N--) {
        char op[10];
        scanf("%s", op);

        if (strcmp(op, "enqueue") == 0) {
            int x;
            scanf("%d", &x);
            enqueue(x);
        } 
        else if (strcmp(op, "dequeue") == 0) {
            dequeue();
        }
    }

    return 0;
}
