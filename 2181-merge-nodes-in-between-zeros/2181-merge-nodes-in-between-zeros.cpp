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
    ListNode* mergeNodes(ListNode* head) {
        
        if(head == nullptr) return head;
        
        ListNode* dummy = new ListNode(0);
        ListNode* dummyHead = dummy;
        ListNode* temp = head->next;
        
        int count = 0;
        while(temp != nullptr){
            
            if(temp->val != 0){
                count += temp->val;
                temp = temp->next;
            }
            else{
                ListNode* t = new ListNode(count);
                dummy->next = t;
                dummy = t;
                count = 0;
                temp = temp->next;
            }
        }
        
        return dummyHead->next;
    }
};