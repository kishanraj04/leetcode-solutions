/*
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* intersectPoint(Node* head1, Node* head2) {
    Node* p1 = head1;
    Node* p2 = head2;

    while (p1 != p2) {
        p1 = (p1 == nullptr) ? head1 : p1->next;
        p2 = (p2 == nullptr) ? head2 : p2->next;
    }

    return p1; 
    }
};