#include <stdio.h>
#include <stdlib.h>
#define size 5

// defining stack_array globally because every function needs it
int stack_array[size];

// initializing top variable globally because we uses in every operation
int top = -1; // -1 means stack is initially empty

// define display function
void display()
{   
    // system("cls");
    int i;
    printf("\n\n**************Stack**************\n\n");
    for (i = top; i >= 0; i--)
    {
        printf("\t\t%d\n", stack_array[i]);
    }
    printf("\n**************Stack**************\n\n");
}

// define push function
void push()
{
    int element;
    printf("\nEnter a Data: ");
    scanf("%d", &element);

    // checking stack is overflow or not
    if (top == (size - 1))
    {
        printf("\nStack is Full\n");
        return;
    }

    // first we have to increment the top by 1 so that we can store the new element at top of the stack
    top += 1;
    // now add the new element at top position
    stack_array[top] = element;
    display();
}

// define pop function
int pop()
{
    int pop_value;
    // checking stack is empty or not
    if (top == -1)
    {
        printf("\nStack is Empty");
        exit(1); // abnormal termination
    }
    // first remove the top position value from stack
    pop_value = stack_array[top];
    // now decrement the top by 1
    top -= 1;
    return pop_value; // return the pop value to caller
}

int main()
{
    int ch, pop_data;
    while (1)
    {
        printf("\n1. Push\n2. Pop\nChoose Stack Operation: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            push();
            break;
        case 2:
            pop_data = pop(); // this function will return the removed value
            printf("\nPoped Data is %d", pop_data);
            display();
            break;
        default:
            printf("\nChoose Correct Operation\n ");
            break;
        }
    }
    return 0;
}