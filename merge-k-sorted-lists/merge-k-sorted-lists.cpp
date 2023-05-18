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
    
    ListNode* mergelists(ListNode* l1, ListNode* l2){
        
        ListNode* res = new ListNode(0);
        ListNode* v = res;
        
        while(l1!=NULL && l2 !=NULL){
            if(l1->val<l2->val){
                res->next = l1;
                l1 = l1->next;
            }else{
                res->next = l2;
                l2 = l2->next;
            }
            res = res->next;
        }
        
        if(l1!=NULL){
            res->next = l1;
        }
        if(l2!=NULL){
            res->next = l2;
        }
        return v->next;
    }
    
    
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        if(lists.size()==0){
            return NULL;
        }else if(lists.size()==1){
            return lists[0];
        }
    
        
        // while(last!=0){
            
        //     start = 0;
        //     temp = last;
            
        //     while(start<temp){
                
        //         lists[start] = mergelists(lists[start],lists[temp]);
        //         start++;
        //         temp--;
                
        //     }
        //     last = temp;        
            
        // }
        ListNode* cur;
        ListNode* prev = lists[0];
        ListNode* res = prev;

        for(int i=1;i<lists.size();i++){
            cur = lists[i];
            res = mergelists(cur,prev);
            prev = res;
        }
        return res;
    }
};
