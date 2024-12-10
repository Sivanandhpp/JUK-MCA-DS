#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

// Define the structure for a node in the BST
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new key into the BST
struct Node *insert(struct Node *root, int data)
{
    if (root == NULL)
    {
        return createNode(data);
    }
    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
    }
    return root;
}

// Function to search for a given key in the BST
struct Node *search(struct Node *root, int key)
{
    // Base case: root is null or key is present at root
    if (root == NULL || root->data == key)
    {
        return root;
    }
    // Key is greater than root's data
    if (key > root->data)
    {
        return search(root->right, key);
    }
    // Key is smaller than root's data
    return search(root->left, key);
}

// Main function to demonstrate the BST operations
int main()
{
    clrscr();
    struct Node *root = NULL;
    int choice, value, key;

    // Menu-driven approach for inserting and searching
    do
    {
        printf("\nMenu:\n");
        printf("1. Insert a value\n");
        printf("2. Search for a value\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            root = insert(root, value);
            printf("Inserted %d into the BST.\n", value);
            break;
        case 2:
            printf("Enter value to search: ");
            scanf("%d", &key);
            struct Node *result = search(root, key);
            if (result != NULL)
            {
                printf("Value %d found in the BST.\n", key);
            }
            else
            {
                printf("Value %d not found in the BST.\n", key);
            }
            break;
        case 3:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}
