// Link-> https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/submissions/

#include <vector>
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
    
    
    void dfs(TreeNode* root, int &x, vector<int> &path_from_root, bool &found){
      if (!found){
        path_from_root.push_back(root->val);
        if (root->val == x){
           found = true;
           return; 
        }
        if (root->left != NULL){
            dfs(root->left,x,path_from_root,found);
        }
        if (root->right != NULL){
            dfs(root->right,x,path_from_root,found);
        }
          
      if (!found){    
      path_from_root.pop_back();   
      }
          
      }    
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       vector<int> path_root_p;
       vector<int> path_root_q;
       TreeNode* t = root;
       int p_val = p->val;
       int q_val = q->val;
       bool found = false;
       dfs(root,p_val,path_root_p,found); 
       found = false;
       dfs(root,q_val,path_root_q,found);
       int ancestorVal = 0;
       vector<int> min_path;
       int minSize = 0;
       vector<int> max_path;
       int maxSize = 0;
    
       if (path_root_p.size() < path_root_q.size()){
           minSize = path_root_p.size();
           maxSize = path_root_q.size();
           for (int i=0; i<minSize; i++){
               min_path.push_back(path_root_p[i]);
           }
           for (int i=0; i<maxSize; i++){
               max_path.push_back(path_root_q[i]);
           }
       }
       else{
           minSize = path_root_q.size();
           maxSize = path_root_p.size();
           for (int i=0; i<minSize; i++){
               min_path.push_back(path_root_q[i]);
           }   
            for (int i=0; i<maxSize; i++){
               max_path.push_back(path_root_p[i]);
           }   
       }
        
         
       for (int i=0; i<minSize; i++){
           if ((i==minSize-1 && min_path[i] == max_path[i])  ||  (min_path[i]==max_path[i] &&       min_path[i+1] != max_path[i+1]) ){
            break;
           }
           else {
               
               if ((t->left!=NULL) && min_path[i+1] == (t->left)->val){
                   t = t->left;
                   
               }
               else{
                   t = t->right;
               }
           }
       }
     return t;  
    }
};