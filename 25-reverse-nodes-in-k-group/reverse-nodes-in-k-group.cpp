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

    ListNode* reverseList(ListNode* head){
        ListNode* prev = NULL;
        ListNode* next;

        while(head!=NULL){
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }  

    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode* curStart;
        ListNode* newListStart;
        int n = k;
        ListNode* cur = new ListNode(0);
        ListNode* ans = NULL;

        while(head!=NULL){
            curStart = head;
            
            n = k;
            while(n>1 && head!=NULL){
                head = head->next;
                n--;
            }

            if(head==NULL){
                break;
            }

            newListStart = head->next;
            head->next = NULL;

            cur->next = reverseList(curStart);
            if(ans==NULL){
                ans = cur->next;
            }
            cur = curStart;
            cur->next = newListStart;
            head = newListStart;
        }
        return ans; 
    }
};