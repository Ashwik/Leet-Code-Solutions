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
    int widthOfBinaryTree(TreeNode* root) {
        
        queue<pair<TreeNode*,long>> q;
        int ind;

        q.push({root,0});
        int ans = 0;
        int num;
        while(!q.empty()){
            int len = q.size();
            int st = q.front().second;
            int en = q.back().second;
            ans = max(ans,en-st+1);
            while(len--){
                root = q.front().first;
                num = q.front().second;
                q.pop();
                ind = num-st;
                if(root->left!=NULL){
                    q.push({root->left,(long long)2*ind});
                }
                if(root->right!=NULL){
                    q.push({root->right,(long long)2*ind+1});
                }

            }
            
        }
        return ans;


    }
};