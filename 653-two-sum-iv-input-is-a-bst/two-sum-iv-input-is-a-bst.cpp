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
    void inorder(TreeNode* root, vector<int>& arr) {

        // if(root==nullptr) return;
        while (root) {
            if (root->left == nullptr) {
                {
                    arr.push_back(root->val);
                    root = root->right;
                }
            } else {
                TreeNode* prev = root->left;

                while (prev->right != nullptr && prev->right != root)
                    prev = prev->right;

                if (prev->right == nullptr) {
                    prev->right = root; // assign thread
                    root = root->left;
                } else {
                    arr.push_back(root->val);

                    prev->right = nullptr; // remove thread
                    root = root->right;
                }
            }
        }
    }

    bool findTarget(TreeNode* root, int k) {

        vector<int> arr;
        inorder(root, arr);
        int l = 0, r = arr.size() - 1;

        while (l < r) {
            if (arr[l] + arr[r] > k)
                r--;
            else if (arr[l] + arr[r] < k)
                l++;
            else
                return 1;
        }
        return 0;
    }
};