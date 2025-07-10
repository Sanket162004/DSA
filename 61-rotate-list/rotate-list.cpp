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

        ListNode*temp=head;


       
        int n=0;

        while(temp){

          n=n+1;
          temp=temp->next;
        }

        temp=head;

        vector<int>ans(n);

        int i=0;

        while(temp){
            ans[i]=temp->val;
            temp=temp->next;
            i++;
        }

        if(n==0){
            return head;
        }


        k=k%n;

        reverse(ans.begin(),ans.end());
        reverse(ans.begin(),ans.begin()+k);

        reverse(ans.begin()+k,ans.end());

        ListNode*curr=new ListNode(0);

        ListNode*currhead=curr;

        for(int i=0;i<n;i++){
            currhead->next=new ListNode(ans[i]);
            currhead=currhead->next;
            
        }


        return curr=curr->next;




      
    }
};