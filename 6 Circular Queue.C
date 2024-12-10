#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

// Node structure for the linked list
struct Node
{
    int data;
    struct Node *next;
};

// Circular Queue structure
struct CircularQueue
{
    struct Node *front;
    struct Node *rear;
};

// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize the circular queue
struct CircularQueue *createQueue()
{
    struct CircularQueue *queue = (struct CircularQueue *)malloc(sizeof(struct CircularQueue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

// Function to check if the queue is empty
int isEmpty(struct CircularQueue *queue)
{
    return (queue->front == NULL);
}

// Function to enqueue an element
void enqueue(struct CircularQueue *queue, int data)
{
    struct Node *newNode = createNode(data);
    if (isEmpty(queue))
    {
        queue->front = newNode;
        queue->rear = newNode;
        newNode->next = newNode; // Point to itself
    }
    else
    {
        queue->rear->next = newNode;
        queue->rear = newNode;
        newNode->next = queue->front; // Make it circular
    }
    printf("Enqueued: %d\n", data);
}

// Function to dequeue an element
int dequeue(struct CircularQueue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1; // Indicate that the queue is empty
    }
    int data = queue->front->data;
    if (queue->front == queue->rear)
    { // Only one element
        free(queue->front);
        queue->front = NULL;
        queue->rear = NULL;
    }
    else
    {
        struct Node *temp = queue->front;
        queue->rear->next = queue->front->next; // Bypass the front node
        queue->front = queue->front->next;      // Move front to the next node
        free(temp);
    }
    printf("Dequeued: %d\n", data);
    return data;
}

// Function to display the queue
void displayQueue(struct CircularQueue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty.\n");
        return;
    }
    struct Node *temp = queue->front;
    printf("Queue elements: ");
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != queue->front);
    printf("\n");
}

// Main function
int main()
{
    struct CircularQueue *queue = createQueue();
    int choice, data;
    clrscr();

    while (1)
    {
        printf("\nCircular Queue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data to enqueue: ");
            scanf("%d", &data);
            enqueue(queue, data);
            break;
        case 2:
            dequeue(queue);
            break;
        case 3:
            displayQueue(queue);
            break;
        case 4:
            printf("Exiting...\n");
            free(queue); // Free the queue structure
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    getch();
}