// Circular Queue Operations Using Array
#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
int c_queue[SIZE];
int front = -1;
int rear = -1;
// Insert Function
void insert()
{
    int data;
    printf("\nEnter a Data:- ");
    scanf("%d", &data);
    // check whether Circular Queue is full or not
    if ((rear == SIZE - 1 && front == 0) || (front == rear + 1))
    {
        printf("\nCircular Queue is Full!!!\n");
    }
    else if (rear == -1 && front == -1)
    {
        rear = 0;
        front = 0;
        c_queue[rear] = data;
    }
    else if (rear == SIZE - 1 && front != 0)
    {
        rear = 0;
        c_queue[rear] = data;
    }
    else
    {
        // increase the rear value by one before inserting
        rear++;
        // assign data from rear side
        c_queue[rear] = data;
    }
}

// Delete Function
void delete ()
{
    int data;
    // check whether Circular Queue is empty or not
    if (rear == -1 && front == -1)
    {
        printf("\nCircular Queue is Empty!!!\n");
    }
    else if (front == rear)
    {
        data = c_queue[front];
        printf("\nDelete data:- %d\n", data);
        rear = front = -1;
    }
    else if (front == SIZE - 1)
    {
        data = c_queue[front];
        printf("\nDelete data:- %d\n", data);
        front = 0;
    }
    else
    {
        data = c_queue[front];
        printf("\nDelete data:- %d\n", data);
        front++;
    }
}

// Traverse Function
void display()
{
    int i, j;
    if (front == -1 && rear == -1)
    {
        printf("\nCircular Queue is empty!!!\n");
    }
    else if (rear > front)
    {
        printf("\nElements:- ");
        for (i = front; i <= rear; i++)
        {
            printf("%d  ", c_queue[i]);
        }
        printf("\n");
    }
    else
    {
        printf("\nElements:- ");
        for (j = front; j <= SIZE - 1; j++)
        {
            printf("%d  ", c_queue[j]);
        }
        for (i = 0; i <= rear; i++)
        {
            printf("%d  ", c_queue[i]);
        }
        printf("\n");
    }
}

int main()
{
    int ch;
    while (1)
    {
        printf("\nCircular Queue Operations:-");
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