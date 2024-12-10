#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void push(struct Node **top, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Stack overflow!\n");
        return;
    }
    newNode->data = value;
    newNode->next = *top;
    *top = newNode;
    printf("\nPushed %d onto the stack.", value);
}

int pop(struct Node **top)
{
    struct Node *temp = *top;
    int value = temp->data;
    if (*top == NULL)
    {
        printf("\nStack overflow!");
        return -1;
    }
    *top = (*top)->next;
    free(temp);
    return value;
}

int isEmpty(struct Node *top)
{
    return top == NULL;
}

void display(struct Node *top)
{
    struct Node *temp = top;
    if (isEmpty(top))
    {
        printf("\nStack is empty!");
        return;
    }
    printf("\nStack elements: \n");
    while (temp != NULL)
    {
        printf("\n%d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int choice, data;
    struct Node *stack = NULL;
    printf("\nStack operations using linked list. ");
    while (1)
    {
        printf("\n1. Push element");
        printf("\n2. Pop element");
        printf("\n3. Show stack");
        printf("\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter element to push: ");
            scanf("%d", &data);
            push(&stack, data);
            break;
        case 2:
            printf("\nPopped element is %d.", pop(&stack));
            break;
        case 3:
            display(stack);
            break;
        case 4:
            exit(0);
        default:
            printf("\nInvalid choice!!");
            break;
        }
    }
    return 0;
}
