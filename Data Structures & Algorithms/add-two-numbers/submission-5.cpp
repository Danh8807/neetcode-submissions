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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* head = dummy;
        int carry = 0;
        while( l1 || l2){
            int val = 0;
            if( l1 == nullptr){
                val = 0 + l2->val + carry;
                l2 = l2->next;
            }
            else if(l2 == nullptr){
                val = 0 + l1->val + carry;
                l1 = l1->next;
            }
            else{
                val = l1->val + l2->val + carry;
                l2 = l2->next;
                l1 = l1->next;
            }
            carry = val/10;
            val = val%10; 
            ListNode *newNode = new ListNode(val);
            dummy->next = newNode; 
            dummy = dummy->next;
        }
        if( carry != 0){
            ListNode *newNode = new ListNode(carry);
            dummy->next = newNode;
        }
        return head->next;
    }
};
