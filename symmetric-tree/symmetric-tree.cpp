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

    bool issymtree(TreeNode* lsub, TreeNode* rsub){
        if(lsub == NULL && rsub == NULL){return true;}
        if(lsub==NULL || rsub==NULL){return false;}
        if(lsub->val != rsub->val){
            return false;
        }

        return issymtree(lsub->left,rsub->right) & issymtree(lsub->right,rsub->left);
    }

    bool isSymmetric(TreeNode* root) {
        
        if(root==NULL){return true;}
        return issymtree(root->left,root->right);

    }
};