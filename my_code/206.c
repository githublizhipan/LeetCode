/*************************************************************************
	> File Name: 206.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月27日 星期四 15时09分41秒
 ************************************************************************/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){
    if(head == NULL) return head;
    struct ListNode node, *p, *q;
    p = head;
    node.next = NULL;
    while(p) {
        q = p->next;
        p->next = node.next;
        node.next = p;
        p = q;
    }
    return node.next;
}
