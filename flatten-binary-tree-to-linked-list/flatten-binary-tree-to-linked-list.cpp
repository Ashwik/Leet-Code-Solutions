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
        stack<TreeNode*> st;
        TreeNode* cur = root;

        while(!st.empty()||cur!=NULL){
            if(cur!=NULL){
                if(cur->right!=NULL){
                    st.push(cur->right);
                }
                root = cur;
                cur = cur->left;
                root->right = cur;
                root->left = NULL;
            }else{
                cur = st.top();st.pop();
                root->right = cur;
            }
        }

    }
};