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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum = 0,rem=0;
        ListNode* prev;
        ListNode* head=l1;

        while(l1!=NULL && l2!=NULL){
            sum = l1->val + l2->val + rem;
            l1->val = sum%10;
            rem = sum/10;
            
            prev = l1;
            l1 = l1->next;
            l2 = l2->next;
        }

        if(l2!=NULL){
            if(prev==NULL){
                head = l2;
            }else{
                prev->next = l2;
            }
            l1 = l2;
        }

        while(l1!=NULL && rem!=0){
            sum = l1->val + rem;
            l1->val = sum%10;
            rem = sum/10;
            prev = l1;
            l1 = l1->next;
        }
        if(rem!=0){
            prev->next = new ListNode(rem);
        }

        return head;

    }
};