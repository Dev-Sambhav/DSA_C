#include <stdio.h>
#include <stdlib.h>
// define a node
struct node
{
    int data;
    struct node *link;
};
// declare a front and rear pointer variable
struct node *front = NULL, *rear = NULL;

// Insert Function
void insert()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter a Node Data:- ");
    scanf("%d", &temp->data);
    temp->link = NULL;
    if (rear == NULL && front == NULL)
    {
        front = rear = temp;
    }
    else
    {
        rear->link = temp;
        rear = temp;
    }
}

// Delete Function
void delete ()
{
    if (front == NULL)
    {
        printf("\nQueue is Empty!!!\n");
    }
    else
    {
        struct node *temp = front;
        front = temp->link;
        free(temp);
    }
}

// Display Function
void display()
{
    if (front == NULL)
    {
        printf("\nQueue is Empty!!!\n");
    }
    else
    {
        struct node *temp;
        temp = front;
        printf("\nNodes:- ");
        while (temp->link != NULL)
        {
            printf("%d-->", temp->data);
            temp = temp->link;
        }
        printf("%d\n", temp->data);
    }
}
int main()
{
    int ch;
    while (1)
    {
        printf("\nSimple Queue Operations by Linked List:-");
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit");
        printf("\nEnter your choice:- ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert();
            break;
        case 2:
            delete ();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(1);

        default:
            printf("\nWrong Choice");
            break;
        }
    }
    return 0;
}