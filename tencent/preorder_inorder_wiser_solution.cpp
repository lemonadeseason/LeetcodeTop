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
    unordered_map<int,int> hash;   //为了方便从vector中找到root的下标
    
    TreeNode* buildTree_recursive(vector<int>& preorder, vector<int>& inorder,int pre_start,int pre_end,int in_start,int in_end)
    {
        if(pre_start>pre_end) return nullptr;
        int root_val = preorder[pre_start];
        int root_idx = hash[root_val];    //在inorder中，root的index
        int left_len = root_idx - in_start;
        return new TreeNode(root_val,buildTree_recursive(preorder,inorder,pre_start+1,pre_start+left_len,in_start,in_start+left_len),buildTree_recursive(preorder,inorder,pre_start+left_len+1,pre_end,root_idx+1,in_end));
    } 

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int len = preorder.size();
        for(int i = 0;i<len;i++)
        {
            hash[inorder[i]] = i;
        }
        return buildTree_recursive(preorder,inorder,0,len-1,0,len-1);
    }
};
