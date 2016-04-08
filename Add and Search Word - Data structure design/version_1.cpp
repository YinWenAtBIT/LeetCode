class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() {
        for(int i=0; i<26; i++)
            child[i] = NULL;
        count =0;
    }
    
    char ch;
    TrieNode * child[26];
    int count;
};


class WordDictionary {
public:
    WordDictionary()
    {
        root = new TrieNode();
    }
    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode * p = root;
        int i=0;
        int len = word.size();
        while(i<len)
        {
            int num = word[i] - 'a';
            if(p->child[num] == NULL)
            {
                p->child[num] = new TrieNode();
                p->ch = word[i];
            }
            
            p= p ->child[num];
            i++;
        }
        p->count++;        
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return search_with_node(word, 0, root);       
    }
    
    bool search_with_node(string &word, int start, TrieNode * p)
    {
        int len = word.size();
        if(start == len)
            return p->count>0;
        
        int i= start;
        while(i<len)
        {
            if(word[i] != '.')
            {
                int num = word[i] - 'a';
                if(p->child[num])
                {
                    p = p->child[num];
                    i++;
                }
                else
                    break;
            }
            else
            {
                for(int j=0; j<26; j++)
                {
                    if(p->child[j])
                    {
                        if(search_with_node(word, i+1, p->child[j]))
                            return true;
                    }
                }
                return false;
            }
        }
        if(i<len)
            return false;
        return p->count>0;     
    }
    
    
private:
    TrieNode* root;
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");