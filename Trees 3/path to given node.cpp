 #include<bits/stdc++.h>
 #include<vector>
 using namespace std;
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
bool findPath(TreeNode* root, int B,vector<int> &arr){
    if(root==NULL)
    return false;
    
    arr.push_back(root->val);
    
    if(root->val==B){
        return true;
    }
    if(findPath(root->left,B,arr)||findPath(root->right,B,arr)){
        return true;
    }
    arr.pop_back();
    return false;
}

vector<int> solve(TreeNode* A, int B) {
    vector<int> arr;
    if(A==NULL){
        return arr;
    }
    findPath(A,B,arr);
    return arr;
}