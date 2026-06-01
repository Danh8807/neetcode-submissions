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
        if( !root){
            return 0;
        }

        int maxLeft = dfs(root->left, res);
        int maxRight = dfs(root->right, res);
        maxLeft = max(maxLeft, 0);
        maxRight = max(maxRight, 0);

        res = max(res, root->val + maxLeft + maxRight);

        return root->val + max(maxLeft, maxRight);
    }
};
