#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node* next;
};

struct HashTable {
    int size;
    struct Node** table;
};

int hashFunction(int key, int size) {
    return key % size;
}

struct HashTable* createTable(int size) {
    struct HashTable* h = (struct HashTable*)malloc(sizeof(struct HashTable));
    h->size = size;
    h->table = (struct Node*)malloc(size * sizeof(struct Node));
    for (int i = 0; i < size; i++)
        h->table[i] = NULL;
    return h;
}

void insertItem(struct HashTable* h, int key) {
    int index = hashFunction(key, h->size);
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->next = h->table[index];
    h->table[index] = newNode;
}

int searchItem(struct HashTable* h, int key) {
    int index = hashFunction(key, h->size);
    struct Node* curr = h->table[index];
    while (curr != NULL) {
        if (curr->key == key) return 1;
        curr = curr->next;
    }
    return 0;
}

void deleteItem(struct HashTable* h, int key) {
    int index = hashFunction(key, h->size);
    struct Node* curr = h->table[index];
    struct Node* prev = NULL;
    while (curr != NULL) {
        if (curr->key == key) {
            if (prev == NULL)
                h->table[index] = curr->next;
            else
                prev->next = curr->next;
            free(curr);
            printf("Deleted %d\n", key);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    printf("Key %d not found\n", key);
}

void displayTable(struct HashTable* h) {
    for (int i = 0; i < h->size; i++) {
        printf("Bucket %d: ", i);
        struct Node* curr = h->table[i];
        while (curr != NULL) {
            printf("%d -> ", curr->key);
            curr = curr->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int size, choice, key;
    printf("Enter hash table size: ");
    scanf("%d", &size);
    struct HashTable* h = createTable(size);

    while (1) {
        printf("\n1.Insert 2.Search 3.Delete 4.Display 5.Exit\n Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter key: ");
                scanf("%d", &key);
                insertItem(h, key);
                break;
            case 2:
                printf("Enter key: ");
                scanf("%d", &key);
                if (searchItem(h, key))
                    printf("Key %d found\n", key);
                else
                    printf("Key %d not found\n", key);
                break;
            case 3:
                printf("Enter key: ");
                scanf("%d", &key);
                deleteItem(h, key);
                break;
            case 4:
                displayTable(h);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}