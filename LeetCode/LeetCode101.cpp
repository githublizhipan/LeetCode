/*************************************************************************
	> File Name: 101.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月26日 星期三 14时02分57秒
 ************************************************************************/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool isSymmetric(struct TreeNode* root){
    if(root == NULL) return true;
    if(root == NULL) return true;
    if(!root->left &&  !root->right) return true;
    if((!root->left && root->right ) || (root->left && !root->right)) return false;
    if(root->left->val != root->right->val) return false;
    return isSymmetric(root->left->left) && isSymmetric(root->right->right) && isSymmetric(root->left->right) && isSymmetric(root->right->left);
}
