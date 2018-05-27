/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    struct ListNode *slow=head, *fast=head;
    if(!head || !head->next)
        return false;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow)
            return true;
    }
    return false;
}
