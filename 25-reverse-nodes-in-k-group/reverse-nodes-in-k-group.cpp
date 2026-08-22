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
        // Check if there are at least k nodes left in the list
        ListNode* cursor = head;
        for (int i = 0; i < k; ++i) {
            if (!cursor) return head; // Less than k nodes left, leave as is
            cursor = cursor->next;
        }
        
        // Reverse the first k nodes
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;
        
        for (int i = 0; i < k; ++i) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        // Recursively call for the rest of the list and connect the blocks
        head->next = reverseKGroup(curr, k);
        
        // `prev` is the new head of the reversed k-group
        return prev;
    }
};