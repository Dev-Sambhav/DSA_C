// Stack Operations Using Single Linked List
#include <stdio.h>
#include <stdlib.h>
// defining node structure
struct node
{
    int data;
    struct node *link;
};
// init top variable with NULL value
struct node *top = NULL;

// Push Function
void push()
{
    // creating a temp variable for performing push operation
    struct node *temp;
    // making a node in somewhere stack
    temp = (struct node *)malloc(sizeof(struct node));
    // asking to user
    printf("\nEnter node data: ");
    scanf("%d", &temp->data);
    // set link part of temp node with top value;
    temp->link = top;
    // assign temp value to top
    top = temp;
}

// Pop Function
void pop()
{
    // check if stack is empty or not
    if (top == NULL)
    {
        printf("\nStack is Empty!!!\n");
    }
    else
    {
        struct node *temp = top;
        // change the top value so that it can point to next node
        top = temp->link;
        // show user to data of deleted node
        printf("\nNode Successfully Popped from Stack, Data of Node is %d\n", temp->data);
        // assign link part of last node to NULL so that it lost the connection
        temp->link = NULL;
        // free the deleted node
        free(temp);
    }
}

// Display Function
void display()
{
    // check if stack is empty or not
    if (top == NULL)
    {
        printf("\nStack is Empty!!!\n");
    }
    else
    {
        struct node *temp;
        temp = top;
        // printf("\nNodes :- ");
        printf("\n\n****************Stack**************\n\n");
        while (temp->link != NULL)
        {
            printf("\t\t %d\n", temp->data);
            printf("\t\t  |\n");
            temp = temp->link;
        }
        printf("\t\t %d\n", temp->data);
        printf("\n****************Stack**************\n\n");
    }
}
int main()
{
    int ch;
    while (1)
    {
        printf("\nStack Operations Using Single Linked List");
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(1);
            break;

        default:
            break;
        }
    }

    return 0;
}