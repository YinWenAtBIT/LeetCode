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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(!root || !p || !q)
            return NULL;
        
        vector<TreeNode *> p_list, q_list;
        find_node(root, p, p_list);
        find_node(root, q, q_list);
        int i=0;
		for(; i<q_list.size() && i<p_list.size(); i++)
        {
            if(q_list[i]!= p_list[i])
                break;
        }
        return q_list[i-1];
    }
    
    bool find_node(TreeNode * root, TreeNode * target, vector<TreeNode *> &list)
    {
        if(!root)
            return false;
        
        list.push_back(root);
        if(root == target)
            return true;
            
        if(find_node(root->left, target, list))
            return true;
        if(find_node(root->right, target, list))
            return true;
        list.pop_back();
        return false;
    }
};