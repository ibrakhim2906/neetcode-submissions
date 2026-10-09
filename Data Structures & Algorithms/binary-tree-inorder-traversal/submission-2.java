/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> inorder = new ArrayList<>();
        
        inorderHelper(root, inorder);


        return inorder;
        
    }

    public void inorderHelper(TreeNode root, List<Integer> arr) {
        
        if (root==null) {
            return;
        }

        inorderHelper(root.left, arr);
        arr.add(root.val);
        inorderHelper(root.right, arr);
    }
}