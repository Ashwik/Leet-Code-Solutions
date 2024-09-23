class LFUCache {
public:

    int minfreq=0;
    int capacity;
    int size = 0;
    unordered_map<int,pair<int,int>> cache;// key -> {value,count}
    unordered_map<int,list<int>::iterator> listitmap; // key -> freqmap[ind].begin()+i
    unordered_map<int,list<int>> freqmap;// count-> list<int> keys

    LFUCache(int capacity) {
        this->capacity = capacity;
    }
    
  
    int get(int key) {

        if(!cache.count(key)){
            return -1;
        }
        updatefrequency(key);
        return cache[key].first;
    }

    void remove(){
        int leastfrequentkey = freqmap[minfreq].back(); // keyd in freqmap are orderd by most recently used 
        cache.erase(leastfrequentkey);
        listitmap.erase(leastfrequentkey);
        freqmap[minfreq].pop_back();// least recently used key in same frequency keys
    }

    void put(int key, int value) {

        if(capacity<=0){
            return;
        }

        if(get(key)!=-1){
            cache[key].first = value;
        }else{
            if(cache.size()>=capacity){
                remove();
            }
            cache[key] = {value,0};
            freqmap[0].push_front(key);
            listitmap[key] = freqmap[0].begin(); // point listiterator[key] to frequncy linked list
            minfreq = 0;
        }
    }

    void updatefrequency(int key){

        int count = cache[key].second;
        cache[key].second = count+1;
        freqmap[count].erase(listitmap[key]); //listmap[key] contains freqmap[count].begin() + some unknown i
        freqmap[count+1].push_front(key);
        listitmap[key] = freqmap[count+1].begin();

        if(freqmap[minfreq].size()==0){ // remove empty frequency list
            freqmap.erase(minfreq);
            minfreq++;
        }

    }

};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */