/*************************************************************************
	> File Name: 19.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月26日 星期三 12时39分17秒
 ************************************************************************/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode *p = head, *q = head;
    int cnt = 0, flag = 1;
    while(p->next) {
        p = p->next;
        cnt++;
        if(cnt >= n + 1) {
            q = q->next;
            flag = 0;
        }
    }
    if(flag) {
        head = head->next;
        return head;
    }
    struct ListNode* node = q->next;
    q->next = node->next;
    free(node);
    return head;
}
