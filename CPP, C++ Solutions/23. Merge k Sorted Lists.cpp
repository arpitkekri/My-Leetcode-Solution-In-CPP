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
struct greater1 {
  bool operator()(ListNode* a,ListNode* b) {
    return a->val > b->val;
  }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
    /******************************************************************
        // TC - O(N*logN) : N is number of total nodes in all lists
        // SC - O(N)
        // push in minq and than pop
        priority_queue<int, vector<int>, greater<int> > minq;
        for(ListNode* list: lists) {
            ListNode* head = list;
            while(head != NULL) {
                minq.push(head -> val);
                head = head -> next;
            }
        }
    
        // Recreate the sorted list 
        if(minq.size() == 0) return NULL;
        ListNode* root = new ListNode(minq.top());
        minq.pop();
        ListNode* res = root;
        while(minq.size()) {
            ListNode* temp = new ListNode(minq.top());
            root->next = temp;
            root = root -> next; 
            minq.pop();
        }
        return res;
    ***********************************************************************/
    
        
    /*********************************************************************/
        // 2nd Approach 
        // TC - O(N*logK): K - No of lists, N is number of total nodes in all lists
        // SC = O(K)
        
        // Custom comparator
        // push one element at a time in minq from all lists -> take the min -> push into the resultant list -> iterate one more element from the list from we remove element
        // push the node, !value
        // custom comparator -> derive the logic for min heap
        
        priority_queue<ListNode*, vector<ListNode*>, greater1> minq;
        for(ListNode* list: lists) {
            if(list != NULL) minq.push(list);
        }
        if(minq.size() == 0) return NULL;
        ListNode* res = minq.top();
        ListNode* temp = minq.top();
        minq.pop();
        // insert the next value of this list
        if(temp && temp -> next != NULL) {
            minq.push(temp -> next);
        }
        ListNode* root = res;
        // let x -> no. of all elements
        while(minq.size()) {
            res -> next = minq.top();
            ListNode* temp = minq.top();
            minq.pop();
            // insert the next value of this list
            if(temp && temp -> next != NULL) {
                minq.push(temp -> next);
            }
            res = res -> next;
        }
        return root;
    /*********************************************************************/
    }
};