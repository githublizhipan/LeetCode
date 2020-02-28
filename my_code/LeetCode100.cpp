/*************************************************************************
	> File Name: 100.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月26日 星期三 13时43分00秒
 ************************************************************************/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    if(!p && !q) return true;
    if(p && q && q->val == p->val) {
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    } else return false;
}
