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
    
    int getpathsum(TreeNode* root,int & ans){
        if(root==NULL){return 0;}

        ans = max(ans,root->val);
        int left =  getpathsum(root->left,ans);
        int right =  getpathsum(root->right,ans);
        if(left>0 && right>0){
            ans = max(ans,left+right+root->val);
        }else if(left>0){
            ans = max(ans,left + root->val);
        }else if(right>0){
            ans = max(ans,right + root->val);
        }
        
        int res;
        if(left<=0 && right<=0){
            res = root->val;
        }else{
            res = max(root->val,root->val + max(left,right));
        }         
        return res;
    }


    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        getpathsum(root,ans);
        return ans;
    }
};