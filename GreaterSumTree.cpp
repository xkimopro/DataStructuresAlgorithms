//Link-> https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    void reverseInOrder(TreeNode* root, int& x){
        if (root->right!=NULL){
            reverseInOrder(root->right, x);
        }
        int temp = root->val;
        root->val += x;
        x += temp;
        if (root->left!=NULL){
            reverseInOrder(root->left,  x);
        }
    }
    
    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        reverseInOrder(root, sum );   
        return root;
    }
};