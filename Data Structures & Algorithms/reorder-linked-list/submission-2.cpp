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
    void reorderList(ListNode* head) {
        ListNode* fast = head; 
        ListNode* slow = head; 
        while( fast && fast->next){
            fast = fast->next->next;
            slow = slow->next; 
        }
        ListNode* l2 = slow->next;
        slow->next = nullptr;
        ListNode* prev = nullptr;
        ListNode* cur = l2; 
        while(cur){
            ListNode* temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }
        ListNode* l1 = head;
        while(l1 && prev){
            ListNode* temp1 = l1->next;
            ListNode* temp2 = prev->next;
            l1->next = prev;
            prev->next = temp1;
            l1 = temp1;
            prev = temp2;
        }
    }
};
