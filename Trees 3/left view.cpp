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

  void leftview(TreeNode* root,int level,vector<int> &ans){

    if(root==NULL)
    return;

    if(ans.size()==level){
        ans.push_back(root->val);
    }

    leftview(root->left,level+1, ans);
    leftview(root->right,level+1, ans);

}

vector<int> printLeftView(TreeNode* root) {
    // Write your code here.
    vector<int> ans;
    int level=0;
    leftview(root,level, ans);
    return ans;

}