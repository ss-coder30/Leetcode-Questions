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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL )return NULL;
        ListNode* temp=head;
        int len=0;
        while(temp->next!=NULL){
            temp=temp->next;
            len++;
        }
        len++;
        temp->next = head;
        k%=len;
        k=len-k;
        k--;
        ListNode* temp1=head;
        while(k--)
        {
            temp1=temp1->next;
        }
        head=temp1->next;
        temp1->next=NULL;
        return head;
    } 
};