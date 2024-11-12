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

    void traverse(vector<int>& ans ,int level, int& maxh, TreeNode* root){
        if(root==NULL){return;}
        if(level>maxh){
            ans.push_back(root->val);
            maxh = level;
        }
        traverse(ans,level+1,maxh,root->right);
        traverse(ans,level+1,maxh,root->left);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root==NULL){return ans;}
        ans.push_back(root->val);
        int maxh = 0;
        traverse(ans,0,maxh,root);
        return ans;
    }
};