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
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        dfs(root, res);
        return res;
    }

    int dfs(TreeNode* root, int &res){
        if(!root){
            return 0;
        }

        int max_left = dfs(root->left, res);
        int max_right = dfs(root->right, res);
        max_left = max(max_left, 0);
        max_right = max(max_right, 0);

        res = max(res, max_left + max_right + root->val);
        
        return root->val + max(max_left, max_right);
    }


    
};
