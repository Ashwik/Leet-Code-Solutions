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
    bool findTarget(TreeNode* root, int k) {

        vector<int> v;
        stack<TreeNode*> st;

        while(!st.empty() || root!= NULL){
            if(root!=NULL){
                st.push(root);
                root = root->left;
            }else{
                root = st.top();st.pop();
                v.push_back(root->val);
                root = root->right;
            }
        }

        for(int i=0,j=v.size()-1;i<j;){
            if(v[i]+v[j]==k){return true;}
            else if(v[i]+v[j]>k){j--;}
            else{i++;}
        }
        return false;

    }

};