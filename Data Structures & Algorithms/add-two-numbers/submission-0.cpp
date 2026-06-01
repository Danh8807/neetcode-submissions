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
        int rem = 0;
        while( l1 || l2){
            int num = 0;
            if(!l1){
                num = l2->val + rem;
                l2 = l2->next;
            }
            else if(!l2){
                num = l1->val + rem;
                l1 = l1->next;
            }
            else{
                num = l1->val + l2->val + rem; 
                l1 = l1->next;
                l2 = l2->next;
            }
            ListNode* tmp = new ListNode(num%10);
            if( num >= 10){
                rem = num/10;
            }
            else{
                rem = 0;
            }
            dummy->next = tmp;
            dummy = dummy->next;
        }
        if( rem > 0){
            ListNode* tmp2 = new ListNode(rem);
            dummy->next = tmp2;
        }
        return head->next;
    }
};
