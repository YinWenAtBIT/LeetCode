struct Node {
    Node * ch[26];
    string str;
    Node() {
        for (int i = 0; i < 26; ++i)
            ch[i] = NULL;
            str = "";
    }
};

class Solution {
public:
    vector<string> results;
    Node * root;
    void insert(Node* p, string s) {
        int len = s.size();
        for (int i = 0; i < len; ++i) {
            if (p->ch[s[i]-'a'] == NULL)
                p->ch[s[i]-'a'] = new Node();
            p = p->ch[s[i]-'a'];
        }   
        p->str = s;
    }
    void search(vector<vector<char> > &board, vector<vector<bool> > &mask, Node* p, int x, int y) {
        if (p->str != "") {
            results.push_back(p->str);
            p->str = "";
        }

        mask[x][y] = false;
        if (y + 1 < board[0].size() && mask[x][y+1] && p->ch[board[x][y+1]-'a'] != NULL) {
           search(board,mask, p->ch[board[x][y+1]-'a'], x, y+1);
        }

        if (x + 1 < board.size() && mask[x+1][y] && p->ch[board[x+1][y]-'a'] != NULL) {
           search(board,mask, p->ch[board[x+1][y]-'a'], x+1, y);
        }

        if (y - 1 >= 0 && mask[x][y-1] && p->ch[board[x][y-1]-'a'] != NULL) {
           search(board,mask, p->ch[board[x][y-1]-'a'], x, y-1);
        }

        if (x - 1 >= 0 && mask[x-1][y] && p->ch[board[x-1][y]-'a'] != NULL) {
           search(board,mask, p->ch[board[x-1][y]-'a'], x-1, y);
        }
        mask[x][y] = true;
    }
    /**
     * @param board: A list of lists of character
     * @param words: A list of string
     * @return: A list of string
     */
    vector<string> findWords(vector<vector<char> > &board, vector<string> &words) {
        // write your code here
        root = new Node();
        int len = words.size();
        for (int i = 0; i < len; ++i) { 
            insert(root, words[i]);
        }
        vector<vector<bool> > mask(board.size(), vector<bool>(board[0].size(), true));
        if (board.size() < 1) return results;
        for (int i = 0; i <board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
               if (root->ch[board[i][j]-'a'] != NULL) {
                    search(board, mask, root->ch[board[i][j]-'a'], i, j);
                }
            }
        }
        return results;
    }
};