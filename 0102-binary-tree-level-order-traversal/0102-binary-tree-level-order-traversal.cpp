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
    void levelorder1(TreeNode* root,vector<vector<int>>& v1,int level){
    if(root==NULL){
            return;
                }
            if (root->left != NULL || root->right != NULL) {
            while (v1.size() <= level) {
                v1.push_back({});
            }
        }



            if(root->left!=NULL && root->right!=NULL){
                v1[level].push_back(root->left->val);
                v1[level].push_back(root->right->val);
            }
            if(root->left!=NULL && root->right==NULL ){
               v1[level].push_back(root->left->val);
            }
            if(root->right!=NULL && root->left==NULL ){
                v1[level].push_back(root->right->val);
            }
            levelorder1(root->left,v1,level+1);
            levelorder1(root->right,v1,level+1);

    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> v1;
        levelorder1(root,v1,0);
        if(root!=NULL){
        v1.insert(v1.begin(),{root->val});
        }
        
        return v1;
    }
};