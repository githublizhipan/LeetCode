/*************************************************************************
	> File Name: LeetCode235.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月29日 星期六 19时35分29秒
 ************************************************************************/
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if(root == NULL) return NULL;
    if(p->val > root->val && q->val > root->val) {
        return lowestCommonAncestor(root->right, p, q);
    } else if(p->val < root->val && q->val < root->val) {
        return lowestCommonAncestor(root->left, p, q);
    } else return root;
}
