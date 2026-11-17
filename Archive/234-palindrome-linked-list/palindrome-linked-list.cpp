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

    bool isPalindrome(ListNode* head) {
        ListNode* temp = head;
        int n = 0;
        while(temp!=NULL){
            temp = temp->next;n++;
        }
        n = (n+1)/2;
        temp = head;
        while(n>1){
            temp = temp->next;n--;
        }

        temp = reverseList(temp);

        while(temp!=NULL && head!=NULL){
            if(head->val != temp->val){
                return false;
            }
            head = head->next;
            temp = temp->next;
        }
        return true;
    }
};