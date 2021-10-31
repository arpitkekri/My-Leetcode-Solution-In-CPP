/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(!head) return head;
        Node *temp = head;
        while(temp->child || temp->next) {
            if(temp -> child) {
                Node *childNode = flatten(temp->child);
                
                while(childNode -> next) {
                    childNode = childNode -> next;
                }
                
                Node *next = temp->next;
                temp -> next = temp -> child;
                temp -> child -> prev = temp;
                temp -> child = NULL;
                if(next) {
                    childNode -> next = next;
                    next -> prev = childNode;
                }
            }
            temp = temp -> next;
        }
        return head;
    }
};