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
    pair<int,int> DFS(TreeNode*root,int &result)
    {
        if(root==NULL)
        return {0,0};

        pair<int,int>P1=DFS(root->left,result);
        pair<int,int>P2=DFS(root->right,result);

        int totalSum=P1.first +P2.first+root->val;
        int totalCount=P1.second+P2.second+1;

        int avg=totalSum/totalCount;

        if(root->val==avg)
        {
            result++;
        }

        return {totalSum,totalCount};

    }
    int averageOfSubtree(TreeNode* root) {
        int result=0;
        
        DFS(root,result);

        return result;
    }
};