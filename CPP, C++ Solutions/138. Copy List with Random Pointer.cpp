/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
// Simple Linked-List only solution 
// TC - O(N)
// SC - O(N) for new Linked List
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) {
            return NULL;
        }
        Node *temp = head;
        Node *copyNode = NULL;
        while(temp) {
            copyNode = new Node(temp->val);
            copyNode->next = temp->next;
            temp->next = copyNode;
            temp = copyNode->next;
        }
        temp = head;
        while(temp) {
            copyNode = temp->next;
            if(temp->random)
                copyNode->random = temp->random->next;
            temp = copyNode->next;
        }
        Node* res = head->next;
        temp = head;
        
        while(temp) {
            copyNode = temp->next;
            temp->next = copyNode->next;
            temp = temp->next;
            if(temp) copyNode->next = temp->next;   
        }
        return res;
    }
};