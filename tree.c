// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node* lchild;
    int data;
    struct node* rchild;
};

struct node* root = NULL;
struct node* current;
struct node* previous;

// Function declarations
struct node* create_node(int);
struct node* insert_bst(int);
struct node* display(struct node*);
struct node* delete_leafnode(int);
struct node* delete_nodewithonenode(int);

int n;

int main()
{
    int *a;
    printf("Enter the value of n = ");
    scanf("%d", &n);
    a = (int*)malloc(n * sizeof(int));

    printf("Enter the elements of the array = ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < n; i++) {
        insert_bst(a[i]);
    }

    printf("\nElements in tree = ");
    display(root);

    int key;
    printf("\nEnter the deleting value (leaf node) key = ");
    scanf("%d", &key);
    delete_leafnode(key);

    printf("\nElements in tree after deleting leaf node = ");
    display(root);

    int key1;
    printf("\nEnter the deleting value (one child node) key = ");
    scanf("%d", &key1);
    delete_nodewithonenode(key1);

    printf("\nElements in tree after deleting one-child node = ");
    display(root);

    return 0;
}


struct node* create_node(int item)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = item;
    newnode->lchild = NULL;
    newnode->rchild = NULL;
    return newnode;
}


struct node* insert_bst(int item)
{
    if (root == NULL) {
        root = create_node(item);
    } else {
        current = root;
        previous = NULL;
        while (1) {
            if (item < current->data) {
                previous = current;
                current = current->lchild;
                if (current == NULL) {
                    previous->lchild = create_node(item);
                    return root;
                }
            } else {
                previous = current;
                current = current->rchild;
                if (current == NULL) {
                    previous->rchild = create_node(item);
                    return root;
                }
            }
        }
    }
    return root;
}


struct node* display(struct node* current)
{
    if (current != NULL) {
        display(current->lchild);
        printf("%d ", current->data);
        display(current->rchild);
    }
    return root;
}


struct node* delete_leafnode(int key)
{
    if (root == NULL) {
        printf("Tree is empty.\n");
        return root;
    }

    current = root;
    previous = NULL;

    while (current != NULL) {
        if (key < current->data) {
            previous = current;
            current = current->lchild;
        } else if (key > current->data) {
            previous = current;
            current = current->rchild;
        } else { 
            if (current->lchild == NULL && current->rchild == NULL) { 
                if (previous == NULL) {
                    free(current);
                    root = NULL;
                } else if (previous->lchild == current) {
                    free(current);
                    previous->lchild = NULL;
                } else {
                    free(current);
                    previous->rchild = NULL;
                }
            } else {
                printf("Node is not a leaf.\n");
            }
            return root;
        }
    }
    printf("Key not found.\n");
    return root;
}


struct node* delete_nodewithonenode(int key1)
{
    if (root == NULL) {
        printf("Tree is empty.\n");
        return root;
    }

    current = root;
    previous = NULL;

    while (current != NULL) {
        if (key1 < current->data) {
            previous = current;
            current = current->lchild;
        } else if (key1 > current->data) {
            previous = current;
            current = current->rchild;
        } else { 
            if ((current->lchild == NULL) ^ (current->rchild == NULL)) { 
                struct node* child = (current->lchild != NULL) ? current->lchild : current->rchild;

                if (previous == NULL) { 
                    free(current);
                    root = child;
                } else if (previous->lchild == current) {
                    free(current);
                    previous->lchild = child;
                } else {
                    free(current);
                    previous->rchild = child;
                }
            } else {
                printf("Node has 0 or 2 children (not 1).\n");
            }
            return root;
        }
    }
    printf("Key not found.\n");
    return root;
}
