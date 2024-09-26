/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    
    bool isNode(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode* res){
        if(root==NULL){
            return false;
        }

        bool isroot = false;
        if(root==p || root == q){
            isroot = true;
        }

        bool left = isNode(root->left, p, q, res);
        bool right = isNode(root->right,p, q, res);

        if(res->left==NULL){
            if(left && right){
                res->left = root;
            }else if((left&&isroot) || (right&&isroot)){
                res->left = root;
            }
        }
        return isroot || left || right;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* res = new TreeNode(0);
        isNode(root,p,q,res);
        return res->left;
    }
};