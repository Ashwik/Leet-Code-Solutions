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

    int findPathSum(TreeNode* root,int &maxSum){

        if(root==NULL){
            return 0;
        }
        int leftSum = findPathSum(root->left, maxSum);
        int rightSum = findPathSum(root->right, maxSum);

        maxSum = max(maxSum, root->val + leftSum + rightSum);

        int res = max(root->val+leftSum, root->val+rightSum);
        res = max(root->val, res);
        maxSum = max(maxSum, res);
        return res;
    }

    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        findPathSum(root, ans); 
        return ans;
    }
};