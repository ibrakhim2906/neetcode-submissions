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
class BSTIterator {
public:
    vector<int> result;
    int index = 0;
    BSTIterator(TreeNode* root) {

        TreeNode* curr = root;
        vector<TreeNode*> stck;

        while (curr || stck.size())
        {
            if (curr)
            {
                stck.push_back(curr);
                curr = curr -> left;
                
            } else {
                curr = stck.back();
                stck.pop_back();
                result.push_back(curr->val);
                curr = curr->right;
            }
        }

        
        
    }
    
    int next() {

        return result[index++];
        
    }
    
    bool hasNext() {
        return index < result.size();
        
        
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */