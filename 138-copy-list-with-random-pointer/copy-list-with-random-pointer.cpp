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

class Solution {
public:
    Node* copyRandomList(Node* head) {
        //Brute force
        // Node*temp=head;
        // map<Node*,Node*>mpp;
        // while(temp){
        //     Node* newNode=new Node(temp->val);
        //     mpp[temp]=newNode;
        //     temp=temp->next;
        // }
        // temp=head;
        // while(temp){
        //     mpp[temp]->next=mpp[temp->next];
        //     mpp[temp]->random=mpp[temp->random];
        //     temp=temp->next;
        // }
        // return mpp[head];


        //Optimal
        Node*temp=head;
        //insert copyNodes in between.
        while(temp){
            Node* nextElement=temp->next;
            Node* cpNode=new Node(temp->val);
            cpNode->next=nextElement;
            temp->next=cpNode;
            temp=nextElement;
        }
        temp=head;
        //initialize random pointers in copy nodes.
        while(temp){
            if(temp->random) temp->next->random=temp->random->next;
            else    temp->next->random=nullptr;
            temp=temp->next->next;
        }
        Node* dNode=new Node(-1);
        Node* res=dNode;
        temp=head;
        //connecting next in both lists.
        while(temp){
            res->next=temp->next;
            temp->next=temp->next->next;

            res=res->next;
            temp=temp->next;
        }
        return dNode->next;
    }
};