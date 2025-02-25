typedef struct Queue{
    Node *front, *end;
} Queue;

Queue *createQueue(){
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->front = queue->end = NULL;
    return queue;
}

void enqueue (Queue *queue, int number){
    Node *newNode = createNode(number);

    if (queue->end == NULL || queue->front == NULL){
        queue->front = newNode;
    
    }else{
        queue->end->next = newNode;
    }
    queue->end = newNode;
    printf("%i added to queue. \n",queue->end->number);
}

int dequeue ( Queue *queue ){
    if(queue->front == NULL){
        printf("****************queue is empty! dequeuing 0**************\n");
        return 0;
    }

    int temp = queue->front->number;
    
    if(queue->front->next==NULL){
        queue->end = NULL;
    }
    Node *ptr = queue->front->next;
    free(queue->front);
    queue->front = ptr;
    return temp;
}

void printQueue( Queue *queue){
    Node *ptr = queue->front;
    printf("Printing Queue Values : [ ");
    while( ptr!=NULL){
        printf("%i ",ptr->number);
        ptr=ptr->next;    
    }
    printf("]\n");
}
void clearQueue( Queue *queue){
    printf("Clearing Stack...\n");
    while( queue->front!=NULL ){
        Node *temp = queue->front->next;
        printf("%i popped out of queue.\n",dequeue(queue));
        queue->front= temp;
    }
}