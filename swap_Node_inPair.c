struct Node{
    int data;
    struct Node* next;
};

typedef struct Node* node;

node makeNode(int value){
    node newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertLast(node *head, int value){
    node newNode = makeNode(value);
    if((*head) == NULL) (*head) = NULL;
    else {
        node tmp = *head;
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = newNode;
    }
}

void swap(int *a, int *b){
    int temp = (*a);
    (*a) = (*b);
    (*b) = temp; 
}

node swapPairs(node head) {
    if(head == NULL) return head;
    node current = head;
    while (current != NULL && current->next != NULL) {
        swap(&current->data, &current->next->data);
        current = current->next->next;
    }
    return head;
}
