#include <stdio.h>
#include <stdlib.h>
// Node structure for the linked list
struct Node
{
    int data;
    struct Node *next;
};
// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
// Function to insert a node at the end of the list
void insertNode(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        struct Node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
// Function to delete a node with a given value
void deleteNode(struct Node **head, int key)
{
    struct Node *temp = *head, *prev = NULL;

    // If the head node itself holds the key to be deleted
    if (temp != NULL && temp->data == key)
    {
        *head = temp->next;
        free(temp);
        return;
    }
    // Search for the key to be deleted
    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }
    // If the key was not present in the list
    if (temp == NULL)
    {
        printf("Integer %d not found in the list.\n", key);
        return;
    }
    // Unlink the node from the list and free it
    prev->next = temp->next;
    free(temp);
}
// Function to display the contents of the list
void displayList(struct Node *head)
{
    struct Node *temp = head;
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    printf("Linked List: ");
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
// Main function
int main()
{
    struct Node *head = NULL;
    int choice, data, key;

    while (1)
    {
        printf("\n1. Insert Integer\n2. Delete Integer\n3. Display
         List\n4. Exit\nEnter your choice:");    
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter integer to insert: ");
            scanf("%d", &data);
            insertNode(&head, data);
            break;
        case 2:
            printf("Enter integer to delete: ");
            scanf("%d", &key);
            deleteNode(&head, key);
            break;
        case 3:
            displayList(head);
            break;
        case 4:
            exit(0);
            break;

        default:
            printf("Invalid choice!\n");
            break;
        }
    }
    return 0;
}
