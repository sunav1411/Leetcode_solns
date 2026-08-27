/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int sum = 0;

    void Inorder(TreeNode* root)
    {
        if(root == NULL)
            return;

        // Visit larger values first
        Inorder(root->right);

        // Update running sum
        sum += root->val;

        // Replace current node value
        root->val = sum;

        // Process smaller values
        Inorder(root->left);
    }

    TreeNode* convertBST(TreeNode* root)
    {
        Inorder(root);
        return root;
    }
};