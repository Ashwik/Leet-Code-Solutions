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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<TreeNode*> v;
        vector<int> ans;
        
        while(root!=NULL || v.size()!=0){
            if(root!=NULL){
                v.push_back(root);
                root = root->left;
            }else{
                root = v.back();
                v.pop_back();
                ans.push_back(root->val);
                root = root->right;
            }
        }
        return ans;
    }
};