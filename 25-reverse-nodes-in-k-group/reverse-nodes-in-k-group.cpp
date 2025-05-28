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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || !head->next)    return head;
        if(k==1)    return head;
        int cntMulK=0;
        ListNode *temp=head;
        while(temp){
            temp=temp->next;
            cntMulK++;
        }
        ListNode*cur=head,*back=NULL,*front=head->next,*lastNode=head,*x=NULL;
        cntMulK/=k;
        while(cntMulK--){
            int cnt=k;
            while(cnt--){
                cur->next=back;
                back=cur;
                cur=front;
                if(front)    front=front->next;
            }
            if(head==lastNode){  
                head=back;
            }
            else{
                lastNode->next=back;
                lastNode=x;
            }
            x=cur;
            back=NULL;
            
        }
        lastNode->next=cur;;
        return head;



    }
};