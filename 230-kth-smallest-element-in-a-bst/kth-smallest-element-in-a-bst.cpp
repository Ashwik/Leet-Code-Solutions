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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;

        while(!st.empty() || root != NULL){
            while(root!=NULL){
                st.push(root);
                root = root->left;
            }
            root = st.top();
            st.pop();
            k--;
            if(k==0){return root->val;}
            root = root->right;
        }
        return -1;
    }
};