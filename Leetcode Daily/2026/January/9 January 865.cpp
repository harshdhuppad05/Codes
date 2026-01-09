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
    unordered_map<TreeNode*, TreeNode*> parent;
    unordered_map<TreeNode*, int> depth;
    int maxDepth = 0;

    void dfs(TreeNode* node, TreeNode* par, int d) {
        if (!node) return;

        parent[node] = par;
        depth[node] = d;
        maxDepth = max(maxDepth, d);

        dfs(node->left, node, d + 1);
        dfs(node->right, node, d + 1);
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        dfs(root, nullptr, 0);

        // collect all deepest nodes
        vector<TreeNode*> curr;
        for (auto &it : depth) {
            if (it.second == maxDepth) {
                curr.push_back(it.first);
            }
        }

        // move up until only one node remains
        while (curr.size() > 1) {
            unordered_set<TreeNode*> next;
            for (TreeNode* node : curr) {
                if (parent[node]) {
                    next.insert(parent[node]);
                }
            }
            curr.assign(next.begin(), next.end());
        }

        return curr[0];
    }
};
