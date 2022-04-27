#include <stdio.h>
#include <stdlib.h>
#define SIZE 3
int s_queue[SIZE];
// init required variable
int front = 0;
int rear = -1;

// Insert Function
void insert()
{
    if (rear == SIZE - 1)
    {
        printf("\nQueue is Full!!!\n");
    }
    else
    {
        int data;
        printf("\nEnter a Data:- ");
        scanf("%d", &data);
        // increase the rear value by one before adding the new data
        rear++;
        // add this data from rear side
        s_queue[rear] = data;
    }
}

// Delete function
void delete ()
{
    if (rear == front - 1)
    {
        printf("\nQueue is Empty!!!\n");
    }
    else
    {
        int i;
        printf("\nDeleted Element is %d\n", s_queue[front]);
        for (i = 0; i < SIZE - 1; i++)
        {
            s_queue[i] = s_queue[i + 1];
        }
        rear--;
    }
}

// Traverse Function
void display()
{
    if (rear == front - 1)
    {
        printf("\nQueue is Empty!!!\n");
    }
    else
    {
        int i;
        printf("\nData :- ");
        for (i = front; i <= rear; i++)
        {
            printf("%d ", s_queue[i]);
        }
    }
}
int main()
{
    int ch;
    while (1)
    {
        printf("\nSimple Queue Operations:-");
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