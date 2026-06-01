/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mapp; 
        mapp[nullptr] = nullptr; 
        Node* cur = head; 

        while(cur != nullptr){
            if( mapp.find(cur) == mapp.end()){
                mapp[cur] = new Node(0);
            }
            mapp[cur]->val = cur->val;
            if(mapp.find(cur->next) == mapp.end()){
                mapp[cur->next] = new Node(0);
            }
            mapp[cur]->next = mapp[cur->next];
            if(mapp.find(cur->random) == mapp.end()){
                mapp[cur->random] = new Node(0);
            }
            mapp[cur]->random = mapp[cur->random];
            cur = cur->next;
        }
        return mapp[head];
        
    }
};
