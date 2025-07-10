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
    ListNode* middleNode(ListNode* head) {
        
       
        int n=0;

        ListNode*temp=head;

        while(temp){
            n=n+1;
            temp=temp->next;
        }

        vector<int>ans(n);

        temp=head;

        while(temp){
            ans.push_back(temp->val);
            temp=temp->next;
        }

        int mid=n/2;

        while(mid){
            head=head->next;
            mid--;
        }

        return head;

        
    }
};