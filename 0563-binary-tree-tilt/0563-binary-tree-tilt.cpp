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
class Solution{
    int total=0;
public:
    int find(TreeNode* node){
        if(!node) return 0;

        int cur=node->val;
        int left=find(node->left);
        int right=find(node->right);

        node->val=abs(left-right);
        total+=node->val;

        return cur+left+right;
    }

    int findTilt(TreeNode* root){
        find(root);
        return total;
    }
};