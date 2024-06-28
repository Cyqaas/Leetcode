int helper(TreeNode *root)
{
    // return 0 when null nodes are reached
    if (root == NULL)
    {
        return 0;
    }

    // calculate the left and right height then find the difference between the two
    int left = helper(root->left);
    int right = helper(root->right);
    int difference = abs(left - right);

    // return -1 in the instances
    // a_ we reached a bigger difference than 1 in the left subtree
    // b_ we reached a bigger difference than 1 in the right subrree
    // c_ the current difference is greated than 1
    if (left == -1 || right == -1 || difference > 1) 
    {
        return -1; 
    }

    // otherwise, return the max of the left and right if the difference is < 1 and add 1 to the height
    // since we are traversing from the bottom up. Without the +1 the height will never grow. 
    return max(left, right) + 1;
}

bool isBalanced(TreeNode *root)
{
    // in the instance the root is null
    if (root == NULL)
    {
        return true;
    }
    // gather the result then return if the result was successful
    int result = helper(root);
    return result != -1; 
}
