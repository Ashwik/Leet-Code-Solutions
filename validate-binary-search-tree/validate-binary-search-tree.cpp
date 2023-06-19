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

    bool valid(TreeNode* root,TreeNode* left,TreeNode* right){
        if(root==NULL){
            return true;
        }
        
        if((left!=NULL && root->val <= left->val) || (right!=NULL && root->val >= right->val)){
            return false;
        }
                

        bool a = valid(root->left,left,root);
        if(a==false){return false;}
        bool b = valid(root->right,root,right);

        return a & b;
    }

    bool isValidBST(TreeNode* root) {
        
        return valid(root,NULL,NULL);

    }
};