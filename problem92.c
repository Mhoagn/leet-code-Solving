/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    if(head == NULL || head->next == NULL) return head;
    struct ListNode* prev = NULL;
    struct ListNode* current = head;
    
    while(left > 1){
        prev = current;
        current = current->next;
        left--;
        right--;
    }

    struct ListNode* connection = prev;
    struct ListNode* tail = current;

    while(right > 0){
        struct ListNode* next_node = current->next;
        current->next = prev;
        prev = current;
        current = next_node;
        right--;
    }
    if(connection != NULL){
        connection->next = prev;
    }
    else head = prev;

    tail->next = current;
    return head;
}
