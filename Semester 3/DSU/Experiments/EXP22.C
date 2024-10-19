#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* front = NULL;
Node* rear = NULL;
Node* temp = NULL;
Node* current = NULL;

int value = 0;

void enqueue(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL) {
	front = rear = newNode;  // First element
    } else {
	rear->next = newNode;
	rear = newNode;
    }
    printf("Inserted %d into the queue.\n", value);
}

void dequeue() {
    if (front == NULL) {
	printf("Queue is empty!\n");
	return;
    }

    temp = front;
    value = front->data;
    front = front->next;

    if (front == NULL) {
	rear = NULL;  // Queue is now empty
    }

    free(temp);
    printf("Deleted %d from the queue.\n", value);
}

void display() {
    if (front == NULL) {
	printf("Queue is empty!\n");
	return;
    }

    current = front;
    printf("Queue elements: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
	clrscr();
	printf("Menu:\n");
	printf("0: Exit\n");
	printf("1: Enqueue\n");
	printf("2: Dequeue\n");
	printf("3: Display\n");
	printf("Enter your choice: ");
	scanf("%d", &choice);

	switch (choice) {
	    case 0:
		printf("Exiting...\n");
		return 0;

	    case 1: // Enqueue
		printf("Enter value to enqueue: ");
		scanf("%d", &value);
		enqueue(value);
		getch();
		break;

	    case 2: // Dequeue
		dequeue();
		getch();
		break;

	    case 3: // Display
		display();
		getch();
		break;

	    default:
		printf("Invalid choice! Please try again.\n");
	}
    }

    return 0;
}
