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
    string startPath;
    string destPath;
public:
bool dfs(TreeNode* root, int startValue, bool start) {
        if (root == NULL) return false;
        if (root->val == startValue) return true;
        bool left = dfs(root->left, startValue, start);
        if (left) {
            if (start) startPath += "L";
            else destPath += "L";
            return true;
        }
        bool right = dfs(root->right, startValue, start);
        if (right) {
            if (start) startPath += "R";
            else destPath += "R";
            return true;
        }
        return false;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
         dfs(root, startValue, true);
        dfs(root, destValue, false);
        reverse(startPath.begin(), startPath.end());
        reverse(destPath.begin(), destPath.end());
        int i = 0, j = 0;
        while (i < startPath.length() && j < destPath.length()) {
            if (startPath[i] == destPath[j]) {
                i++;
                j++;
            }
            else {
                break;
            }
        }
        string sb;
        while (i < startPath.length()) {
            sb += "U";
            i++;
        }
        sb += destPath.substr(j);
        return sb;
        
    }
};