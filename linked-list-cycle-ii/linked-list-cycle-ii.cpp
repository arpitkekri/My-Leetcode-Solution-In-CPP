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
    ListNode *detectCycle(ListNode *head) {
        if(!head) return NULL;
        ListNode *slow = head, *fast = head;
        while(fast && fast->next && slow) {
            fast = fast->next->next;
            slow = slow -> next;
            if(fast == slow) break;
        }
        if(!fast || !fast->next) return NULL;
        slow = head;
        while(fast != slow) {
            slow = slow->next;
            fast = fast -> next;
        }
        return slow;
    }
};