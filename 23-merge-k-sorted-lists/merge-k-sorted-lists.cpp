class Solution {
private:
    // LeetCode 21. Merge Two Sorted Lists
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* prev = &dummy;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                prev->next = l1;
                l1 = l1->next;
            }
            else {
                prev->next = l2;
                l2 = l2->next;
            }
            prev = prev->next;
        }
        prev->next = (l1 != nullptr) ? l1 : l2;
        return dummy.next;
    }
    
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        
        while (lists.size() > 1) {
            int mergedSize = (lists.size() + 1) / 2;
            vector<ListNode*> merged;
            for (int i = 0; i < mergedSize; ++i) {
                int index1 = i * 2;
                int index2 = i * 2 + 1;
                ListNode* l1 = lists[index1];
                ListNode* l2 = (index2 < lists.size()) ? lists[index2] : nullptr;
                merged.push_back(mergeTwoLists(l1, l2));
            }
            lists = merged;
        }
        
        return lists[0];
    }
};