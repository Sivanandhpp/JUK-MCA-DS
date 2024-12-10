#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

// Node structure for the doubly linked list
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to insert a node at the end of the doubly linked list
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// Function to delete a given integer from the doubly linked list
void deleteNode(struct Node** head, int key) {
    if (*head == NULL) {
        printf("List is empty. Cannot delete %d.\n", key);
        return;
    }

    struct Node* temp = *head;

    // Traverse the list to find the node to delete
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    // If the key was not found
    if (temp == NULL) {
        printf("Element %d not found in the list.\n", key);
        return;
    }

    // If the node to be deleted is the head node
    if (temp == *head) {
        *head = temp->next; // Change head
        if (*head != NULL) {
            (*head)->prev = NULL; // Update previous of new head
        }
    } else {
        temp->prev->next = temp->next; // Bypass the node to be deleted
    }

    // If the node to be deleted is not the last node
    if (temp->next != NULL) {
        temp->next->prev = temp->prev; // Bypass the node to be deleted
    }

    free(temp); // Free the memory
    printf("Deleted: %d\n", key);
}

// Function to display the contents of the doubly linked list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    struct Node* head = NULL;
    int choice, data, key;
    clrscr();

    while (1) {
        printf("\nDoubly Linked List Operations:\n");
        printf("1. Insert an integer\n");
        printf("2. Delete an integer\n");
        printf("3. Display the list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter an integer to insert: ");
                scanf("%d", &data);
                insertEnd(&head, data);
                break;
            case 2:
                printf("Enter an integer to delete: ");
                scanf("%d", &key);
                deleteNode(&head, key);
                break;
            case 3:
                displayList(head);
                break;
            case 4:
                printf("Exiting...\n");
                // Free the list before exiting
                while (head != NULL) {
                    struct Node* temp = head;
                    head = head->next;
                    free(temp);
                }
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    getch();
}