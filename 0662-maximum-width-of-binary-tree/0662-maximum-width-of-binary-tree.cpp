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
int bfs(TreeNode* root){
    if(root==nullptr) return 0;

    queue<pair<TreeNode*,long long>> q;
    q.push({root,1});
    long long maxi=0;

    while(!q.empty()){
        int n=q.size();
        long long pehla=q.front().second;
        long long last=pehla;

        while(n--){
            TreeNode* node=q.front().first;
            long long pos=q.front().second-pehla;
            q.pop();

            last=pos;

            if(node->left)
                q.push({node->left,2*pos});
            if(node->right)
                q.push({node->right,2*pos+1});
        }

        maxi=max(maxi,last+1);
    }
    return maxi;
}

int widthOfBinaryTree(TreeNode* root){
    return bfs(root);
}
};