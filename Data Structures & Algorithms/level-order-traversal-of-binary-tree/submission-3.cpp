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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res; 
        queue<TreeNode*> q;
        if(root == nullptr){
            return res;
        }
        q.push(root);
        while(!q.empty()){
            vector<int> subset;
            int size = q.size();
            for(int i = 0; i < size; i++){
                TreeNode* tmp = q.front();
                q.pop();
                if( tmp != nullptr){
                    if (tmp->left) q.push(tmp->left);
                    if (tmp->right) q.push(tmp->right);
                    subset.push_back(tmp->val);
                }
            }
            if(!subset.empty()){
                res.push_back(subset);
            }
        }

        return res;

    }

    

    
    
};
