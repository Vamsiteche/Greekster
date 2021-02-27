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
 //https://leetcode.com/problems/subtree-of-another-tree/solution/
class Solution {
public:
    bool helper(TreeNode* s,TreeNode* t)
    {
        if(s==nullptr&&t==nullptr)
            return true;
        if(s==nullptr||t==nullptr)
            return false;
        if(s->val==t->val)
        {
            return helper(s->left,t->left) && helper(s->right,t->right);
        }
        return false;
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(s==nullptr&&t==nullptr)
            return true;
        if(s==nullptr||t==nullptr)
            return false;
        bool temp=false;
        if(s->val==t->val)
        {
            temp=helper(s,t);
        }
        if(temp)
            return true;
        return isSubtree(s->left,t)||isSubtree(s->right,t);
        
    }
};
