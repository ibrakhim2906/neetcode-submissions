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
    
    public boolean hasPathSum(TreeNode root, int targetSum) {
        return helper(root, 0, targetSum);
    }

    public boolean helper(TreeNode root, int curSum, int targetSum) {
        if (root==null) {
            return false;
        }

        curSum += root.val;

        if (root.left==null && root.right==null && curSum == targetSum) {
            return true;
        }

        if (helper(root.left, curSum, targetSum)) {
            return true;
        }

        if (helper(root.right, curSum,targetSum)) {
            return true;
        }

        curSum -= root.val;

        return false;
    }
}