/*
Implement a fixed size Queue - clone
Tags:	Data StructuresQueue
Given a 'struct Queue', implement a fixed size queue. 
Write a function: 
          struct Queue * solution(int A[], int N) 
that accept an array of integers A representing a sequence of operations to be performed on queue along with values to pushed to queue and size of an array. The function should perform the given operations on the queue and return a pointer to queue.
The array element contains operation codes and values to be inserted in the queue.
Enqueue (code 1): Push the next value in an array into the queue. If a queue is full, print "queue is full" on a new line. 
Dequeue (code 2): Remove an element from the queue. If a queue is empty, print "queue is empty" on a new line. 
Exit (code 3): Return pointer to Queue.
Input
    8
    1 10 1 20 1 30 2 3 
    where,
First line represents the size of an array.
Second line represents an array elements.
Output
    20 30
Assume that, 
The queue is initially empty. 
The maximum size of the queue is 10. 
Value in the queue can be in the range from [-2,147,483,648 to 2,147,483,647].
*/

#include<stdio.h>
int enqueue(int *queue,int front,int rear,int elem)       // Enqueue operation pushing element inside queue
{
    if(rear == 10)                                       // If queue is full print its full
    {
        printf("queue is full\n");
        return rear;
    }
    if(front == -1 && rear == -1)                      // If its empty then initialise front and rear to -1
    {
        front = 0;
        rear = 0;
        queue[rear] = elem;
    }
    else 
    {
        queue[rear] = elem;                         // Inserting element in queue
    }
    rear = rear + 1;                               // Incrementing rear
    return rear;
}

int dequeue(int *queue, int front, int rear) 
{
    if(front == -1 || front > rear)               // if front is equal to -1 then queue is empty
    {
        printf("queue is empty");
        return front;
    }
    else  
        front = front  + 1;                      // Deleting the element in queue
    return front;
}
int solution(int *A, int N)
{
    int front = -1;
    int rear = -1;
    int queue[10];
    int flag = 0;
    for(int i = 0; i<N; i++)
    {
        if(A[i] == 1) 
        {
            flag = flag + 1;
            int x = A[i+1];
            rear = enqueue(queue,front,rear,x);
            if(flag == 1) 
            {
                front = 0;
            }
        }
        if(A[i] == 2) 
        {
            if(front == rear) 
                printf("queue is empty\n");
            else 
                front = dequeue(queue,front,rear);
        }
        
        if(A[i] == 3) 
        {
            if(front == -1 || front >= rear) 
            {
                printf("queue is empty");
            }
            else{
                for(int l = front; l <rear; l++)
                {
                    if(front == -1) 
                    {
                        printf("queue is empty\n");
                    }
                    printf("%d ",queue[l]);
                }
            }
        }
    }
    return 0;
}

//Your program will be evaluated by this main method and several test cases.
int main()
{
    int *A,N,i;
    scanf("%d",&N);
    A = malloc(sizeof(int)*N);
    for(i=0;i<N;i++)
    {
        scanf("%d",&A[i]);
    }
    solution(A,N);
    free(A);
}