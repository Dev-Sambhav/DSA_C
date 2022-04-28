#include <stdio.h>
#include <stdlib.h>
// define node structure
struct node
{
    struct node *left;
    int data;
    struct node *right;
};
// declare a global head pointer variable
struct node *head = NULL;

// Append Function
void insert_at_end()
{
    // declare a temp variable
    struct node *temp;
    // create a node
    temp = (struct node *)malloc(sizeof(struct node));
    // ask to user
    printf("\nEnter a Node Data:- ");
    scanf("%d", &temp->data);
    // set NULL to left and right part of newly created node
    temp->left = NULL;
    temp->right = NULL;
    // check if head is null or not
    if (head == NULL)
    {
        // assign temp value to head value
        head = temp;
    }
    else
    {
        // make another temp variable for traversing to the last node
        struct node *temp_2 = head;
        while (temp_2->right != NULL)
        {
            temp_2 = temp_2->right;
        }
        // connection between last node and newly created node
        temp_2->right = temp;
        temp->left = temp_2;
    }
}

// Insert new node at begin
void insert_at_begin()
{
    // declare a temp variable
    struct node *temp;
    // create a node
    temp = (struct node *)malloc(sizeof(struct node));
    // ask to user
    printf("\nEnter a Node Data:- ");
    scanf("%d", &temp->data);
    // set NULL to left and right part of newly created node
    temp->left = NULL;
    temp->right = NULL;
    // check if head is null or not
    if (head == NULL)
    {
        // assign temp value to head value
        head = temp;
    }
    else{
        temp->right = head;
        head->left = temp;
        head = temp;
    }
}
int main()
{

    return 0;
}