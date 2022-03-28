#include<stdio.h>

int ring_buffer[5], rear=-1, front=-1;

void Enqueue(int n){
    if (front == rear + 1 || front == rear + 4)
        printf("\nRing buffer overflow\n");
    else{
        if (rear == -1 && front == -1){
            rear++;
            front++;
            ring_buffer[rear] = n;
        }
        else if (rear == 4){
            rear = 0;
            ring_buffer[rear] = n;
        }
        else{
            rear++;
            ring_buffer[rear] = n;
        }
    }
}

void Dequeue(){
    if (front == 4)
        front = 0;
    else
        front++;
}

void print_queue(){
    int k = 0;
    printf("\n");
    for (int i=front; i!=rear; i++){
        k++;
        printf("Ring buffer[%d] = [%d]\n", k, ring_buffer[i]);
        if (i == 4)
            i = 0;
        if (i == rear){
            printf("Ring buffer[%d] = [%d]\n", ++k, ring_buffer[i]);
            break;
        }
    }
}


int main(){
    Enqueue(10);
    print_queue();

    Enqueue(50);
    print_queue();
    
    Enqueue(20);
    print_queue();
    
    Enqueue(70);
    print_queue();
    
    Dequeue();
    print_queue();
    
    Enqueue(100);
    print_queue();
    
    Enqueue(40);
    print_queue();

    Enqueue(140);

    Dequeue();
    print_queue();

    Dequeue();
    print_queue();

    Dequeue();
    print_queue();
}
