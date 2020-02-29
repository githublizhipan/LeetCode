/*************************************************************************
	> File Name: LeetCode226.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月29日 星期六 18时43分36秒
 ************************************************************************/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* invertTree(struct TreeNode* root){
    if(root == NULL) return NULL;
    if(root->left == NULL && root->right == NULL) return root;
    struct TreeNode *temp = root->left;
    root->left = root->right;
    root->right = temp;
    invertTree(root->left);
    invertTree(root->right);
    return root;
}
