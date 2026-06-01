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
        unordered_map<Node*, Node* > map; 
        Node* q = head; 
        Node dummy(0);
        Node* p = &dummy; 
        while(q){
            if(map.find(q) == map.end()){
                Node* newNode = new Node(q->val);
                p->next = newNode;
                map[q] = newNode;
            }
            else{
                p->next = map[q];
            }
            p = p->next;
            if(q->random == nullptr){
                p->random =nullptr;
            }
            else if(map.find(q->random) == map.end()){
                Node* newNode =new Node(q->random->val);
                p->random = newNode;
                map[q->random] = newNode;
            }
            else{
                p->random = map[q->random];
            }
            q = q->next;
        }
        return dummy.next; 
    }
};
