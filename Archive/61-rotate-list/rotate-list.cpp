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
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(head==NULL || head->next == NULL){return head;}
        int n=0;
        ListNode* temp = head;
        ListNode* lastNode;
        while(head!=NULL){
            lastNode = head;
            head = head->next;
            n++;
        }
        k = k%n;
        if(k==0){return temp;}
        int num = n-k;
        
        lastNode->next = temp;
        while(num--){
            lastNode = temp;
            temp = temp->next;  
        }
        lastNode->next = NULL;

        return temp;
    }
};