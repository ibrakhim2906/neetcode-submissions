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
        int[] counter = new int[2];
        counter[0] = k;

        dfs(root, counter);

        return counter[1];
    }

    public void dfs(TreeNode root, int[] counter) {
        if (root==null) {
            return;
        }

        dfs(root.left, counter);
        counter[0]-=1;
        if (counter[0]==0) {
            counter[1] = root.val;
            return;
        }
        dfs(root.right, counter);
    }
}
