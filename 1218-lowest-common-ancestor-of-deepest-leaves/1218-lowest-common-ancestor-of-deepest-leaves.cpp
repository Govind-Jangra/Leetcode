class Solution {
public:
    unordered_set <TreeNode*> m;
    int n;
    TreeNode *ans = NULL;
    
    int solve(TreeNode *root)
    {
        if(!root or ans) return 0;
        
        int left = solve(root->left);
        int right = solve(root->right);
        
        int x = left+right;
        
        if(m.find(root)!=m.end())
        x++;
        
        if(x==n and !ans)
        ans = root;
        
        return x;
    }
    
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        queue<TreeNode*> q, temp;
        q.push(root);
        
        while(q.size())
        {
            temp = q;
            int n = q.size();
            for(int i = 0;i<n;i++)
            {
                TreeNode *r = q.front();
                q.pop();
                
                if(r->left)
                q.push(r->left);
                
                if(r->right)
                q.push(r->right);
            }
        }
        
        while(temp.size())
        {
            m.insert(temp.front());
            temp.pop();
        }
        n = m.size();
        
        solve(root);
        return ans;
    }
};