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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* t1=l1,*t2=l2;
        ListNode *head=new ListNode();
        ListNode* t3=head;
        int c=0;
        while( t1 && t2){
            t3->val=((t1->val)+(t2->val)+c)%10;
            c=(((t1->val)+(t2->val)+c)>9)?1:0;
            if(t1->next!=nullptr || t2->next!=nullptr){
                t3->next=new ListNode();
                t3=t3->next;
            }
            t1=t1->next;
            t2=t2->next;
        }
        while(t1){
            t3->val=((t1->val)+c)%10;
            c=(((t1->val)+c)>9)?1:0;
            if(t1->next!=nullptr){
                t3->next=new ListNode();
                t3=t3->next;
            }
            t1=t1->next;
        }
        while(t2){
            t3->val=((t2->val)+c)%10;
            c=(((t2->val)+c)>9)?1:0;
            if(t2->next!=nullptr){
                t3->next=new ListNode();
                t3=t3->next;
            }
            t2=t2->next;
        }

        if(c==1){
            t3->next=new ListNode(1);
            return head;
        }
        t3->next=nullptr;
        return head;
    }
};