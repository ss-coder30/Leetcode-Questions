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
    ListNode* middleNode(ListNode* head) {
        if(head->next == nullptr){
            return head;
        }
        
        ListNode* temp = head;
        int count = 1;
        
        while(temp->next != nullptr){
            temp = temp->next;
            count++;
        }
        
        int middle = (count/2) + 1;
        for(int i = 0; i<middle-1; i++){
            head = head->next;
        }
        
        return head;
    }
};