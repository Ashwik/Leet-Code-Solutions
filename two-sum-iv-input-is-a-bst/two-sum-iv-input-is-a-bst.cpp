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

    bool treetraverse(TreeNode* root,TreeNode* cur,int k){
        if(cur==NULL){
            return false;
        }
        
        bool a = searchtree(root,cur,k-cur->val);
        if(a){return a;}

        a = treetraverse(root,cur->left,k);
        if(a){return a;}
        a = treetraverse(root,cur->right,k);
        return a;
    }

    bool searchtree(TreeNode* root,TreeNode* cur, int k){
        if(root==NULL){return false;}
        if(root==cur){
            return false;
        }
        if(root->val==k){return true;}
        if(root->val > k){return searchtree(root->left,cur,k);}
        return searchtree(root->right,cur,k);
    }

    bool findTarget(TreeNode* root, int k) {
        return treetraverse(root,root,k);
    }

};