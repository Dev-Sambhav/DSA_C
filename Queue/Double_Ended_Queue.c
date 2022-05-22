// DeQue Operations Using Array
#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
int deQueue[SIZE];
int front = -1;
int rear = -1;
// Insert from Front End Function
void insert_front()
{
    int data;
    printf("\nEnter a Data:- ");
    scanf("%d", &data);
    // check whether DeQue is full or not
    if ((rear == SIZE - 1 && front == 0) || (front == rear + 1))
    {
        printf("\nDeQue is Full!!!\n");
    }
    else if (rear == -1 && front == -1)
    {
        rear = 0;
        front = 0;
        deQueue[front] = data;
    }
    else if (front==0)
    {
        front = SIZE-1;
        deQueue[front] = data;
    }
    else
    {
        front--;
        deQueue[front] = data;
    }
}


// Insert from Rear End Function
void insert_rear(){
    int data;
    printf("\nEnter a Data:- ");
    scanf("%d", &data);
    // Checking whether Deque is full or not.
    if((rear == SIZE-1 && front==0 ) || front == rear+1){
        printf("Deque is Full!!!");
    }else if(front==-1&&rear==-1){
        rear=0;
        front=0;
        deQueue[rear]=data;
    }else if(rear == SIZE-1){
        rear=0;
        deQueue[rear] = data;
    }else{
        rear++;
        deQueue[rear]=data;
    }
}

// Delete from Front End Function
void delete_front()
{
    int data;
    // check whether DeQue is empty or not
    if (rear == -1 && front == -1)
    {
        printf("\nDeque is Empty!!!\n");
    }
    else if (front == rear)
    {
        data = deQueue[front];
        printf("\nDelete data:- %d\n", data);
        rear = front = -1;
    }
    else if (front == SIZE - 1)
    {
        data = deQueue[front];
        printf("\nDelete data:- %d\n", data);
        front = 0;
    }
    else
    {
        data = deQueue[front];
        printf("\nDelete data:- %d\n", data);
        front++;
    }
}


// Delete from Rear End Function
void delete_rear(){
    int data;
    if(front==-1 && rear==-1){
        printf("\nDeque is Empty!!!");
    }else if(front == rear){
        data = deQueue[rear];
        printf("\nDeleted Data :- %d\n",data);
        front = rear = -1;
    }else if(rear==0){
        data = deQueue[rear];
        printf("\nDeleted Data :- %d\n",data);
        rear = SIZE-1;
    }else{
        data = deQueue[rear];
        printf("\nDeleted Data :- %d\n",data);
        rear--;
    }
}
// Traverse Function
void display()
{
    int i, j;
    if (front == -1 && rear == -1)
    {
        printf("\nDeQue is empty!!!\n");
    }
    else if (rear >= front)
    {
        printf("\nElements:- ");
        for (i = front; i <= rear; i++)
        {
            printf("%d  ", deQueue[i]);
        }
        printf("\n");
    }
    else
    {
        printf("\nElements:- ");
        for (j = front; j <= SIZE - 1; j++)
        {
            printf("%d  ", deQueue[j]);
        }
        for (i = 0; i <= rear; i++)
        {
            printf("%d  ", deQueue[i]);
        }
        printf("\n");
    }
}

int main()
{
    int ch;
    while (1)
    {
        printf("\nDeQue Operations:-");
        printf("\n1. Insert From Front\n2. Insert From Rear\n3. Delete From Front\n4. Delete From Rear\n5. Display\n6. Exit");
        printf("\nEnter your choice:- ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert_front();
            break;
        case 2:
            insert_rear();
            break;
        case 3:
            delete_front();
            break;
        case 4:
            delete_rear();
            break;
        case 5:
            display();
            break;
        case 6:
            exit(1);

        default:
            printf("\nWrong Choice");
            break;
        }
    }
    return 0;
}