#include <stdio.h>
#include <stdlib.h>

// Node structure for doubly linked list
struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the list
void insertEnd(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    struct Node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

// Function to delete a node with a specific value
void deleteNode(struct Node **head, int key)
{
    struct Node *temp = *head;

    // If the list is empty
    if (temp == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    // Traverse the list to find the node to delete
    while (temp != NULL && temp->data != key)
    {
        temp = temp->next;
    }

    // If the node is not found
    if (temp == NULL)
    {
        printf("Node with value %d not found!\n", key);
        return;
    }

    // If the node to be deleted is the head
    if (*head == temp)
    {
        *head = temp->next;
    }

    // Change the next of the previous node
    if (temp->prev != NULL)
    {
        temp->prev->next = temp->next;
    }

    // Change the prev of the next node
    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }

    free(temp);
    printf("Node with value %d deleted!\n", key);
}

// Function to display the contents of the doubly linked list
void displayList(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    struct Node *temp = head;
    printf("Doubly linked list: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    struct Node *head = NULL;

    // Insert integers into the doubly linked list
    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);
    insertEnd(&head, 40);
    insertEnd(&head, 50);

    // Display the list before deletion
    printf("Original ");
    displayList(head);

    // Delete a node with a specific value
    deleteNode(&head, 30);

    // Display the list after deletion
    printf("After deletion ");
    displayList(head);

    return 0;
}
