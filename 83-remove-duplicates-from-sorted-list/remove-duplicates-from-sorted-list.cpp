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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next)    return head;
        ListNode *cur=head,*front=head->next;
        while(front){
            if(cur->val==front->val){
                front=front->next;
                // if(front)    front->prev=cur;
                delete cur->next;
                cur->next=front;
            }else{
                cur=front;
                front=front->next;
            }
        }
        return head;
    }
};