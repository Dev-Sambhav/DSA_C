#include <stdio.h>
#include <stdlib.h>

// define the structure node
struct node
{
    int data;
    struct node *link;
};

// init a pointer head variable which always pointing to first node of list
struct node *head = NULL; // initially there is no node present

// for counting the total length of list
int length;

// This function will insert a new node at the end of the list
void insert_at_end()
{
    // init a temp pointer for getting a new node from the user
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node)); // temp pointer holding a base address of newly created node
    // ask to user
    printf("\nEnter a Node Data: ");
    scanf("%d", &temp->data);
    // set NULL value to link part
    temp->link = NULL;
    // checking if head is NULL or not
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        struct node *temp_2;
        temp_2 = head;
        // we have to traverse to the last node for insert
        while (temp_2->link != NULL)
        {
            temp_2 = temp_2->link;
        }
        temp_2->link = temp; // here temp value is assign to the last node of list
    }
}

// This function will show all the nodes which are present in list
void display()
{
    if (head == NULL)
    {
        printf("\nList is Empty");
    }
    else
    {
        struct node *temp;
        temp = head;
        printf("\nNodes :- ");
        while (temp->link != NULL)
        {
            printf("%d-->", temp->data);
            temp = temp->link;
        }
        printf("%d\n", temp->data);
    }
}

// This function will count the number of nodes present in the list.
int count()
{
    int count = 0;
    if (head == NULL)
    {
        return count;
    }
    else
    {
        struct node *temp;
        temp = head;
        while (temp != NULL)
        {
            count++;
            temp = temp->link;
        }
        return count;
    }
}

// This function will insert a new node at the begin of the list
void insert_at_begin()
{
    // init a temp pointer for getting a new node from the user
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node)); // temp pointer holding a base address of newly created node
    // ask to user
    printf("\nEnter a Node Data: ");
    scanf("%d", &temp->data);
    // set NULL value to link part
    temp->link = NULL;
    // checking if head is NULL or not
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        temp->link = head;
        head = temp;
    }
}

// This function will delete a particular node from the list
void delete ()
{
    int i = 1, loc;
    struct node *temp = head;
    // ask to user
    printf("\nWhich node do you want to delete? : ");
    scanf("%d", &loc);
    // checking entered location is correct or not
    if (loc > count())
    {
        printf("\nThe node which you want to delete is not present inside the list!!!\n");
    }
    else if (loc == 1)
    {
        head = temp->link;
        temp->link = NULL;
        printf("\nNode Successfully Deleted, Data of Node is %d\n", temp->data);
        free(temp);
    }
    else
    {
        while (i < loc - 1)
        {
            temp = temp->link;
            i++;
        }
        struct node *temp_2;
        temp_2 = temp->link;
        temp->link = temp_2->link;
        temp_2->link = NULL;
        printf("\nNode Successfully Deleted, Data of Node is %d\n", temp_2->data);
        free(temp_2);
    }
}

// This function will add a node at specified location in list
void add_after()
{
    int loc, i = 1;
    struct node *temp_2 = head;
    printf("\nAfter which node you want to add a new node? : ");
    scanf("%d", &loc);
    if (count() == 0)
    {
        printf("\nList is Empty! First add a new node to the list\n");
    }
    else if (loc > count())
    {
        printf("\nGiven Location must be in between nodes!!!\n");
    }
    else if (loc == 1)
    {
        printf("\nFor adding at 1st location begin function is already present!!!\n");
    }
    else
    {
        // init a temp pointer for getting a new node from the user
        struct node *temp;
        temp = (struct node *)malloc(sizeof(struct node)); // temp pointer holding a base address of newly created node
        // ask to user
        printf("\nEnter a Node Data: ");
        scanf("%d", &temp->data);
        // set NULL value to link part
        temp->link = NULL;
        while (i < loc)
        {
            temp_2 = temp_2->link;
            i++;
        }
        temp->link = temp_2->link; // right side work
        temp_2->link = temp; // left side work
    }
}
int main()
{
    int ch;
    while (1)
    {
        printf("\nSingle Linked List Operations: ");
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
            add_after();
            break;
        case 4:
            system("cls");
            display();
            break;
        case 5:
            system("cls");
            length = count();
            printf("\nTotal Nodes are %d\n", length);
            break;
        case 6:
            system("cls");
            delete ();
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