/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode *> temp;
        if(!n)
            return temp;
        
        vector<vector<vector<TreeNode *>>> dp(n+2);
        for(int i=0; i<n+2; i++)
            dp[i].resize(n+1);
        for(int i=0; i<n+2; i++)
            dp[i][0]. push_back(NULL);
            
            
        
        //二叉树长度l
        for(int l=1; l<=n; l++)
        {
            //起始地点i
            for(int i=1; i<=n+1 -l; i++)
            {
				//中点
                for(int j=i; j<=i+l-1; j++)
                {
                    vector<TreeNode *> & left = dp[i][j-i];
                    vector<TreeNode *> & right = dp[j+1][l-1-(j-i)];
                    int left_kind = left.size();
                    int right_kind = right.size();
                    for(int l_count =0; l_count<left_kind; l_count++)
                        for(int r_count =0; r_count< right_kind; r_count++)
                        {
							TreeNode * mid = new TreeNode(j);
                            mid->left = left[l_count];
                            mid->right = right[r_count];
                            dp[i][l].push_back(mid);
                        }
                }
                
            }
        }
        
        return dp[1][n];
        
    }
};