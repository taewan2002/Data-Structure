#include<stdio.h>

int stack[10] = {0}, top = -1;

void push(int a){
    top++;
    stack[top] = a;
}

void pop(){
    stack[top] = 0;
    top--;
}

void stack_full(){
    if(top != 9)
        printf("\n[stack is not full]\n");
    else
        printf("\n[stack is full]\n");
}

void stack_empty(){
    for(int i=0; i<10; i++) 
        stack[i] = 0;
    top = -1;
}

void print_stack(){
    printf("\n");
    if (top == -1)
        printf("stack is empty\n");
    else{
        int end = top;
        for(int i=0; i<=end; i++)
            printf("stack%d = %d\n", i+1, stack[i]);
    }
}

int main(){
    // push five integer and pop two ineteger
    push(100);
    push(200);
    push(300);
    push(400);
    push(500);
    pop();
    pop();
    print_stack();
    stack_full();

    // push into last stack
    push(100);
    push(200);
    push(300);
    push(400);
    push(500);
    push(600);
    push(700);
    print_stack();
    stack_full();

    // empty stack
    stack_empty();
    print_stack();
}
