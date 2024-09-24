class MyHashMap {
public:

    struct ListNode{
        int key;
        int val;
        ListNode* next;
        ListNode(int key, int val, ListNode* next){
            this->key = key;
            this->val = val;
            this->next = next;
        }
    };

    const static int mutex = 12582917;
    const static int size = 19997;
    ListNode* data[size]={};
    MyHashMap() {
        
    }

    int hashFunc(int key){
        return (int)( (long)key*mutex % size);
    }
    
    void put(int key, int value) {
        remove(key);
        int hash = hashFunc(key);
        ListNode* node = new ListNode(key,value, data[hash]);
        data[hash] = node;
    }
    
    int get(int key) {
        ListNode* node = data[hashFunc(key)];
        while(node!=NULL){
            if(node->key == key){return node->val;}
            node = node->next;
        }
        return -1;
    }
    
    void remove(int key) {
        int hash = hashFunc(key);
        ListNode* node = data[hash];
        if(node==NULL){
            return;
        }
        ListNode* temp = new ListNode(0,0,NULL);
        ListNode* prev = temp;
        while(node!=NULL){
            if(node->key == key){
                prev->next = node->next;
                delete node;
                break;
            }
            prev->next = node;
            prev = node;
            node = node->next;
        }
        data[hash] = temp->next;
        delete temp;

    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */