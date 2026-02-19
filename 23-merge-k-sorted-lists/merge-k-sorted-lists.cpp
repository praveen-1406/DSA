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
    struct compare{
        bool operator()(ListNode*a,ListNode*b){
            return a->val>b->val;   //return true when wrong
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode*head=new ListNode(),*temp=head;
        priority_queue<ListNode*,vector<ListNode*>,compare>pq; //min heap
        for(auto l:lists){
            if(l)    pq.push(l);
        }
        while(!pq.empty()){
            ListNode*smallest=pq.top();
            temp->next=smallest;
            temp=temp->next;
            pq.pop();
            if(smallest->next)    pq.push(smallest->next);
        }
        return head->next;
    }
};