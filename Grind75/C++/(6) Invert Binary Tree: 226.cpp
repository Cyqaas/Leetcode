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
    void swapNodes(TreeNode* node)
    {
        if (node == nullptr)
        {
            return; 
        }
        else 
        {
            TreeNode* temp; 

            // do subtrees of the current node
            swapNodes(node->left);
            swapNodes(node->right);

            // swap the nodes
            temp = node->left; 
            node->left = node->right; 
            node->right = temp; 
        }
    }

    TreeNode* invertTree(TreeNode* root) {
        // start time: 1:44pm 
        // end time: 2:20pm

        // problem breakdown: 
        // root stays the same while the immediate left and right child of 
        // root are swapped; child nodes of children nodes are also inverted

        // possible solution(s): 
        // recursively go through the tree by starting with the left side
        // then the right, eventually reaching nullptr leaf nodes. Then swap 
        // the left and right nodes
        swapNodes(root);

        return root;
    }
};
