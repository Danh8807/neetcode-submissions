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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr){
            return nullptr;
        }       
        ListNode* count = head;
        int size = 0;
        while(count){
            size++;
            count = count->next;
        }
        ListNode dummy(0);
        dummy.next = head;
        int target = size - n;
        ListNode* l1 = &dummy;
        int index = 0;
        while(l1){
            if(index == target){
                ListNode* temp = l1->next->next;
                l1->next->next = nullptr;
                l1->next = temp;
            }
            index++;
            l1 = l1->next;
        }
        return dummy.next;
    }
};
