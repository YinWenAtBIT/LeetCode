class LRUCache{
public:
    unordered_map<int, int> dic;
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
            erase_last();
        }
    }
    void set_front(int key)
    {
        for(auto it = lru.begin(); it != lru.end(); it++)
        {
            if(*it == key)
            {
                lru.erase(it);
                lru.push_front(key);
                break;
            }
        }
    }
    
    void erase_last()
    {
        if(lru.size()>cap)
        {
            int temp = lru.back();
            lru.pop_back();
            dic.erase(temp);
        }
    }
};