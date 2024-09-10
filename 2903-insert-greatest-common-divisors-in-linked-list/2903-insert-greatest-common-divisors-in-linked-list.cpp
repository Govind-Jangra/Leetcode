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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {

        if(!head or !head->next) return head;
        ListNode *ansHead = head;
        ListNode *prevNode = head;
        ListNode *currNode = head->next;
        while(currNode){
            int divisor = __gcd(prevNode->val, currNode->val);
            ListNode *newNode = new ListNode(divisor);
            prevNode->next = newNode;
            newNode->next = currNode;
            prevNode = currNode;
            currNode = currNode->next;
        }
        return ansHead;
    }
};