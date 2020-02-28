/*************************************************************************
	> File Name: 142.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月28日 星期五 09时42分31秒
 ************************************************************************/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    if(head == NULL) return NULL;
    struct ListNode *p = head, *q = head;
    do {
        if(p->next == NULL) return NULL;
        p = p->next;
        if(q->next && q->next->next) q = q->next->next;
        else return NULL;
    } while(p != q);
    q = head;
    while(p != q) {
        p = p->next;
        q = q->next;
    }
    return p;
}
