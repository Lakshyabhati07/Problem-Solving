#include<bits/stdc++.h>
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

private:
    void inorder(TreeNode *root, vector<int> &numbers){
        
        if(root==NULL)
        return ;

        inorder(root->left,numbers);
        numbers.push_back(root->val);
        inorder(root->right,numbers);

    }

    bool FindtwoSum(vector<int>& numbers, int target) {
        vector<int> ans;
            int i=0;
            int j=numbers.size()-1;

            while(i<j){
                if((numbers[i]+numbers[j])==target){
                return true;
                }

                else if((numbers[i]+numbers[j])>target){
                    j--;
                }
                else    i++;
            }
        return false;
    }
   
public:
    bool findTarget(TreeNode* root, int k) {
     //if k is even
        vector<int> ans;
        inorder(root,ans);
        return FindtwoSum(ans,k);
    }
};