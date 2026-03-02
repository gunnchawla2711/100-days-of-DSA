#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);

    if (head == NULL)
        return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Find node by value in first list
struct Node* findNode(struct Node* head, int value) {
    while (head != NULL) {
        if (head->data == value)
            return head;
        head = head->next;
    }
    return NULL;
}

// Get length
int getLength(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

// Find intersection
struct Node* findIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    int diff = abs(len1 - len2);

    // Move pointer of longer list
    if (len1 > len2) {
        for (int i = 0; i < diff; i++)
            head1 = head1->next;
    } else {
        for (int i = 0; i < diff; i++)
            head2 = head2->next;
    }

    // Traverse together
    while (head1 != NULL && head2 != NULL) {
        if (head1 == head2)
            return head1;

        head1 = head1->next;
        head2 = head2->next;
    }

    return NULL;
}

int main() {
    int n, m, value;

    struct Node* head1 = NULL;
    struct Node* head2 = NULL;

    scanf("%d", &n);

    // First list
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        head1 = insertEnd(head1, value);
    }

    scanf("%d", &m);

    // Second list (simulate intersection)
    struct Node* temp2 = NULL;

    for (int i = 0; i < m; i++) {
        scanf("%d", &value);

        struct Node* intersectNode = findNode(head1, value);

        if (intersectNode != NULL) {
            if (head2 == NULL)
                head2 = intersectNode;
            else
                temp2->next = intersectNode;
            break;  // remaining nodes already connected
        } else {
            struct Node* newNode = createNode(value);
            if (head2 == NULL)
                head2 = newNode;
            else
                temp2->next = newNode;
            temp2 = newNode;
        }
    }

    struct Node* intersection = findIntersection(head1, head2);

    if (intersection != NULL)
        printf("%d", intersection->data);
    else
        printf("No Intersection");

    return 0;
}
