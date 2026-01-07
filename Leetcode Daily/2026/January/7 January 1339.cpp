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
    long long ans = 0;
    long long total_sum = 0;
    const int MOD = 1e9+7;
    long long get_total_sum(TreeNode* root){
        if(!root)return 0;
        return total_sum = root->val+get_total_sum(root->left)+get_total_sum(root->right);
    }
    long long max_product_sum(TreeNode* root){
        if(!root)return 0;
        long long curr_sum = root->val+max_product_sum(root->left)+max_product_sum(root->right);
        ans= max(ans, curr_sum*(total_sum-curr_sum));
        return curr_sum;
    }
    int maxProduct(TreeNode* root) {
        get_total_sum(root);
        max_product_sum(root);
        return ans%MOD;
    }
};
