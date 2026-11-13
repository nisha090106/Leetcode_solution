class LRUCache {
    private:
    int capacity;
    list<pair<int,int>> cache;
    unordered_map<int,list<pair<int,int>>::iterator>mp;
public:
    LRUCache(int capacity) {
        this->capacity=capacity;
        
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end()){
            return -1;
        }
        auto it = mp[key];
        cache.splice(cache.begin(),cache,it);
        return it->second;
        
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            auto it= mp[key];
            it->second = value;
            cache.splice(cache.begin(),cache,it);
        }else{
            cache.push_front({key,value});
            mp[key]=cache.begin();
            if(cache.size()>capacity){
                int lrukey = cache.back().first;
                mp.erase(lrukey);
                cache.pop_back();
            }
        }
        
    }
};