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
    ListNode* reverseList(ListNode* head) {
    stack<int> st;
    ListNode* temp = head;

    // Step 1: Push values onto the stack
    while (temp) {
        st.push(temp->val);
        temp = temp->next;
    }

    // ab stack maijo jo new element hai usko dal dene ka ne w linkedlist bana ke


    ListNode*newlist=new ListNode(-1);

    ListNode*newhead=newlist;

    ListNode*curr=newhead;


    while(st.empty()==0){
        curr->next=new ListNode(st.top());
        st.pop();
        curr=curr->next;
    }

    newhead=newhead->next;

    return newhead;
    

    }
};