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
    int ans = 0;
    void solve(TreeNode* root, int curr){
        if(!root->left && !root->right){
            ans+=curr;
            return ;
        }
        if(root->left){
            solve(root->left, curr*2+root->left->val);
        }
        if(root->right){
            solve(root->right, curr*2+root->right->val);
        }
    }
    int sumRootToLeaf(TreeNode* root) {
        solve(root, root->val);
        return ans;
    }
};
