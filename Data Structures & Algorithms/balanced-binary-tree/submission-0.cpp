/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        bool isBalanced = true;
        dfs(root, isBalanced); 
        return isBalanced;
    }

    int dfs(TreeNode* cur, bool &isBalanced){
        if( !cur){
            return 0;
        }
        if(abs(dfs(cur->left, isBalanced) - dfs(cur->right, isBalanced)) > 1){
            isBalanced = false;
        }
        return 1 + max(dfs(cur->left, isBalanced), dfs(cur->right, isBalanced));
    }   
    
};
