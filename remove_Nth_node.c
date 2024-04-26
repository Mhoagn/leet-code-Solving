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

node removeNthFromEnd(node head, int n) {
    if(head == NULL || n <= 0) return NULL;
    node dummy = makeNode(0);
    dummy->next = head;
    node fast = dummy;
    node slow = dummy;
    for(int i = 0; i < n; i++){
        if(fast == NULL) return head;
        fast = fast->next;
    }
    while(fast->next != NULL){
        fast = fast->next;
        slow = slow->next;
    }
    node toDelete = slow->next;
    slow->next = toDelete->next;
    free(toDelete);
    return dummy->next;    
}
