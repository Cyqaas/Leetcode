struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *helper(TreeNode *root, TreeNode *p, TreeNode *q, int minVal, int maxVal)
{
    // case 1: the current root is bigger than p and q, thus they are in the left side of the subtree
    if (root->val > maxVal)
    {
        return helper(root->left, p, q, minVal, maxVal);
    }
    // case 2: the current root is smaller than p and q, thus they are in the right of the subtree
    else if (root->val < minVal)
    {
        return helper(root->right, p, q, minVal, maxVal);
    }
    // case 3: the current root is right in between, is equal to either p or q, thus the solution is found
    else if (minVal <= root->val <= maxVal)
    {
        return root; 
    }

    // in the instance no solution is found
    return nullptr;
}

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    // problem breakdown:
    // finding the lowest ancestor/parent of the two given nodes,
    // where they can be ancestor of themselves and the other given node

    // solution:
    // Go left and right depending if the current roots value is < or > the min or max since the BST is already sorted 
    int minVal = min(p->val, q->val);
    int maxVal = max(p->val, q->val);
    TreeNode *result = helper(root, p, q, minVal, maxVal);

    return result;
}
