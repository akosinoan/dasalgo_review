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

typedef struct node {
    int number;
    struct node *next;
} node;

node* push( node *head, int number);// add a node on top of stack; 
int pop(node *head);                // remove topmost node; return node; 
void printStack(node *head);        //print the whole stack.
node *clearStack(node *head);
int main(int argc, char *argv[]){
    if( argc< 2){
        printf("No input\n");
        return 1;
    }
    node* stackHead = NULL;
    
    for(int i=1; i<argc;i++){
        stackHead = push(stackHead,atoi(argv[i]));
    }
    printStack(stackHead);
    stackHead = clearStack(stackHead);
    printStack(stackHead);
    stackHead = push(stackHead,4);
    printStack(stackHead);
}

node *push( node *head, int number){
    
    node *temp = malloc(sizeof(node));
    temp->number = number;
    temp->next = head;

    head = temp;
    printf("%i pushed in stack.\n", head->number);
    return head;
} 

int pop(node *head){
  
    int temp = head->number;
    node *ptr = head;
    head=head->next;
    free(ptr);
    return temp;
}

void printStack(node *head){
    
    node *ptr = head;
    printf("Printing Stack Values : [ ");
    while( ptr!=NULL){
        printf("%i ",ptr->number);
        ptr=ptr->next;    
    }
    printf("]\n");
}

node *clearStack(node *head){
    while( head!=NULL ){
        node *temp = head->next;
        printf("%i popped out of stack.\n",pop(head));
        head= temp;
    }
}