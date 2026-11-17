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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode* prev = new ListNode(0);
        ListNode* ans = prev;

        while(list1!=NULL && list2!=NULL){
            if(list1->val<list2->val){
                prev->next = list1;
                list1 = list1->next;
            }else{
                prev->next = list2;
                list2 = list2->next;
            }
            prev = prev->next;
        }

        if(list1!=NULL){
            prev->next = list1;
        }else{
            prev->next = list2;
        }

        prev = ans;
        ans = ans->next;
        delete prev;
        return ans;

    }
};