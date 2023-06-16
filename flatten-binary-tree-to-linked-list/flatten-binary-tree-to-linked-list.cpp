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
    void flatten(TreeNode* root) {
        
        TreeNode* cur = root;

        while(cur!=NULL){
            if(cur->left){
                TreeNode* leftsub = cur->left;
                TreeNode* rightsub = cur->right;
                while(leftsub->right){
                    leftsub = leftsub->right;
                }
                leftsub->right = rightsub;
                cur->right = cur->left;
                cur->left = NULL;
            }
            cur = cur->right;
        }

    }
};