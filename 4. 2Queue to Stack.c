#include <stdio.h>
#define MAX_SIZE 10


/*  global variables  */
int queue1[MAX_SIZE], queue2[MAX_SIZE];
int front1 = -1, front2 = -1;
int rear1 = -1, rear2 = -1;

int queue_full() {
    if (rear1 >= MAX_SIZE - 1)
        return 1;
    return 0; // return 0 only if the above condition is false
}

int queue_empty() {
    if (front1 == -1 || front1 > rear1) // front cannot be greater than rear
        return 1;
    return 0; // return 0 only if the above condition is false
}

void enqueue1(int x) {
    rear1++;
    queue1[rear1] = x;
    if (front1 == 4-1) // increase front only initially
        front1++;
}

void enqueue2(int x) {
    rear2++;
    queue2[rear2] = x;
    if (front2 == -1) // increase front only initially
        front2++;
}

int dequeue1() {
    int temp = queue1[front1];
    front1++;
    return temp;
}

int dequeue2() {
    int temp = queue2[front2];
    front2++;
    return temp;
}

void print_queue1() {
    /*  helper function: print the current queue  */
    printf("stack = ");
    for (int i = front1; i <= rear1; i++){
            if (queue_empty()){
                break;
            }
        printf(" %d", queue1[i]);
    }
    printf(" (top=%d)\n", rear1);
}

void push(int num) {
    enqueue1(num);
}

int pop() {
    /*  datas queue1 -> queue2, pop last data in queue1 -> queue1  */
    front2 = -1;
    rear2 = -1;
    int f1 = front1, r1 = rear1;
    for (int i = f1; i < r1; i++) {
        enqueue2(dequeue1());
    }
    int temp = dequeue1();
    if (rear1 == 0){
        rear1 = -1;
        front1 = -1;
        return temp;
    }
        

    front1 = -1;
    rear1 = -1;
    int f2 = front2, r2 = rear2;
    for (int k = f2; k <= r2; k++) {
        enqueue1(dequeue2());
    }
    return temp;
}

void run_enqueues(int arr[], int num) {

    for (int i = 0; i < num; i++) {
        printf("push(%d) , ", arr[i]);
        if (!queue_full()) { // if queue is not full (!1 = 0)
            push(arr[i]);
        }
        else {
            printf("stack full! ");
        }
        print_queue1();
    }
}

void run_dequeues(int num) {
    int value;
    for (int i = 0; i < num; i++) {
        printf("pop() ");
        if (!queue_empty()) { // if queue is not empty (!1 = 0)
            value = pop();
           printf("-> %d , ", value);
        }
        else {
            printf("stack empty! ");
        }
        print_queue1();
    }
}

int main() {
    int numbers[] = { 3, 9, 4, 5, 2, 1, 6, 8, 7, 5, 8 };

    print_queue1();
    run_enqueues(numbers, 5);
    run_dequeues(3);
    run_enqueues(numbers, 10);
    run_dequeues(11);
    run_enqueues(numbers, 3);
}
