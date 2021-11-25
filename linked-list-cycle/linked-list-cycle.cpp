/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head) return false;
        ListNode *fast = head, *slow = head;
        while(fast && fast->next && slow) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast && fast != NULL) return true;
        }
        return false;
    }
};