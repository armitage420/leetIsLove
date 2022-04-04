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
    void helper(TreeNode* root, vector<int>& res){
        if(root == NULL)
            return;
        
        stack<TreeNode*> recursion;
        stack<int> result;
        
        recursion.push(root);
        
        while(!recursion.empty()){
            TreeNode* currNode = recursion.top();
            recursion.pop();
            
            result.push(currNode->val);
            if(currNode->left)
                recursion.push(currNode->left);
            if(currNode->right)
                recursion.push(currNode->right);
        }
        
        while(!result.empty()){
            res.push_back(result.top());
            result.pop();
        }
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        
        vector<int> res;
        
        helper(root, res);
        return res;
    }
};