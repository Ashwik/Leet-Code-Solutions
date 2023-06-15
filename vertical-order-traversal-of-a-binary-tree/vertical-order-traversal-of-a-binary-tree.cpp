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
            unordered_map<int,vector<int>> temp;
            while(len--){
                root = q.front().first;
                node = q.front().second;
                q.pop();
                temp[node].push_back(root->val);
                if(root->left!=NULL){
                    q.push({root->left,node-1});
                }
                if(root->right!=NULL){
                    q.push({root->right,node+1});
                }
            }
            for(auto it=temp.begin();it!=temp.end();it++){
                sort(it->second.begin(),it->second.end());
                for(int i=0;i<it->second.size();i++){
                    mp[it->first].push_back(it->second[i]);
                }
            }
        }

        vector<vector<int>> ans;
        for(auto it=mp.begin();it!=mp.end();it++){
            ans.push_back(it->second);
        }
        return ans;

    }
};