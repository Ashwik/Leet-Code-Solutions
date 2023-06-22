class LRUCache {
public:
    struct ListNode{
        int key;
        int value;
        ListNode* left;
        ListNode* right;

        ListNode(int key,int value,ListNode* left, ListNode* right){
            this->key = key;
            this->value = value;
            this->left = left;
            this->right = right;
        }
    };

    ListNode* head = new ListNode(0,0,NULL,NULL);
    ListNode* tail = new ListNode(0,0,NULL,NULL);
    unordered_map<int,ListNode*> mp;


    int cap =0;
    LRUCache(int capacity) {
        cap = capacity;
        head->right = tail;
        tail->left = head;
    }
    
    int get(int key) {
        
        if(mp.find(key)==mp.end()){
            return -1;
        }
        ListNode* node = mp[key];
        deletefromlist(node);
        insertintolist(node);
        return node->value;
    }
    
    void put(int key, int value) {
        ListNode* node;
        if(mp.find(key)==mp.end()){
            if(mp.size()==cap){
                node = head->right;
                deletefromlist(node);
                mp.erase(node->key);
            }
            node = new ListNode(key,value,NULL,NULL);
            mp.insert({key,node});
            insertintolist(node);
        }else{
            node = mp[key];
            node->value = value;
            deletefromlist(node);
            insertintolist(node);
        }
    }

    void deletefromlist(ListNode* node){
        node->left->right = node->right;
        node->right->left = node->left;
    }

    void insertintolist(ListNode* node){
        ListNode* prev = tail->left;
        prev->right = node;
        node->left = prev;
        /////
        tail->left = node;
        node->right = tail;
        
    }

};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */