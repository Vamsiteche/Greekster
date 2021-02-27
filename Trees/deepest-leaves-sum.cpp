//https://leetcode.com/problems/deepest-leaves-sum/
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
    int max_level=0;
    int sum=0;
    void helper(TreeNode* root,int h)
    {
        if(root==nullptr)
            return;
        if(h==max_level)
            sum+=root->val;
        else if(h>max_level)
        {
            sum=root->val;
            max_level=h;
        }
        helper(root->left,h+1);
        helper(root->right,h+1);
    }
    int deepestLeavesSum(TreeNode* root) {
        max_level=0;
        sum=0;
        helper(root,0);
        return sum;
            
    }
};
