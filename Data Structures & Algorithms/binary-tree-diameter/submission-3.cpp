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
    int d = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root, d);
        return d;
        
    }

    int dfs(TreeNode *root, int &d){
        if(root == nullptr){
            return 0;
        }
        d = max(d, dfs(root->left, d) + dfs(root->right, d));

        return 1 + max(dfs(root->left, d), dfs(root->right, d));
    }

};
