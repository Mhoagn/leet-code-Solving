/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
     if (head == NULL || head->next == NULL) return head;

    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->val = 0;
    dummy->next = head;

    struct ListNode* prev = dummy;
    struct ListNode* curr = head;

    while(curr != NULL && curr->next != NULL){
        if(curr->val != curr->next->val){
            prev = curr;
        }
        else{
            while(curr->next != NULL && curr->val == curr->next->val){
                curr = curr->next;
            }
            prev ->next = curr->next;
        }
        curr = curr->next;
        
    }
    return dummy->next;
}
