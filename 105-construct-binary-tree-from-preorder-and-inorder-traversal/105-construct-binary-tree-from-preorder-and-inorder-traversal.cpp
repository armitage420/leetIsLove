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
    TreeNode* helper(vector<int>& preorder, int pstart, int pend, vector<int>& inorder, int istart, int iend, map<int, int>& mpp){
        if(pstart > pend || istart > iend){
            return NULL;
        }
        
        TreeNode* root = new TreeNode(preorder[pstart]);
        
        int iroot = mpp[root->val];
        int ileft = iroot - istart;
        
        root->left = helper(preorder, pstart+1, pstart+ileft, inorder, istart, iroot-1, mpp);
        root->right = helper(preorder, pstart+ileft+1, pend, inorder, iroot+1, iend, mpp);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> mpp;
        
        for(int i=0; i<inorder.size(); i++){
            mpp[inorder[i]] = i;
        }
        
        TreeNode* root = helper(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, mpp);
        
        return root;
    }
};