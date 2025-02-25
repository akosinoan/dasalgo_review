typedef struct Stack{
    Node *head;
} Stack;

Stack *createStack(){
    Stack* newStack = (Stack *)malloc(sizeof(Stack));
    newStack->head = NULL;
    return newStack;
}

void push (Stack *stack, int number){
    Node *newNode = createNode(number);
    newNode->next = stack->head;
    stack->head = newNode;
    printf("\n%i pushed in stack.\n", stack->head->number);
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