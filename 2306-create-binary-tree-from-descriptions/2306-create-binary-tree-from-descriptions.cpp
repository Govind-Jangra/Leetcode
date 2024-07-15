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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_set<int> st;
        for(auto it:descriptions){
            st.insert(it[0]);
        }
        unordered_map<int,TreeNode*> mp;
        for(auto it:descriptions){
            auto p=it[0],c=it[1],l=it[2];
            st.erase(c);
            TreeNode *pa,*ch;
            if(mp.find(p)==mp.end()) pa=new TreeNode(p);
            else pa=mp[p];

            if(mp.find(c)==mp.end()) ch=new TreeNode(c);
            else ch=mp[c];

            if(l==0){
                pa->right=ch;
            }
            else pa->left=ch;
            mp[c]=ch;
            mp[p]=pa;
        }
        return mp[*st.begin()];
    }
};