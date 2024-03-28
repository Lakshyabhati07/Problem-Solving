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
    int pathSum(TreeNode* root, int targetSum) {
        int ans = 0;
        unordered_map<int, int> count;
        count[targetSum] = 1;
        dfs(root, 0, ans, count, targetSum);
        return ans;
    }
    
    void dfs(TreeNode* node, int curr, int& ans, unordered_map<int, int>& count, int targetSum) {
        if (!node) return;
        curr += node->val;
        ans += count[curr];
        count[curr + targetSum]++;
        
        dfs(node->left, curr, ans, count, targetSum);
        dfs(node->right, curr, ans, count, targetSum);
        
        count[curr + targetSum]--;
    }
};


