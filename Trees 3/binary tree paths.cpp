 #include<bits/stdc++.h>
 #include<vector>
 using namespace std;
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

  class Solution {
public:
    void findPath(TreeNode* root,string s,vector<string> &st){
        if(root==NULL)
            return;
            
           s+=to_string(root->val)+"->";
            if(root->left==NULL && root->right==NULL){
                    s.pop_back();
                    s.pop_back();
                     st.push_back(s);
                return;
            }                  
            findPath(root->left,s,st);  
            findPath(root->right,s,st);   
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> st;
        string s="";
        findPath(root,s,st);
        return st;
    }
};