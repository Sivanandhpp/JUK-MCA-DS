#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(struct Node** head_ref, int new_data) {
    struct Node* newNode = createNode(new_data);
    struct Node* last = *head_ref;

    if (*head_ref == NULL) {
        *head_ref = newNode;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }

    last->next = newNode;
    newNode->prev = last;
}


void deleteNode(struct Node** head_ref, int key) {
    struct Node* temp = *head_ref;

    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value %d not found in the list.\n", key);
        return;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        *head_ref = temp->next;    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    free(temp);
    printf("Deleted %d from the list.\n", key);
}

void displayList(struct Node* node) {
    if (node == NULL) {
        printf("The list is empty.\n");
        return;
    }

    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


int main() {
    struct Node* head = NULL;
    int i,num, ele, del;
    printf("Enter Number of elements in doubly link list:");
    scanf("%d",&num);
    for(i =1; i<=num;i++){
	printf("Enter element %d: ",i);
	scanf("%d",&ele);
	insertEnd(&head, ele);
    }

    printf("Current list: ");
    displayList(head);

     printf("Enter enter element to be deleted from doubly link list:");
    scanf("%d",&del);

    deleteNode(&head, del);

    printf("List after deleting %d: ", del);
    displayList(head);

    getch();
}