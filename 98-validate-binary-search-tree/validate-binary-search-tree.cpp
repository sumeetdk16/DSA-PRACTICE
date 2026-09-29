/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

class Solution {
public:
    bool isvalid(TreeNode* root, long minval, long maxval) {
        if (root == nullptr)
            return 1;

        if (root->val >= maxval || root->val <= minval)
            return 0;

        return isvalid(root->left, minval, root->val) &&
               isvalid(root->right, root->val, maxval);
    }
    bool isValidBST(TreeNode* root) {

        long minval = LONG_MIN;
        long maxval = LONG_MAX;
        
        return isvalid(root, minval, maxval);
    }
};
