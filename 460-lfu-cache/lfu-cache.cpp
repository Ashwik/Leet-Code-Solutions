class LFUCache {
public:

    unordered_map<int,pair<int,int>> cache;
    unordered_map<int,list<int>::iterator> listItrMap;
    unordered_map<int,list<int>> freq;

    int capacity;
    int minFreq=0;

    LFUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(!cache.count(key)){
            return -1;
        }
        updateFrequency(key);
        return cache[key].first;
    }
    
    void put(int key, int value) {
        if(capacity<=0){
            return;
        }

        if(get(key)!=-1){
            cache[key].first = value;
            return;
        }

        if(cache.size()==capacity){
            int leastFrequentKey = freq[minFreq].back();
            cache.erase(leastFrequentKey);
            listItrMap.erase(leastFrequentKey);
            freq[minFreq].pop_back();
        }
        cache[key] = {value,0};
        freq[0].push_front(key);
        listItrMap[key] = freq[0].begin();
        minFreq = 0;
    }

    void updateFrequency(int key){
        int freqCount = cache[key].second;
        cache[key].second = freqCount+1;

        freq[freqCount].erase(listItrMap[key]);
        
        freq[freqCount+1].push_front(key);
        listItrMap[key] = freq[freqCount+1].begin();

        if(freq[minFreq].size()==0){
            freq.erase(minFreq);
            minFreq++;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */