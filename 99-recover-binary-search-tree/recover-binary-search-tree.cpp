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
    TreeNode *first, *middile, *last, *prev;

    void inorder(TreeNode* root) {

        if (root == nullptr)
            return;

        inorder(root->left); // left

        // root
        if (prev != nullptr && root->val < prev->val) {
            // 1st violation
            if (first == nullptr) {
                first = prev;
                middile = root;
            }
            // 2nd violation
            else {
                last = root;
            }
        }

        prev = root;
        inorder(root->right); // right
    }

    void recoverTree(TreeNode* root) {

        first = middile = last = nullptr;

        prev = new TreeNode(INT_MIN);

        inorder(root);

        if (first && last)
            swap(first->val, last->val);
        else if (first && middile)
            swap(first->val, middile->val);
    }
};