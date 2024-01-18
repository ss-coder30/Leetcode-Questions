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
    ListNode* reverseLinkedList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* newHead = reverseLinkedList(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next = nullptr;

        return newHead;
    }

    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return true; // An empty list or a list with one node is a palindrome
        }

        ListNode* slow = head;
        ListNode* fast = head;

        // Move slow to the middle of the list
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse the second half of the list
        ListNode* secondHalfReversed = reverseLinkedList(slow->next);

        // Compare the first half with the reversed second half
        ListNode* temp = head;
        while (secondHalfReversed != nullptr) {
            if (temp->val != secondHalfReversed->val) {
                return false;
            }
            temp = temp->next;
            secondHalfReversed = secondHalfReversed->next;
        }

        return true;
    }
};