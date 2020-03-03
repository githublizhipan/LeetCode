/*************************************************************************
	> File Name: 83.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月26日 星期三 13时41分11秒
 ************************************************************************/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteDuplicates(struct ListNode* head){
    if(head == NULL || head->next == NULL) return head;
    struct ListNode *p = head, *q;
    int t = p->val;
    while(p->next) {
        if(!(p->next->val - t)) {
            q = p->next;
            p->next = q->next;
            free(q);
        } else {
            p = p->next;
            t = p->val;
        }
    }
    return head;
}
