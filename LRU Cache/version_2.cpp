class LRUCache{
public:
    unordered_map<int, int> dic;
    unordered_map<int, list<int>::iterator> key_loc;
    list<int> lru;
    int cap;
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(dic.find(key) == dic.end())
            return -1;
        else
        {
            set_front(key);
            return dic[key];
        }
    }
    
    void set(int key, int value) {
        if(dic.find(key) != dic.end())
        {
            dic[key] = value;
            set_front(key);
        }
        else
        {
            dic[key] = value;
            lru.push_front(key);
            key_loc[key] = lru.begin();
            erase_last();
        }
    }
    void set_front(int key)
    {
        list<int>::iterator  it = key_loc[key]; 
        lru.erase(it);
        lru.push_front(key);
        key_loc[key] = lru.begin();
    }
    
    void erase_last()
    {
        if(lru.size()>cap)
        {
            int temp = lru.back();
            lru.pop_back();
            dic.erase(temp);
            key_loc.erase(temp);
        }
    }
};