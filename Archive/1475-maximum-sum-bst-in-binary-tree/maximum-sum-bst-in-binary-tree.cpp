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

    struct Node{
        int minVal;
        int maxVal; 
        int sum;
        Node(int minVal,int maxVal,int sum){
            this->minVal = minVal;
            this->maxVal = maxVal;
            this->sum = sum;
        }
    };
    
    Node* isValid(TreeNode* root, int &bstSum){

        if(root==NULL){return new Node(INT_MAX,INT_MIN,0);}

        Node* leftTree = isValid(root->left, bstSum);
        Node*  rightTree = isValid(root->right, bstSum);
        
        int val = root->val;
        
        if(leftTree == NULL || rightTree == NULL || val <= leftTree->maxVal || val >= rightTree->minVal){
            return NULL;
        }
        // for given root value it should between max value in leftsubtree and min value in right subtree

        int sum = val + leftTree->sum + rightTree->sum;
        bstSum = max(sum,bstSum);
        
        int mi = min(val, leftTree->minVal);// leftTree[0] has the minimum value in left sub tree
        int ma = max(val, rightTree->maxVal);// rightTree[1] has the maximum value in right sub tree

        return new Node(mi,ma,sum);
    }

    int maxSumBST(TreeNode* root) {
        int bstSum = 0;
        isValid(root,bstSum);
        return bstSum;
        // bottom up solution
    }
};