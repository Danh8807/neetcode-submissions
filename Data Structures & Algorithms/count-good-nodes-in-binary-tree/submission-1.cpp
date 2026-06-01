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
    int goodNodes(TreeNode* root) {
        int res = 0;
        int maximum = root->val;
        dfs(root, res, maximum);
        return res;
    }
    int dfs(TreeNode* root, int &res, int maximum){
        if(!root){
            return 0;
        }
        maximum = max(maximum, root->val);
        if( root->val >= maximum){
            res++;
        }
        dfs(root->left, res, maximum);
        dfs(root->right,res, maximum);
        return 0;
    }
};
