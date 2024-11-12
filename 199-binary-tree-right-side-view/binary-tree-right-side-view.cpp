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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root==NULL){return ans;}
        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty()){
            int len = q.size();
            while(len--){
                root = q.front();
                q.pop();
                if(len==0){
                    ans.push_back(root->val);
                }
                if(root->left){q.push(root->left);}
                if(root->right){q.push(root->right);}
            }
        }
        return ans;
    }
};