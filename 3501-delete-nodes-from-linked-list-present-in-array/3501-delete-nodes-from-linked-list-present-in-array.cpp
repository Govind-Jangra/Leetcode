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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int> st;
        for(auto it:nums) st.insert(it);
        ListNode* temp = new ListNode(0, head);
        ListNode* c = temp;
        while(c->next){
            if (st.find(c->next->val)==st.end())  c = c->next;
            else c->next = c->next->next;
        }
        return temp->next;
    }
};