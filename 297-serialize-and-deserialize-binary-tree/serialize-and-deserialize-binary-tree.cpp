/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:



    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string str = "";
        if(root==NULL){return str;}

        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int len = q.size();
            while(len--){
                root = q.front();q.pop();
                if(root==NULL){
                    str += "null,";
                    continue;
                }
                str += to_string(root->val) + ",";
                q.push(root->left);
                q.push(root->right);
            }
        }
        // cout<<str<<endl;
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> v;
        string str = "";
        for(int i=0;i<data.length();i++){
            if(data[i]==','){
                v.push_back(str);
                str = "";
            }else{
                str += data[i];
            }
        }
        if(str!=""){v.push_back(str);}
        // for(int i=0;i<v.size();i++){
        //     cout<<v[i]<<" "<<endl;
        // }

        if(v.size()==0 || v[0]=="null"){
            return NULL;
        }

        TreeNode* root = new TreeNode(stoi(v[0]));
        TreeNode* temp;
        queue<TreeNode*> q;
        q.push(root);
        int i = 1;
        while(!q.empty()){
            int len = q.size();
            while(len--){
                temp = q.front();q.pop();
                if(i==v.size()){return root;}
                if(v[i]!="null"){
                    temp->left = new TreeNode(stoi(v[i]));
                    q.push(temp->left);
                }
                i++;
                if(i==v.size()){return root;}
                if(v[i]!="null"){
                    temp->right = new TreeNode(stoi(v[i]));
                    q.push(temp->right);
                }
                i++;
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));