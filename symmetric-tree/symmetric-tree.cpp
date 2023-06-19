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
    bool isSymmetric(TreeNode* root) {
        

        if(root->left == NULL && root->right == NULL){
            return true;
        }else if(root->left == NULL || root->right == NULL){
            return false;
        }
        if(root->left->val != root->right->val){
            return false;
        }
        
        deque<TreeNode*> q1;
        deque<TreeNode*> q2;

        q1.push_front(root->left);
        q2.push_back(root->right);

        TreeNode* leftsub;
        TreeNode* rightsub;

        while(!q1.empty()){
            if(q1.size()!=q2.size()){
                return false;
            }
            int len = q1.size();
            while(len--){
                leftsub = q1.front();q1.pop_front();
                rightsub = q2.back();q2.pop_back();
                if(leftsub->left != NULL && rightsub->right != NULL){
                    if(leftsub->left->val != rightsub->right->val){
                        return false;
                    }else{
                        q1.push_front(leftsub->left);
                        q2.push_back(rightsub->right);
                    }
                }else if(leftsub->left == NULL && rightsub->right == NULL){
                   
                }else if(leftsub->left == NULL || rightsub->right == NULL){
                    return false;
                }

                if(leftsub->right != NULL && rightsub->left != NULL){
                    if(leftsub->right->val != rightsub->left->val){
                        return false;
                    }else{
                        q1.push_front(leftsub->right);
                        q2.push_back(rightsub->left);
                    }
                }else if(leftsub->right == NULL && rightsub->left == NULL){
                   
                }else if(leftsub->right == NULL || rightsub->left == NULL){
                    return false;
                }
                
            }
        }

        return true;

    }
};