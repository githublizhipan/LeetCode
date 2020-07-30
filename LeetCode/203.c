/*************************************************************************
	> File Name: 203.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月27日 星期四 15时03分49秒
 ************************************************************************/
 /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeElements(struct ListNode* head, int val){
    struct ListNode node;
    node.next = head;
    struct ListNode* p = &(node);
    while(p->next) {
        if(p->next->val == val) {
            struct ListNode* q = p->next;
            p->next = q->next;
            free(q);
        } else p = p->next;
    }
    return node.next;
}

