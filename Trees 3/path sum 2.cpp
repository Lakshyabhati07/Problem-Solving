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
    vector<vector<int>> ans;
    vector<int> store;
    void Sum(TreeNode * root, int target,int sum){


        if(root==NULL)
        return;

        store.push_back(root->val);
        sum+=root->val;

        if(sum==target && root->left==NULL&& root->right==NULL){
            ans.push_back(store);
       }

    Sum(root->left,target,sum);
    Sum(root->right,target,sum);
    store.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
       Sum(root,targetSum,0);
        return ans;
    }
};