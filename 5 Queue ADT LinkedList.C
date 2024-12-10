#include <stdio.h>
#include <stdlib.h>

// Node definition for Linked List
struct Node
{
    int data;
    struct Node *next;
};

// Queue with front and rear pointers
struct Queue
{
    struct Node *front;
    struct Node *rear;
};

// Function to create an empty queue
struct Queue *createQueue()
{
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

// Enqueue function (insert at rear)
void enqueue(struct Queue *q, int value)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = value;
    temp->next = NULL;
    if (q->rear == NULL)
    {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
    printf("Enqueued: %d\n", value);
}

// Dequeue function (remove from front)
void dequeue(struct Queue *q)
{
    if (q->front == NULL)
    {
        printf("Queue is empty.\n");
        return;
    }
    struct Node *temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL)
    {
        q->rear = NULL;
    }
    printf("Dequeued: %d\n", temp->data);
    free(temp);
}

// Display queue
void displayQueue(struct Queue *q)
{
    if (q->front == NULL)
    {
        printf("Queue is empty.\n");
        return;
    }
    struct Node *temp = q->front;
    printf("Queue: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
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
