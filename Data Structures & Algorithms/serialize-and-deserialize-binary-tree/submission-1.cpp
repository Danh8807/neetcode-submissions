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
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root){
            return "N,";
        }
        string s;
        s += to_string(root->val);
        s += ",";

        s+= serialize(root->left);
        s+= serialize(root->right);

        return s;
    }

    // Decodes your encoded data to tree.
    int i = 0;
    TreeNode* deserialize(string data){
        return dfs(data, i);
        
    }

    TreeNode* dfs(string data, int &i){
        if(data[i] == 'N'){
            i+=2;
            return nullptr;
        }
        TreeNode* root = new TreeNode;

        string val; 
        while( i < data.size() && data[i] != ','){
            val += data[i];
            i++;
        }
        i++;
        if(val.empty()){
            return nullptr;
        }
        root->val = stoi(val);
        root->left = dfs(data, i);
        root->right = dfs(data, i);

        return root;
    }
   
};
