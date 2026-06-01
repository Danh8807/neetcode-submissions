/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()){
            return nullptr;
        }
        ListNode* res = lists[0]; 
        for(int i = 1; i < lists.size(); i++){
            res = merge2list(res, lists[i]);
        
        }
        return res;
    }
    ListNode* merge2list(ListNode* p1, ListNode* p2){
        if(p1 == nullptr){
            return p2;
        }
        if(p2 == nullptr){
            return p1;
        }
        ListNode dummy(0);
        ListNode* cur = &dummy;
        while(p1 && p2){
            if(p1->val < p2->val){
                cur->next = p1;
                p1 = p1->next;
            }
            else{
                cur->next = p2;
                p2 = p2->next;
            }
            cur = cur->next;
        }
        if(!p1){
            cur->next = p2;
        }
        if(!p2){
            cur->next = p1;
        }
        return dummy.next;
    }
};
