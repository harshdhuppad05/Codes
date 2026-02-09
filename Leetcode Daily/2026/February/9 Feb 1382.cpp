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
    vector<int> arr;
    void inorder(TreeNode *root){
        if(!root)return;
        if(root->left)inorder(root->left);
        arr.push_back(root->val);
        if(root->right)inorder(root->right);
    }
    TreeNode* make_tree(int l, int r){
        if(l>r)return NULL;
        int mid = (l+r)/2;
        TreeNode *root =new TreeNode(arr[mid]);
        root->left = make_tree(l, mid-1);
        root->right = make_tree(mid+1, r);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        if(!root)return NULL;
        inorder(root);
        int n = arr.size();
        return make_tree(0,n-1);
    }
};
