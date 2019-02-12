/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    string smallestFromLeaf(TreeNode* root) {
        //在本题中，因为题目要求从树叶到树根，用递归做
        if(root == NULL){
            return "";//如果为空，则什么也不返回
        }//if(root->val!=NULL)
        const char v = static_cast<char>('a' + root->val);//将数字转换为对应的字母；
        string l = smallestFromLeaf(root->left);//递归调用左子树
        string r = smallestFromLeaf(root->right);//递归调用右子树
        if(l.empty()) return r + v;//如果右子树空，则字典序最小序列为右子树的最小字典序和根相加
        if(r.empty()) return l + v;
        return min(l,r) + v;//总的最小为跟加上左右子树的最小字典序
        
        
    }
};
