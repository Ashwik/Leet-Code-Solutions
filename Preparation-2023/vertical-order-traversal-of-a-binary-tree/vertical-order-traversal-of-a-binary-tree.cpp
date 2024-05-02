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

    vector<vector<int>> verticalTraversal(TreeNode* root) {

        map<int,vector<int>> mp;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        int node;

        while(!q.empty()){
            int len = q.size();
            vector<pair<int,int>> v;
            while(len--){
                root = q.front().first;
                node = q.front().second;
                q.pop();
                v.push_back({root->val,node});
                if(root->left!=NULL){
                    q.push({root->left,node-1});
                }
                if(root->right!=NULL){
                    q.push({root->right,node+1});
                }
            }
            sort(v.begin(),v.end());
            for(int i=0;i<v.size();i++){
                mp[v[i].second].push_back(v[i].first);
            }
        }

        vector<vector<int>> ans;
        for(auto it=mp.begin();it!=mp.end();it++){
            ans.push_back(it->second);
        }
        return ans;

    }
};