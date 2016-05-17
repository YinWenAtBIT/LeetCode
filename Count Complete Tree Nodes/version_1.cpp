/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public:
    int countNodes(TreeNode *root) {
        if(!root) return 0;
        
        int l = getLeft(root) + 1;
        int r = getRight(root) + 1;
        
        if(l==r) {
            return (2<<(l-1)) - 1;
        } else {
            return countNodes(root->left) + countNodes(root->right) + 1;
        }
    }
    
    int getLeft(TreeNode *root) {
        int count = 0;
        while(root->left) {
            root = root->left;
            ++count;
        }
        return count;
    }
    
    int getRight(TreeNode *root) {
        int count = 0;
        while(root->right) {
            root = root->right;
            ++count;
        }
        return count;
    }
};