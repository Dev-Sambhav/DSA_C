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

// declare a length variable
int len;

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

// Find total length of Double Linked List
int length()
{
    int count = 0;
    // check whether list is empty or not
    if (head == NULL)
    {
        printf("\nList is Empty!!!\n");
    }
    else
    {
        // storing head value into temp for counting
        struct node *temp = head;
        while (temp != NULL)
        {
            count++;
            temp = temp->right;
        }
    }
    return count;
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
    else
    {
        temp->right = head;
        head->left = temp;
        head = temp;
    }
}
int main()
{
    int ch;
    while (1)
    {
        printf("\nDouble Linked List Operations:- \n");
        printf("\n1. Insert at End\n2. Insert at Begin\n3. Add After\n4. Display\n5. Length\n6. Delete\n7. Exit");
        printf("\nEnter Your Choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            system("cls");
            insert_at_end();
            break;
        case 2:
            system("cls");
            insert_at_begin();
            break;
        case 3:
            system("cls");
            // add_after();
            break;
        case 4:
            system("cls");
            // display();
            break;
        case 5:
            system("cls");
            len = length();
            printf("\nTotal Nodes are %d\n", len);
            break;
        case 6:
            system("cls");
            // delete ();
            break;
        case 7:
            exit(1);
            break;
        default:
            printf("\nWrong Choice!!!\n");
            break;
        }
    }

    return 0;
}