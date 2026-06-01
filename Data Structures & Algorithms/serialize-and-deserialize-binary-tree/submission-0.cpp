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

class Codec {
public:
    int i = 0;
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root){
            return "N,";
        }
        
        string s = to_string(root->val);
        s += ",";
        
        s += serialize(root->left);
        s += serialize(root->right);
        return s;
    }

    // Decodes your encoded data to tree.
    
    TreeNode* deserialize(string data){
        return dfs(data, i);
    }
    TreeNode* dfs(string data, int &i){
        if( data[i] == 'N'){
            i+=2;
            return nullptr;
        }
        string token = ""; 
        while( i < data.size() && data[i] != ','){
            token += data[i];
            i++;
        }
        i++;
        if(token.empty()){
            return nullptr;
        }
        TreeNode* root = new TreeNode(stoi(token));
        root->left = dfs(data, i);
        root->right = dfs(data, i);
        return root;
    }
};
