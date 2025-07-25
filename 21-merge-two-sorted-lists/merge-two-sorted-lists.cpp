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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode*List3=new ListNode(-1);

        ListNode*temp=List3;

        ListNode*head=List3;

        while(list1!=nullptr && list2!=nullptr){
            if(list1->val<=list2->val){
                head->next=new ListNode(list1->val);
                list1=list1->next;
            }
            else{
                head->next=new ListNode(list2->val);
                list2=list2->next;
            }

            head=head->next;

        }

        // aagar list1 exist karti ho

        while(list1!=nullptr){
            head->next=new ListNode(list1->val);
                list1=list1->next;
                head=head->next;

        }

        // aagar list 2 exist karti ho

        while(list2!=nullptr){
            head->next=new ListNode(list2->val);
                list2=list2->next;
                head=head->next;

        }


        return temp=temp->next;


    }
};