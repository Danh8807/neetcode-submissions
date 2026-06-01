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
        bool isBalanced = 1;
        dfs(root, isBalanced);
        return isBalanced;


    }

    int dfs(TreeNode* root, bool &isBalanced){
        if( root == nullptr){
            return 0;
        }

        if(abs(dfs(root->left, isBalanced) - dfs(root->right, isBalanced)) > 1){
            isBalanced = 0;
        }

        return 1 + max(dfs(root->left, isBalanced), dfs(root->right, isBalanced));
    }
    
};
