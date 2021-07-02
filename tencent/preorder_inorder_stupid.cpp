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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int len = preorder.size();
        if(len==0)  return nullptr;
        int root_idx = find(inorder.begin(),inorder.end(),preorder[0]) - inorder.begin();   //root在中序遍历的index
        vector<int> pre_left,pre_right,in_left,in_right;
        for(int i = 0;i<root_idx;i++)
        {
            in_left.insert(in_left.end(),inorder[i]);
        }
        for(int i = root_idx+1;i<len;i++)
        {
            in_right.insert(in_right.end(),inorder[i]);
        }
        for(int i = 1;i<=root_idx;i++)
        {
            pre_left.insert(pre_left.end(),preorder[i]);
        }
        for(int i = root_idx+1;i<len;i++)
        {
            pre_right.insert(pre_right.end(),preorder[i]);
        }
        TreeNode* root = new TreeNode(preorder[0]);
        root->left = buildTree(pre_left,in_left);
        root->right = buildTree(pre_right,in_right);
        return root;
    }
};
