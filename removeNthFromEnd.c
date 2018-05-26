/*
给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

示例：

给定一个链表: 1->2->3->4->5, 和 n = 2.

当删除了倒数第二个节点后，链表变为 1->2->3->5.
说明：

给定的 n 保证是有效的。

进阶：

你能尝试使用一趟扫描实现吗？
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* slow, *dumppy;
    slow = malloc(sizeof(struct ListNode));
    slow->next = head;
    dumppy = slow;
    if(n<0)return NULL;
    while(n>=1){
        if(head == NULL)break;
        head= head->next;
        n--;
    }
    while(head != NULL){
        head = head->next;
        slow = slow->next;
    }
    slow->next = slow->next->next;
    return dumppy->next;
}
