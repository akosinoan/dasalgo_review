/* by Noel Angelo Babao 

    This program implements how different data structures work using linked list

    argv[] = integers only;

    -Stack push pop
    
    TO DO:
    -Queue enqueue dequeue

    -UI let user choose which data structure to use;

*/
#include <stdio.h>
#include <stdlib.h>
#include "Node.c"
#include "Stack.c"
#include "Queue.c"

void showMainMenu();
void showQueueMenu();
void showStackMenu();
void showInvalid();

int main(int argc, char *argv[]){
   
    // if( argc< 2){
    //     printf("No input\n");
    //     return 1;
    // }
    Stack *stack = createStack();
    Queue *queue = createQueue();
    int answer = 0;
    char *answerInChar;
    do{
        showMainMenu();
        scanf("%s" ,answerInChar);
        answer = atoi(answerInChar);
        if(!(answer > 0 && answer <4)){
            void showInvalid();
        }else if(answer !=3){
            if(answer == 1){ // chose STACK
                do{
                    showStackMenu();
                    scanf("%s" ,answerInChar);
                    answer = atoi(answerInChar);
                    
                    if(answer==5){
                        printf("\nBack to Main menu.....\n");
                        break;
                    }
                                        
                    if(!(answer > 0 && answer <6)){
                        showInvalid();
                    }else if(answer ==1){ // PUSH
                        printf("Enter number to be pushed: ");
                        int value;
                        scanf("%d",&value);
                        push(stack,value);
                    }else if(answer ==2){ // POP  
                        printf("%i Popped out. ", pop(stack));
                    }else if(answer ==3){ // Clear Stack
                        clearStack(stack);
                    }else if(answer ==4){ // Show Stack
                        printf("Show Stack\n");
                    }
                    printStack(stack);
                }while (answer != 5);
                
            }else if(answer ==2){ // Chose Queue
                do{
                    showQueueMenu();
                    scanf("%s" ,answerInChar);
                    answer = atoi(answerInChar);
                    
                    if(answer==5){
                        printf("\nBack to Main menu.....\n");
                        break;
                    }
                                        
                    if(!(answer > 0 && answer <6)){
                        showInvalid();
                    }else if(answer ==1){ // enqueue
                        printf("Enter number to be enqueued: ");
                        int value;
                        scanf("%d",&value);
                        enqueue(queue,value);
                    }else if(answer ==2){ // dequeue  
                        printf("\n%i dequeued out. ", dequeue(queue));
                    }else if(answer ==3){ // Clear Queue
                        clearQueue(queue);
                    }else if(answer ==4){ // Show Queue.
                        printf("Show Queue\n");
                    }
                    printQueue(queue);
                }while (answer != 5);
            }
        }
    }while (answer != 3);



    // for(int i=1; i<argc;i++){
    //     enqueue(queue,atoi(argv[i]));
    // }

    // printQueue(queue);
    // clearQueue(queue);
    // printQueue(queue);

    // for(int i=1; i<argc;i++){
    //     push(stack,atoi(argv[i]));
    // }
    // printStack(stack);
    // clearStack(stack);
    // printStack(stack);
}


void showQueueMenu(){
    printf("\n******Queue Menu*****\n");
    printf("Pick one.\n");
    printf("1. Enqueue\n2. Dequeue\n3. Clear Queue\n4. Show Queue\n5. Back to Main Menu\n : ");
}

void showStackMenu(){
    printf("\n******Stack Menu*****\n");
    printf("Pick one.\n");
    printf("1. Push\n2. Pop\n3. Clear Stack\n4. Show Stack\n5. Back to Main Menu\n : ");
}


void showMainMenu(){
    printf("\n******Main Menu*****\n");
    printf("Pick one.\n");
    printf("1. Stack\n2. Queue\n3. Exit\n : ");
}
void showInvalid(){printf("\nInvalid Input. Try Again.\n");}





