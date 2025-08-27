#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* top = NULL;

void push();
int pop();
void display();
void find_max();
void find_min();
void search(int);

int main()
{
    printf("enter your choice to perform below operation=\n"
           "push(int)=1\n"
           "display()=2\n"
           "find_max()=3\n"
           "find_min()=4\n"
           "search(int)=5\n"
           "pop()=6\n");

    while (1)
    {
        int choice;
        printf("\nenter your choice = ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                push();
                printf("element is pushed into the stack.\n");
                break;

            case 2:
                display();
                break;

            case 3:
                find_max();
                break;

            case 4:
                find_min();
                break;

            case 5:
            {
                int sea;
                printf("enter the searching element = ");
                scanf("%d", &sea);
                search(sea);
                break;
            }

            case 6:
            {
                int val = pop();
                if (val != -1)
                    printf("element %d is popped from the stack\n", val);
                break;
            }

            default:
                printf("invalid number for operation\n");
        }
    }
    return 0;
}

void push()
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if (!newnode)
    {
        printf("Memory allocation failed!\n");
        return;
    }
    printf("enter the data = ");
    scanf("%d", &newnode->data);
    newnode->next = top;
    top = newnode;
}

int pop()
{
    if (top == NULL)
    {
        printf("stack underflow\n");
        return -1;
    }
    struct node* temp = top;
    int val = temp->data;
    top = top->next;
    free(temp);
    return val;
}

void display()
{
    if (top == NULL)
    {
        printf("stack is empty\n");
        return;
    }
    printf("stack elements: ");
    struct node* temp;
    for (temp = top; temp != NULL; temp = temp->next)
        printf("%d ", temp->data);
    printf("\n");
}

void find_max()
{
    if (top == NULL)
    {
        printf("stack is empty\n");
        return;
    }
    int max = top->data;
    struct node* temp;
    for (temp = top; temp != NULL; temp = temp->next)
        if (temp->data > max)
            max = temp->data;
    printf("maximum element in stack = %d\n", max);
}

void find_min()
{
    if (top == NULL)
    {
        printf("stack is empty\n");
        return;
    }
    int min = top->data;
    struct node* temp;
    for (temp = top; temp != NULL; temp = temp->next)
        if (temp->data < min)
            min = temp->data;
    printf("minimum element in stack = %d\n", min);
}

void search(int sea)
{
    struct node* temp;
    for (temp = top; temp != NULL; temp = temp->next)
    {
        if (temp->data == sea)
        {
            printf("%d is found in stack\n", sea);
            return;
        }
    }
    printf("%d is not found in stack\n", sea);
}
