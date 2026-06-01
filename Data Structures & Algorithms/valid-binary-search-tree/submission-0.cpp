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
    bool isValidBST(TreeNode* root) {
        int upperbound = INT_MAX;
        int lowerbound = INT_MIN;
        return dfs(root, upperbound, lowerbound);
    }
    bool dfs(TreeNode* root, int upperbound, int lowerbound){
        if(!root){
            return true;
        }
        else if(root->val >= upperbound || root->val <= lowerbound){
            return false;
        }
        else{
            return dfs(root->left, root->val, lowerbound) && dfs(root->right, upperbound, root->val);
        }
    }
};
