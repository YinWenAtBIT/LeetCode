
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

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
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

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode * p = root;
        int len = word.size();
        int i=0;
        while(i<len)
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
        if(i<len)
            return false;
        return p->count>0;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode * p = root;
        int len = prefix.size();
        int i=0;
        while(i<len)
        {
            int num = prefix[i] - 'a';
            if(p->child[num])
            {
                p = p->child[num];
                i++;
            }
            else
                break;
        }
        return i==len;
        
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");