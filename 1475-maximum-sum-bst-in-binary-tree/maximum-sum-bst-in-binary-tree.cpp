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

    
    vector<int> isValid(TreeNode* root, int &bstSum){

        if(root==NULL){return {INT_MAX,INT_MIN,0};}

        vector<int> leftTree = isValid(root->left, bstSum);
        vector<int> rightTree = isValid(root->right, bstSum);
        
        int val = root->val;
        
        if(leftTree.size()==0 || rightTree.size() == 0 || val <= leftTree[1] || val >= rightTree[0]){
            return {};
        }
        // for given root value it should between max value in leftsubtree and min value in right subtree

        int sum = val + leftTree[2] + rightTree[2];
        bstSum = max(sum,bstSum);
        
        int mi = min(val, leftTree[0]);// leftTree[0] has the minimum value in left sub tree
        int ma = max(val, rightTree[1]);// rightTree[1] has the maximum value in right sub tree

        return {mi,ma,sum};
    }

    int maxSumBST(TreeNode* root) {
        int bstSum = 0;
        isValid(root,bstSum);
        return bstSum;
    }
};