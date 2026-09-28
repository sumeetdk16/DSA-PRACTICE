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
    void morrisinorderTraversal(TreeNode* root, int& k, int& cnt, int& ans) {

        // vector<int> inorder;
        TreeNode* curr = root;
        while (curr) {
            if (curr->left == NULL) {
                // inorder.push_back(curr->val);
                cnt++;
                if (cnt == k)
                    ans = curr->val;
                curr = curr->right;
            } else {
                TreeNode* prev = curr->left;
                while (prev->right != nullptr && prev->right != curr)
                    prev = prev->right;

                if (prev->right == nullptr) // assign thread
                {
                    prev->right = curr;
                    curr = curr->left;
                } else // thread is assigned already
                {

                    cnt++;
                    if (cnt == k)
                        ans = curr->val;

                    prev->right = nullptr; // remove thread
                    curr = curr->right;
                }
            }
        }
    };
    int kthSmallest(TreeNode* root, int k) {
        int ans = 0;
        int cnt = 0;
        morrisinorderTraversal(root, k, cnt, ans);
        return ans;
    }
};
