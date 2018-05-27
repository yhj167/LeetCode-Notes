/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    if(head == NULL)return NULL;
    if(head->next == NULL){
        return head;
    }
    struct ListNode *newH = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return newH;
}

bool isPalindrome(struct ListNode* head) {
    struct ListNode *slow=head, *fast=head;
    if(!head || !head->next)
        return true;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    if(fast){
        //奇
        slow = slow->next;
        slow = reverseList(slow);
    }
    else{
        slow = reverseList(slow);
    }
    while(slow){
        if(head->val != slow->val)
            return false;
        head = head->next;
        slow = slow->next;
    }
    return true;
}
