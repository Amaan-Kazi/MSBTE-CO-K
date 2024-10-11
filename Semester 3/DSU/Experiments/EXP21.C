#include <stdio.h>
#include <conio.h>
#define MAX 20  // Maximum size of the queue

int queue[MAX];
int front = -1, rear = -1;

int main() {
	int choice, value, i;

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
				if (rear == MAX - 1)
					printf("Queue is full!\n");
				else {
					if (front == -1)
						front = 0;  // First element
					printf("Enter value to enqueue: ");
					scanf("%d", &value);
					rear++;
					queue[rear] = value;
					printf("Inserted %d into the queue.\n", value);
				}
				getch();
				break;

			case 2: // Dequeue
				if (front == -1 || front > rear)
					printf("Queue is empty!\n");
				else
				{
					value = queue[front];
					front++;
					printf("Deleted %d from the queue.\n", value);
				}
				getch();
				break;

			case 3: // Display
				if (front == -1 || front > rear)
					printf("Queue is empty!\n");
				else
				{
					printf("Queue elements: ");
					for (i = front; i <= rear; i++)
					{
						printf("%d ", queue[i]);
					}
					printf("\n");
				}
				getch();
				break;

			default:
				printf("Invalid choice! Please try again.\n");
		}
	}

	return 0;
}
