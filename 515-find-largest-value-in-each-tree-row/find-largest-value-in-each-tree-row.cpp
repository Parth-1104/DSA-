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
    vector<int> largestValues(TreeNode* root) {
        if(root==NULL)
        return {};

        queue<TreeNode*>q;
        vector<int>result;
        q.push(root);
        
        while(!q.empty())
        {
            int n=q.size();
            int maxVal=INT_MIN;
            while(n--)
            {
                TreeNode* front =q.front();
                q.pop();
                maxVal=max(maxVal,front->val);

                if(front->left!=NULL)
                {
                    q.push(front->left);
                }
                if(front->right!=NULL)
                {
                    q.push(front->right);
                }

            }
            result.push_back(maxVal);


        }

        return result;
    }
};