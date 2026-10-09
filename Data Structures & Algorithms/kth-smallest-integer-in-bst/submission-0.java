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
    public int kthSmallest(TreeNode root, int k) {
        ArrayList<Integer> values = new ArrayList<>();

        dfs(values, root);

        return values.get(k-1);
        
    }

    public void dfs(ArrayList<Integer> arr ,TreeNode root) {
        if (root==null) {
            return;
        }

        dfs(arr, root.left);
        arr.add(root.val);
        dfs(arr, root.right);
    }
}
