#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 15

struct Stack {
	int key;
	struct Stack* next;
};

struct Stack* top = NULL;
struct Stack* head = NULL;

int n_nodes = 0;

int stack_full() {
    /* chaek the stack is full */
    if(n_nodes >= MAX_SIZE)
        return 1;
    return 0;
}

int stack_empty() {
    /* empty the stack */
    if(n_nodes == 0)
        return 1;
    return 0;
}

void push(int n){
    struct Stack* tmp =  (struct Stack*)malloc(sizeof(struct Stack));
     // test if memory allocation failed
    if(tmp == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    tmp->key = n;
    tmp->next = NULL; // tmp will be added at the tail of the linked list
    if (top == NULL){
        head = top = tmp;
    }
    top->next = tmp;
    top = tmp;
    n_nodes += 1;
}

void pop(){
    /* head->next->next ... pop there is last node */
    struct Stack* tmp = head;
    struct Stack* pnode;
    while(tmp->next != NULL){
        pnode = tmp;
        tmp = tmp->next;
    }
    printf("%d", tmp->key);
    pnode->next = NULL;
    free(tmp);
}

int main(){
    int num;
    for(int i=0; i<5; i++){
        n_nodes = 0;
        top = NULL;
        head = NULL;
        printf("Enter the number: ");
        scanf("%d", &num);
        while (num != 0){
            /* push 0 */
            if (num % 2 == 0){
                push(0);
            }
            /* push 1 */
            else{
                push(1);
            }
            num /= 2;
        }
        for(int i=0; i<n_nodes; i++)
            pop();
        printf("\n");
    }
}
