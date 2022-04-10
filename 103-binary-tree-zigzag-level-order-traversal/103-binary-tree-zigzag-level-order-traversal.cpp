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
        vector<vector<int>> res;
        
        if(root == NULL)
            return res;
        queue<TreeNode*> q;
        q.push(root);
        bool flag = 0;
        
        while(!q.empty()){
            vector<int> v;
            int s = q.size();
            
            for(int i = 0; i < s; i++){
                TreeNode* node = q.front();
                q.pop();
                
                if(flag)
                    v.insert(v.begin(), node->val);
                else
                    v.push_back(node->val);


                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            
        res.push_back(v);
        flag = !flag;
        
        }
        
        
        return res;
    }
    
    
};