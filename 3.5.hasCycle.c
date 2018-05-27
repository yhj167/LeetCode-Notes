/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/*是否有环*/
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

/*
环的起点，思路：
环的起点-链表起点=a
相遇时：
fast-环的起点=b
slow走的距离=a+b，fast走的距离=2(a+b)
环长度为n，fast走了k圈，fast走的距离=a+b+kn,则a+b=kn
slow拉倒链表起点，再走一圈到再相遇，a=n-b，到达环的起点

环的长度：fast再走一圈，和slow相遇，即环长度
*/
struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode *slow=head, *fast=head;
    if(!head || !head->next)
        return NULL;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow){
            slow = head;
            while(fast!=slow){
                slow=slow->next;
                fast=fast->next;
            }
            return slow;
        }
    }
    return NULL;
}
/*环的长度*/
int ListNode *detectCycle(struct ListNode *head) {
    int len=0;
    struct ListNode *slow=head, *fast=head;
    if(!head || !head->next)
        return -1;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow){
            while(fast!=slow){
                fast=fast->next;
                len++;
            }
            return len;
        }
    }
    return -1;
}
