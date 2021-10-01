//https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> m;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty()){
            TreeNode* temp=q.front().first;
            int idx=q.front().second.first;
            int level=q.front().second.second;
            m[idx][level].insert(temp->val);
            q.pop();
            if(temp->left){
                q.push({temp->left,{idx-1,level+1}});
            }
            if(temp->right){
                q.push({temp->right,{idx+1,level+1}});
            }
        }
        vector<vector<int>> ans;
        for(auto p:m){
            vector<int> res;
            for(auto q:p.second){
                res.insert(res.end(),q.second.begin(),q.second.end());
                // for(auto r:q.second){
                //     res.push_back(r);
                // }
            }
            ans.push_back(res);
        }
        return ans;
    }
};
