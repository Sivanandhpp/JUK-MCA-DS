#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    int height;
};
int height(struct Node *node)
{
    return node ? node->height : 0;
}
int getBalance(struct Node *node)
{
    return node ? height(node->left) - height(node->right) : 0;
}
struct Node *createNode(int key)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}
struct Node *rotateRight(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = 1 + (height(y->left) > height(y->right) ? height(y->left) : height(y->right));
    x->height = 1 + (height(x->left) > height(x->right) ? height(x->left) : height(x->right));
    return x;
}
struct Node *rotateLeft(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = 1 + (height(x->left) > height(x->right) ? height(x->left) : height(x->right));
    y->height = 1 + (height(y->left) > height(y->right) ? height(y->left) : height(y->right));
    return y;
}
struct Node *insert(struct Node *node, int key)
{
    int balance;
    if (!node)
        return createNode(key);
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;
    node->height = 1 + (height(node->left) > height(node->right) ? height(node->left) : height(node->right));
    balance = getBalance(node);
    if (balance > 1 && key < node->left->key)
        return rotateRight(node);
    if (balance < -1 && key > node->right->key)
        return rotateLeft(node);
    if (balance > 1 && key > node->left->key)
    {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    if (balance < -1 && key < node->right->key)
    {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }
    return node;
}
void inOrder(struct Node *root)
{
    if (root)
    {
        inOrder(root->left);
        printf("%d ", root->key);
        inOrder(root->right);
    }
}
int main()
{
    struct Node *root = NULL;
    int i, n, value, choice;
    clrscr();
    do
    {
        printf("\nMenu:\n");
        printf("1. Insert a key\n");
        printf("2. Display in-order traversal\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the key to insert: ");
            scanf("%d", &value);
            root = insert(root, value);
            printf("Key %d inserted.\n", value);
            break;
            getch();
        case 2:
            printf("In-order traversal of the AVL tree: ");
            inOrder(root);
            printf("\n");
            getch();
            break;
        case 3:
            printf("Exiting...\n");
            break;
            getch();
        default:
            printf("Invalid choice. Please try again.\n");
            getch();
        }
    } while (choice != 3);
    return 0;
}
