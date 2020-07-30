/*************************************************************************
	> File Name: 21.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月26日 星期三 13时14分09秒
 ************************************************************************/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *p = l1, *q = l2;
    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
    head->next = NULL;
    struct ListNode *r = head;
    while(p && q) {
        if(p->val < q->val) {
            struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
            node->val = p->val;
            node->next = NULL;
            r->next = node;
            r = node;
            p = p->next;
        } else {
            struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
            node->val = q->val;
            node->next = NULL;
            r->next = node;
            r = node;
            q = q->next;
        }
    }
    while(p) {
        struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
        node->val = p->val;
        node->next = NULL;
        r->next = node;
        r = node;
        p = p->next;
    }
    while(q) {
        struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
        node->val = q->val;
        node->next = NULL;
        r->next = node;
        r = node;
        q = q->next;
    }
    return head->next;
}
