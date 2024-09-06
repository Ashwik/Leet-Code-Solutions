class LRUCache {
public:

    struct ListNode{
        int key;
        int val;
        ListNode* left;
        ListNode* right;
        ListNode(int key, int val, ListNode *left, ListNode* right){
            this->key = key;
            this->val = val;
            this->left = left;
            this->right = right;
        }
    };

    int maxCap;
    ListNode* startNode;
    ListNode* endNode;
    unordered_map<int,ListNode*> mp;

    LRUCache(int capacity) {
        maxCap = capacity;
        startNode = new ListNode(0,0,NULL,NULL);
        endNode = new ListNode(0,0,NULL,NULL);
        startNode->right = endNode;
        endNode->left = startNode;
    }
    
    void insertNodeAtStart(ListNode* root){
        ListNode* prevNode = startNode;;
        ListNode* nextNode = startNode->right;
        
        prevNode->right = root;
        nextNode->left = root;

        root->right = nextNode;
        root->left = prevNode;
    }

    void removeNode(ListNode* root){
        ListNode* rootleft = root->left;
        ListNode* rootright = root->right;
        rootleft->right = rootright;
        rootright->left = rootleft;
    }

    int get(int key) {
        if(mp.find(key)==mp.end()){
            return -1;
        }
        ListNode* root = mp[key];
        removeNode(root);
        insertNodeAtStart(root);
        return root->val;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            mp[key]->val = value;
            removeNode(mp[key]);
            insertNodeAtStart(mp[key]);
            return;
        }
        if(mp.size()==maxCap){
            mp.erase(endNode->left->key);
            removeNode(endNode->left);
        }
        mp[key] = new ListNode(key,value,NULL,NULL);
        insertNodeAtStart(mp[key]);
        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */