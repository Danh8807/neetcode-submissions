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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty() && inorder.empty()){
            return nullptr;
        }
        TreeNode* root = new TreeNode;
        root->val = preorder[0];
        vector<int> pre_left_branch;
        vector<int> pre_right_branch;
        vector<int> in_left_branch;
        vector<int> in_right_branch;

        int count_left = 0;
        
        while(inorder[count_left] != preorder[0]){
            in_left_branch.push_back(inorder[count_left]);
            count_left++;
        }
           
        for( int i = count_left+1; i < inorder.size(); i++){
            in_right_branch.push_back(inorder[i]);
        }
        
        
        for(int i = 1; i < preorder.size(); i++){
            if( i <= count_left){
                    pre_left_branch.push_back(preorder[i]);
            }
            else{
                pre_right_branch.push_back(preorder[i]); 
            }
        }

        root->left = buildTree(pre_left_branch,in_left_branch);
        root->right = buildTree(pre_right_branch, in_right_branch);
        return root;
    }
};
