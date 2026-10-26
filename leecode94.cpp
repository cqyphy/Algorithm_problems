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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        while (root)
        {
            if (root->left){
                TreeNode *mostRight = root->left;
                while ( mostRight->right != root && mostRight->right != nullptr) mostRight = mostRight->right;
                if (mostRight->right == root) {
                    v.push_back(root->val);
                    mostRight->right = nullptr;
                    root = root->right;
                }
                else if (mostRight->right == nullptr) {
                    mostRight->right = root;
                    root = root->left;
                }
            }
            else 
            {
                v.push_back(root->val);
                root = root->right;
            }
        }
        return v;
    }
};