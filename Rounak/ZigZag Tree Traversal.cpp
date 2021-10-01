class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL){
            return ans;
        }
        queue<TreeNode*> q;
        bool leftToRight=true;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector<int> res(n);
            for(int i=0;i<n;i++){
                TreeNode* temp=q.front();
                q.pop();
                int pos=leftToRight?i:n-i-1;
                res[pos]=temp->val;
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
            leftToRight=!leftToRight;
            ans.push_back(res);
        }
        return ans;
    }
};
