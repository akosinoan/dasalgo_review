/* by Noel Angelo Babao 

    This program implements how different data structures work using linked list

    argv[] = integers only;

    -Stack push pop
    
    TO DO:
    -Queue enqueue dequeue

    -UI let user choose which data structure to use;

*/
#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int number;
    struct Node *next;
} Node;

typedef struct Stack{
    Node *head;
} Stack;

Node *createNode(int number);
Stack *createStack();
void push ( Stack *stack, int number );
int pop (Stack *stack);
void printStack (Stack *stack);
void clearStack (Stack *stack);



int main(int argc, char *argv[]){
    if( argc< 2){
        printf("No input\n");
        return 1;
    }
    Stack *stack = createStack();
        
    for(int i=1; i<argc;i++){
        push(stack,atoi(argv[i]));
    }
    printStack(stack);
    clearStack(stack);
    printStack(stack);

    
}

Node *createNode(int number){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->number = number;
    newNode->next = NULL;
    return newNode;
}

Stack *createStack(){
    Stack* newStack = (Stack *)malloc(sizeof(Stack));
    newStack->head = NULL;
    return newStack;
}

void push (Stack *stack, int number){
    Node *newNode = createNode(number);
    newNode->next = stack->head;
    stack->head = newNode;
    printf("%i pushed in stack.\n", stack->head->number);
}

int pop (Stack *stack){
    
    if(stack->head==NULL){
        printf("****************STACK IS EMPTY POPPING 0*************\n");
        return 0;
    }
    Node *ptr = stack->head;
    
    int temp = stack->head->number;
    stack->head = stack->head->next;
    free(ptr);

    return temp;
}

void printStack ( Stack *stack ){
    Node *ptr = stack->head;
    printf("Printing Stack Values : [ ");
    while( ptr!=NULL){
        printf("%i ",ptr->number);
        ptr=ptr->next;    
    }
    printf("]\n");
}

void clearStack (Stack *stack){
    printf("Clearing Stack...\n");
    while( stack->head!=NULL ){
        Node *temp = stack->head->next;
        printf("%i popped out of stack.\n",pop(stack));
        stack->head= temp;
    }
}
