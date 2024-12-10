#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAX 100

struct Stack
{
    int items[MAX];
    int top;
};

void initialize(struct Stack *s)
{
    s->top = -1;
}
int isEmpty(struct Stack *s)
{
    return s->top == -1;
}
int isFull(struct Stack *s)
{
    return s->top == MAX - 1;
}
void push(struct Stack *s, int value)
{
    if (isFull(s))
    {
        printf("Stack is full. Cannot push %d.", value);
        return;
    }
    s->items[++s->top] = value;
    printf("Pushed %d onto the stack. \n", value);
}
int pop(struct Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is empty. Cannot pop.\n");
        return -1;
    }
    return s->items[s->top--];
}
void show(struct Stack *s)
{
    int i;
    if (isEmpty(s))
    {
        printf("\nUnderflow!!");
    }
    else
    {
        printf("\nElements in the stack: \n");
        for (i = s->top; i >= 0; --i)
            printf("%d\n", s->items[i]);
    }
}
int peak(struct Stack *s)
{
    if (!isEmpty(s))
    {
        printf("Stack is empty. \n");
        return -1;
    }
    return s->items[s->top];
}
int main()
{
    int choice, data;
    struct Stack s;
    initialize(&s);

    clrscr();
    printf("\nStack operations using array. \n");
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
            printf("\nEnter integer to push: ");
            scanf("%d", &data);
            push(&s, data);
            break;
        case 2:
            printf("\nPopped element is %d.\n", pop(&s));
            break;
        case 3:
            show(&s);
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("\nInvalid choice!!");
            break;
        }
    }
    return 0;
}
