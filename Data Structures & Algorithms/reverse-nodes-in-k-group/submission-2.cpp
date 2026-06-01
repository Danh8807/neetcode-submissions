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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;
        while(true){
            ListNode* kth = getKth(head,k);
            if( kth == nullptr){
                break;
            }
            ListNode* next_head = kth->next;
            ListNode* p = nullptr;
            ListNode* tail = head; 
            for(int i = 0; i < k; i++){
                ListNode* temp = head->next;
                head->next = p;
                p = head;
                head = temp;  
            }
            prev->next = kth;
            prev = tail;
            tail->next = next_head; 
            

        }
        return dummy.next;
    }
    
    ListNode* getKth(ListNode* head, int k){
        for(int i = 0; i < k-1; i++){
            if(head == nullptr){
                return nullptr;
            }
            head = head->next;
        }
        return head;
    }
};
