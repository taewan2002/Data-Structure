#include<stdio.h>

int queue[10] = {0}, front = -1, rear = -1;

void enqueue(int a){
    if (front == -1)
        front++;
    rear++;
    queue[rear] = a;
}

void dequeue(){
    queue[front] = 0;
    front++;
}

void queue_full(){
    if(rear != 9)
        printf("\n[queue is not full]\n");
    else
        printf("\n[queue is full]\n");
}

void queue_empty(){
    for(int i=0; i<10; i++) 
        queue[i] = 0;
    rear = -1;
    front = -1;
}

void print_queue(){
    printf("\n");
    if (rear == -1)
        printf("queue is empty\n");
    else{
        int end = rear;
        for(int start = front; start<=end; start++)
            printf("queue%d = %d\n", start - front + 1, queue[start]);
    }
}

int main(){
    // enqueue five integer and dequeue two ineteger
    enqueue(100);
    enqueue(200);
    enqueue(300);
    enqueue(400);
    enqueue(500);
    dequeue();
    dequeue();
    print_queue();
    queue_full();

    // enqueue into last queue
    enqueue(100);
    enqueue(200);
    enqueue(300);
    enqueue(400);
    enqueue(500);
    print_queue();
    queue_full();

    // empty queue
    queue_empty();
    print_queue();
}
