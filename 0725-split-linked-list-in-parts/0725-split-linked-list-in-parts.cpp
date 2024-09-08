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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
         vector<ListNode*> ans(k, NULL);
        int len = 0;
        for (ListNode* temp = root; temp; temp = temp->next)
            len++;


        int n = len / k, r = len % k; 
        ListNode* temp = root, *prev = NULL;
        for (int i = 0; temp && i < k; i++, r--) {
            ans[i] = temp;
            for (int j = 0; j < n + (r > 0); j++) {
                prev = temp;
                temp = temp->next;
            }
            prev->next = NULL;
        }
        return ans;
    }
};