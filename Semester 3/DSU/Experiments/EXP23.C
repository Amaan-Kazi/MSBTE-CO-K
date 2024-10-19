#include <stdio.h>
#include <conio.h>
#define MAX 20  // Maximum size of the queue

int queue[MAX];
int front = -1, rear = -1;
int i = 0;

void enqueue(int value) {
    if ((rear + 1) % MAX == front) {
	printf("Queue is full!\n");
    } else {
	if (front == -1) {  // First element
	    front = 0;
	}
	rear = (rear + 1) % MAX;
	queue[rear] = value;
	printf("Inserted %d into the queue.\n", value);
    }
}

void dequeue() {
    if (front == -1) {
	printf("Queue is empty!\n");
    } else {
	int value = queue[front];
	if (front == rear) {  // Queue is now empty after dequeue
	    front = rear = -1;
	} else {
	    front = (front + 1) % MAX;
	}
	printf("Deleted %d from the queue.\n", value);
    }
}

void display() {
    if (front == -1) {
	printf("Queue is empty!\n");
    } else {
	printf("Queue elements: ");
	i = front;
        while (1) {
            printf("%d ", queue[i]);
            if (i == rear) break;
            i = (i + 1) % MAX;
        }
        printf("\n");
    }
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
                getch();
        }
    }

    return 0;
}
