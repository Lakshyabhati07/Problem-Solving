 #include<bits/stdc++.h>
 using namespace std;
 
 template <typename T>
    class TreeNode
    {
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data)
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode()
        {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

bool isLeaf(TreeNode<int> *node){
    //return !root->left  && !root->right;
    if(node->left==NULL && node->right == NULL) return true;
    return false;
}

void leftboundary(vector<int> &ans,TreeNode<int> *root){
    TreeNode<int>* curr=root->left;
    while(curr){
        if(!isLeaf(curr)){
            ans.push_back(curr->data);
        }

        if(curr->left)  curr=curr->left;
        //if there is no left exist in left subtree
        else curr=curr->right;
        
    }
}

void rightBoundary(vector<int> &ans,TreeNode<int>* root){
     TreeNode<int>* curr=root->right;
     vector<int> res;
     while(curr){
        if (!isLeaf(curr)) {
            res.push_back(curr->data);
        }

        if (curr->right)
            curr = curr->right;

        else
            curr = curr->left;
     }
 //    reverse(res.begin(),res.end());
         for(int i=res.size()-1;i>=0;i--){
             ans.push_back(res[i]);
         
     }
}

void leaf(vector<int> &ans,TreeNode<int> *root){
   
    if(isLeaf(root)){
        ans.push_back(root->data);
        return;
    }

    if(root->left)  leaf(ans,root->left);
    if(root->right) leaf(ans,root->right);

}


vector<int> traverseBoundary(TreeNode<int> *root)
{

    vector<int> ans;
    if(!root) return ans;
   if(!isLeaf(root)) ans.push_back(root->data);
   leftboundary(ans,root);
    leaf(ans,root);
    rightBoundary(ans,root);

    return ans;
	// Write your code here.
}
