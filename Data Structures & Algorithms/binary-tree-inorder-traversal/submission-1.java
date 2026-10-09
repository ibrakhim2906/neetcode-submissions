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
        ArrayList<Integer> out = new ArrayList<>();

        inorderHelper(out, root);

        return out;
    }

    public void inorderHelper(List<Integer> arr, TreeNode root) {
        if (root==null) {
            return;
        }

        inorderHelper(arr, root.left);
        arr.add(root.val);
        inorderHelper(arr, root.right);
    }
}