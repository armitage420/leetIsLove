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
    ListNode* h = NULL;
    
    bool check(ListNode* tail){
        if(h==NULL || tail==NULL)
            return true;
        
        bool res = check(tail->next);
        
        if(h->val != tail->val)
            return false;
        
        h = h->next;
        return res;
    }
    
    bool isPalindrome(ListNode* head) {
        h = head;
        return check(head);
    }
};