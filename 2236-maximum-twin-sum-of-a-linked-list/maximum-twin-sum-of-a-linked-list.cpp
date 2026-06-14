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
    int pairSum(ListNode* head) {
        unordered_map<ListNode*,ListNode*>pre;
        ListNode*slow=head,*fast=head;
        while(fast->next->next!=nullptr){
            pre[slow->next]=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        int maxi=INT_MIN;
        ListNode*rev=slow;
        slow=slow->next;
        while(slow!=nullptr){
            maxi=max(maxi,rev->val+slow->val);
            rev=pre[rev];
            slow=slow->next;
        }
        return maxi;
    }
};