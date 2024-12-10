#include <stdio.h>
#include <stdlib.h>
#define MAX 5

struct Queue
{
    int items[MAX];
    int front, rear;
};

// Function to create an empty queue
struct Queue *createQueue()
{
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    q->front = 0;
    q->rear = -1;
    return q;
}

// Enqueue function (insert at rear)
void enqueue(struct Queue *q, int value)
{
    if (q->rear == MAX - 1)
    {
        printf("Queue Overflow.\n");
        return;
    }
    q->items[++q->rear] = value;
    printf("Enqueued: %d\n", value);
}

// Dequeue function (remove from front)
void dequeue(struct Queue *q)
{
    if (q->front > q->rear)
    {
        printf("Queue Underflow.\n");
        return;
    }
    printf("Dequeued: %d\n", q->items[q->front++]);
}

// Display queue
void displayQueue(struct Queue *q)
{
    if (q->front > q->rear)
    {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue: ");
    for (int i = q->front; i <= q->rear; i++)
    {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}

int main()
{
    struct Queue *q = createQueue();
    int choice, value;

    do
    {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display Queue\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter value to enqueue: ");
            scanf("%d", &value);
            enqueue(q, value);
            break;
        case 2:
            dequeue(q);
            break;
        case 3:
            displayQueue(q);
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice != 4);

    return 0;
}
