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

/********************* Method-1 ( Using Hash Table, i.e. Map) *****************
// TC - O(N) assuming Map access is O(1) avg. 
// SC - O(N) for Map and new List
class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*, Node*> m;
        Node* ptr = head;
        while (ptr) {
            m[ptr] =new Node(ptr->val);
            ptr = ptr->next;
        }
        ptr = head;
        while(ptr) {
            m[ptr]->next = m[ptr->next];
            m[ptr]->random = m[ptr->random];
            ptr = ptr->next;
        }
        return m[head];
    }
};
**************************************************************************/

/**************** Method - 2 (Without Map) *************************/

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