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
    ListNode* rotateRight(ListNode* head, int k) {
        int n=0;
        ListNode*temp=head,*pre=nullptr;
        while(temp){
            n++;
            pre=temp;
            temp=temp->next;
        }
        if(n==0)    return head;
        temp=head;

        k=k%n;
        int moves=n-k-1;
        while(moves--){
            temp=temp->next;
        }
        pre->next=head;
        head=temp->next;
        temp->next=nullptr;
        return head;
    }
};