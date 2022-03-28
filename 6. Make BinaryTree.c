#include<stdio.h>
#include<stdlib.h>
#define LEVEL 0
#define KEY 1
#define CHILD 2
#define MAX_SIZE 10
#define DATA_SIZE 3

struct Tree {
    int key;
    struct Tree* Left;
    struct Tree* Right;
};

struct Tree* tree;
struct Tree* head;

/* set datas */
int tree1_data[MAX_SIZE][DATA_SIZE] = {
   {1, 100, 200}, {2, 200, NULL}, {2, 75, 25},
   {2, 300, NULL}, {3, 25, NULL}, {3, 50, NULL},
   {3, 30, 120}, {3, 150, NULL}, {4, 120, NULL},
   {4, 55, NULL} };

int tree2_data[MAX_SIZE][DATA_SIZE] = {
   {1, 100, 200}, {2, 200, NULL}, {2, 75, 25},
   {2, 300, NULL}, {2, 95, 150}, {3, 25, NULL},
   {3, 50, NULL}, {3, 30, 120}, {3, 150, NULL},
   {4, 120, NULL} };

/* print data into preorder */
void print_preorder(struct Tree* ptr) {
    if (ptr) {
        printf("[Data is %d]\n", ptr->key);
        print_preorder(ptr->Left);
        print_preorder(ptr->Right);
    }
}

void btree(struct Tree* temp, int data[MAX_SIZE][DATA_SIZE], int n) {
    int level = data[n][LEVEL];
    int key = data[n][KEY];
    int child = data[n][CHILD];

    struct Tree* ptr = (struct Tree*)malloc(sizeof(struct Tree));
    ptr->key = key;
    ptr->Left = NULL;
    ptr->Right = NULL;

    /* Insert */
    if (temp == NULL) { // first node
        head = temp = ptr;
    }
    else {
        if (temp->Left == NULL) { // the first child node of the parent node
            temp->Left = ptr;
        }
        else { // Second or latter
            struct Tree* tmp = (struct Tree*)malloc(sizeof(struct Tree));
            struct Tree* ptmp = (struct Tree*)malloc(sizeof(struct Tree));
            ptmp = tmp = temp;
            while (tmp != NULL) {
                ptmp = tmp;
                tmp = tmp->Right;
            }
            ptmp->Right = ptr;
        }
    }

    /* Recursion */
    if (child == NULL) {
        return;
    }
    else {
        int sep = 0;
        int i;
        for (int i = n + 1; i < MAX_SIZE; i++) { // how far the child nodes are
            if (data[i][CHILD] != NULL) {
                sep = data[i][CHILD];
                break;
            }
        }
        for (i = n; i < MAX_SIZE; i++) {
            if (data[i][KEY] == child) { // Find the location of the child node
                break;
            }
        }
        for (i = i; i < MAX_SIZE; i++) {
            if (data[i][KEY] == sep) {
                break;
            }
            if (data[i][LEVEL] == level + 1) {
                btree(ptr, data, i);
            }
        }
    }
}

void make2_tree(int data[MAX_SIZE][DATA_SIZE]) {
    tree = NULL;
    head = NULL;
    btree(tree, data, 0);
}

int main() {
    make2_tree(tree1_data);
    print_preorder(head);
    /* clear data */
    free(head); 

    printf("\n");
    make2_tree(tree2_data);
    print_preorder(head);
    /* clear data */
    free(head);
}
