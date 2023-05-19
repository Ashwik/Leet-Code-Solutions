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
    ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) {
        
        ListNode* temp1 = head1;
        ListNode* temp2 = head2;
        unordered_set<ListNode*> st;

        while(temp1!=NULL){
            st.insert(temp1);
            temp1 = temp1->next;
        }
        while(temp2!=NULL){
            if(st.find(temp2)!=st.end()){
                return temp2;
            }
            temp2 = temp2->next;
        }
        return NULL;
    }
};