typedef struct Node {
    int number;
    struct Node *next;
} Node;


Node *createNode(int number){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->number = number;
    newNode->next = NULL;
    return newNode;
}