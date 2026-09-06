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
int height(TreeNode* root){
    if(root==NULL) return 0;
    return 1+max(height(root->left),height(root->right));
}

void banao(vector<vector<string>>& ans,TreeNode* root,int row,int col,int h){
    if(root==NULL) return;

    ans[row][col]=to_string(root->val);

    if(root->left||root->right){
        int gap=1<<(h-row-2);

        if(root->left)
            banao(ans,root->left,row+1,col-gap,h);

        if(root->right)
            banao(ans,root->right,row+1,col+gap,h);
    }
}

vector<vector<string>> printTree(TreeNode* root){
    int h=height(root);
    int n=(1<<h)-1;

    vector<vector<string>> ans(h,vector<string>(n,""));
    banao(ans,root,0,(n-1)/2,h);

    return ans;
}
};