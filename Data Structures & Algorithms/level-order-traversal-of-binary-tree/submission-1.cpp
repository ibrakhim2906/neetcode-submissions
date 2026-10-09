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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res{};

        traverse(root, 0, res);

        return res;

        

        
        
    }
    
    void traverse(TreeNode* root, int level, vector<vector<int>>& res)
    {
        if (root==nullptr)
        {
            return;
        }

        if (res.size()<=level)
        {
            res.push_back({});
        }

        res[level].push_back(root->val);
        
        traverse(root->left, level+1, res);
        traverse(root->right, level+1, res);
    }

};
