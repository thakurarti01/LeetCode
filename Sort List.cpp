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
        ListNode *split(ListNode* head){
            if(!head || !head->next) return NULL;
            ListNode* fast = head->next;
            ListNode* slow = head;
            while(fast&& fast->next){
                slow = slow->next;
                fast = fast->next->next;
            }
            ListNode* temp = slow->next;
            slow->next = NULL;
            return temp;
        }
    
        ListNode* merge(ListNode* first, ListNode* sec){
            if(first == NULL){
                return sec;
            }
            if(sec==NULL){
                return first;
            }
            if(first->val<sec->val){
                first->next = merge(first->next, sec);
                return first;
            }
            else{
                sec->next = merge(first, sec->next);
                return sec;
            }
        }
        ListNode* sortList(ListNode* head) {
            if(head==NULL|| head->next==NULL){
                return head;
            }
            ListNode* sec = split(head);
            head = sortList(head);
            sec = sortList(sec);
            return merge(head, sec);
        }
    };