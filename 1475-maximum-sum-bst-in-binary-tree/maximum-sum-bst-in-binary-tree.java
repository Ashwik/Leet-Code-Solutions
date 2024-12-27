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
    public int[] findMaxSum(TreeNode root, int[] ans){
        int[] res = new int[4];
        if(root==null){
            res[0]=Integer.MAX_VALUE;
            res[1]=Integer.MIN_VALUE;
            return res;
        }

        int[] left = findMaxSum(root.left,ans);
        int[] right = findMaxSum(root.right,ans);

        if(left[3] == 1 || right[3] ==1 || root.val<=left[1] || root.val>=right[0]){
            res[3]=1;
            return res;
        }

        int sum = root.val;
        sum += left[2] + right[2];
        ans[0] = Math.max(sum,ans[0]);
        res[0]=Math.min(root.val,left[0]);
        res[1]=Math.max(root.val,right[1]);
        res[2] = sum;
        return res;
    }

    public int maxSumBST(TreeNode root) {
        int[] ans = new int[1];
        findMaxSum(root,ans);
        return ans[0];
    }
}