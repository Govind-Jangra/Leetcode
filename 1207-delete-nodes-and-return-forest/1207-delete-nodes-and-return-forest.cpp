class Solution {
public:
    
    vector<TreeNode*> ans;
    set<int> st;
    
    void solve (TreeNode* &root)
    {
        if(root!=NULL)
        {
            solve(root->left);
            solve(root->right);
            if(st.find(root->val)!=st.end())
            {
                if(root->left)  ans.push_back(root->left);
                if(root->right) ans.push_back(root->right);
                root=NULL;
				delete root;
            }
        }
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
	
        for(int i=0;i<to_delete.size();i++)
            st.insert(to_delete[i]);
        solve(root);
        if(root)
            ans.push_back(root);
        return ans;
    }
};