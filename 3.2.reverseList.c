/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdio.h>
void nodeprint(struct ListNode* head) {
    while(head!=NULL){
        printf("%d ",head->val);
        head=head->next;
    }
    printf("\n");
}

/*struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *p=NULL, *q=NULL;
    if(head == NULL)return NULL;
    if(head->next == NULL)return head;
    p = head->next;
    while(p->next != NULL){
        q = p->next;
        p->next = q->next;
        q->next = head->next;
        head->next = q;
    }
    p->next = head;
    head = p->next->next;
    p->next->next = NULL;
    return head;
}
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *p=NULL, *q=NULL, *r=NULL;
    if(head == NULL)return NULL;
    if(head->next == NULL)return head;
    p=head;
    q = head->next;
    head->next = NULL;
    while(q != NULL){
        r = q->next;
        q->next = p;
        p = q;
        q = r;
    }
    head = p;
    return head;
}
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

int main(){
    struct ListNode *n1 = malloc(sizeof(struct ListNode));
    struct ListNode *n2 = malloc(sizeof(struct ListNode));
    struct ListNode *n3 = malloc(sizeof(struct ListNode));
    n1->val=1;
    n2->val=2;
    n3->val=3;
    n1->next = n2;
    n2->next = n3;
    n3->next = NULL;
    struct ListNode *H = n1;
    
    nodeprint(H);
    H = reverseList(H);
    nodeprint(H);
    
    return 0;
}
