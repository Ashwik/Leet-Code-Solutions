/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {

        if(head==NULL){return head;}
        
        ListNode* slow = head;
        ListNode* fast = head;
        bool flag = false;
        
        while(slow != NULL && fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast){
                flag = true;
                break;
            }
        }
        if(flag == false){
            return NULL;
        }

        slow = head;

        while(slow!=fast){
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
        
    }
};