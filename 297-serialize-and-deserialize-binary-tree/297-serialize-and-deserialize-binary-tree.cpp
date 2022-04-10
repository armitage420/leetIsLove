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
        string res = "";
        
        if(root == NULL)
            return res;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int s = q.size();
            
            for(int i=0; i<s; i++){
                TreeNode* temp = q.front();
                q.pop();
                if(temp == NULL)
                    res+="#,";
                else
                    res += to_string(temp->val) + ",";
                if(temp){
                    q.push(temp->left);
                    q.push(temp->right);
                }
            }
        }
        
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0)
            return NULL;
        
        stringstream s(data);
        string str;
        getline(s, str, ',');
        
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            
            getline(s, str, ',');
            
            if(str == "#"){
                node->left = NULL;
            }else{
                TreeNode* l = new TreeNode(stoi(str));
                node->left = l;
                q.push(node->left);
            }
            
            getline(s, str, ',');
            if(str == "#"){
                node->right = NULL;
            }else{
                TreeNode* r = new TreeNode(stoi(str));
                node->right = r;
                q.push(node->right);
            }
        }
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));