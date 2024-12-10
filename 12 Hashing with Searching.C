#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define TABLE_SIZE 10

// Node structure for linked list
typedef struct Node
{
    int key;
    struct Node *next;
} Node;

// Hash table structure
typedef struct HashTable
{
    Node *table[TABLE_SIZE];
} HashTable;

// Function to create a new node
Node *createNode(int key)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->key = key;
    newNode->next = NULL;
    return newNode;
}

// Hash function
int hashFunction(int key)
{
    return key % TABLE_SIZE;
}

// Function to initialize the hash table
HashTable *createHashTable()
{
    HashTable *ht = (HashTable *)malloc(sizeof(HashTable));
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        ht->table[i] = NULL;
    }
    return ht;
}

// Function to insert a key into the hash table
void insert(HashTable *ht, int key)
{
    int index = hashFunction(key);
    Node *newNode = createNode(key);
    newNode->next = ht->table[index];
    ht->table[index] = newNode;
}

// Function to search for a key in the hash table
int search(HashTable *ht, int key)
{
    int index = hashFunction(key);
    Node *current = ht->table[index];
    while (current != NULL)
    {
        if (current->key == key)
        {
            return 1; // Key found
        }
        current = current->next;
    }
    return 0; // Key not found
}

// Function to display the hash table
void displayHashTable(HashTable *ht)
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        printf("Index %d: ", i);
        Node *current = ht->table[i];
        while (current != NULL)
        {
            printf("%d -> ", current->key);
            current = current->next;
        }
        printf("NULL\n");
    }
}

// Main function
int main()
{
    HashTable *ht = createHashTable();
    int choice, key;
    clrscr();
    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Insert key\n");
        printf("2. Search key\n");
        printf("3. Display hash table\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter key to insert: ");
            scanf("%d", &key);
            insert(ht, key);
            printf("Key %d inserted.\n", key);
            break;

        case 2:
            printf("Enter key to search: ");
            scanf("%d", &key);
            if (search(ht, key))
            {
                printf("Key %d found in the hash table.\n", key);
            }
            else
            {
                printf("Key %d not found in the hash table.\n", key);
            }
            break;

        case 3:
            printf("Hash Table:\n");
            displayHashTable(ht);
            break;

        case 4:
            printf("Exiting...\n");
            free(ht); // Free the allocated memory for the hash table (not freeing individual nodes for simplicity)
            return 0;

        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
    getch();
}
