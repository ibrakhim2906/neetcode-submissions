/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
   public:
    bool valid = true;
    bool isValidBST(TreeNode* root) {

        dfs(root, LONG_MIN, LONG_MAX);

        return valid;
    }

    void dfs(TreeNode* root, long left, long right) {
        if (root == nullptr) {
            return;
        }

        if (root->val <= left) {
            valid = false;
            return;
        }

        if (root->val >= right) 
        {
            valid = false;
            return;
        }

        dfs(root->left, left, root->val);
        dfs(root->right, root->val, right);
    }
};
