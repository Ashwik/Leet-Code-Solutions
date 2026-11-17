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
        vector<int> ans;

        while(root!=NULL){
            if(root->left==NULL){
                ans.push_back(root->val);
                root = root->right;
            }else{
                TreeNode* pred = root->left;
                while(pred->right != NULL && pred->right != root){
                    pred = pred->right;
                }

                if(pred->right==NULL){
                    pred->right = root;
                    root = root->left;
                }else{
                    pred->right = NULL;
                    ans.push_back(root->val);
                    root = root->right;
                }
            }
        }
        return ans;
    }
};