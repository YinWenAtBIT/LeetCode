struct Node {  
    int val;  
    int index;  
    int cnt;  
    Node(int val, int index) : val(val), index(index), cnt(0) {}  
    bool operator <= (const Node &node2)const {  
        return val <= node2.val;  
    }  
};  
  
class Solution {  
public:  
    void combine(vector<Node> &nums, int Lpos, int Lend, int Rend, vector<Node> &temp) {  
        int Rpos = Lend + 1;  
        int Tpos = Lpos;  
        int n = Rend - Lpos + 1;  
        int t = Rpos;  
        while (Lpos <= Lend && Rpos <= Rend) {  
            if (nums[Lpos] <= nums[Rpos]) {  
                temp[Tpos] = nums[Lpos];  
                temp[Tpos].cnt += Rpos - t ;  
                Tpos++; Lpos++;  
            }  
            else {  
                temp[Tpos++] = nums[Rpos++];  
            }  
        }  
  
        while (Lpos <= Lend) {  
            temp[Tpos] = nums[Lpos];  
            temp[Tpos].cnt += Rpos - t;  
            Tpos++; Lpos++;  
        }  
  
        while (Rpos <= Rend)   
            temp[Tpos++] = nums[Rpos++];  
  
        for (int i = 0; i< n; i++, Rend--)   
            nums[Rend] = temp[Rend];  
    }  
  
    void merge_sort(vector<Node> & nums, int L, int R, vector<Node> &temp) {  
        if (L < R) {  
            int m = (L + R) >> 1;  
            merge_sort(nums, L, m, temp);  
            merge_sort(nums, m + 1, R, temp);  
            combine(nums, L, m, R, temp);  
        }  
    }  
  
    vector<int> countSmaller(vector<int>& nums) {  
        vector<Node> mynums;  
        vector<Node> temp(nums.size(), Node(0, 0));  
        for (int i = 0; i < nums.size(); i++)   
            mynums.push_back(Node(nums[i], i));  
          
        vector<int> ans(nums.size(), 0);  
        merge_sort(mynums, 0, nums.size() - 1, temp);  
  
        for (int i = 0; i < nums.size(); i++)   
            ans[mynums[i].index] = mynums[i].cnt;  
          
        return ans;  
    }  
};  