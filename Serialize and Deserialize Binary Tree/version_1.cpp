/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res = "";
        serializeHelper(root, res);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode *root = NULL;
        deserializeHelper(root, data);
        return root;
    }

private:
    void serializeHelper(TreeNode *root, string &res)
    {
        if (root == NULL)
        {
            res += "null ";
            return;
        }
        ostringstream oss;
        oss<<root->val;
        res += oss.str();
        res += ' ';
        serializeHelper(root->left, res);
        serializeHelper(root->right, res);
    }

    void deserializeHelper(TreeNode *&root, string& data)
    {
        if (data.length() == 0)
        {
            return;
        }

        string temp = data.substr(0, data.find(' '));
        data = data.substr(data.find(' ') + 1);

        if (temp.compare("null") == 0)
        {
            root = NULL;
        }
        else
        {
            root = new TreeNode(atoi(temp.c_str()));
            deserializeHelper(root->left, data);
            deserializeHelper(root->right, data);
        }
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));