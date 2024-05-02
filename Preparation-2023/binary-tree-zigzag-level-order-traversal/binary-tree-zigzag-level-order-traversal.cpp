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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> ans;
        if(root==NULL){return ans;}

        queue<TreeNode*> q;
        q.push(root);
        bool flag = true;
        

        while(!q.empty()){
            int len = q.size();
            vector<int> v(len);
            int ind = 0;
            int num = len;
            while(len--){
                root = q.front();
                q.pop();
                if(flag){
                    v[ind] = root->val;
                }else{
                    v[num-ind-1] = root->val;
                }
                if(root->left!=NULL){
                    q.push(root->left);
                }
                if(root->right!=NULL){
                    q.push(root->right);
                }
                ind++;
            }
            flag = !flag;
            ans.push_back(v);
        }
        return ans;

    }
};