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
        TreeNode* temp;

        while(!st.empty()|| root!=NULL){
            if(root!=NULL){
                temp = root;
                if(root->right!=NULL){
                    st.push(root->right);
                }
                // cout<<root->val<<" "<<endl;
                root->right = root->left;
                root->left = NULL;
                root = root->right;
            }else if(!st.empty()){
                root = st.top();st.pop();
                temp->right = root;
            }
            
        }
     }
};