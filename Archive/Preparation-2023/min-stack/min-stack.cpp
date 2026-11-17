class MinStack {
public:

    struct ListNode{
        int val;
        int min;
        ListNode* next;
        ListNode(int val,int min, ListNode* next){
            this->val = val;
            this->min = min;
            this->next = next;
        }
    };

    ListNode* head;

    MinStack() {
         head = NULL;
    }
    
    void push(int val) {
        if(head==NULL){
            head = new ListNode(val,val,NULL);
        }else{
            head = new ListNode(val,min(head->min,val),head);
        }

    }
    
    void pop() {
        head = head->next;
    }
    
    int top() {
        return head->val;
    }
    
    int getMin() {
        return head->min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */