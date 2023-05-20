class Solution {
public:
     int ans;
    void solve(TreeNode *root,int &count, int k){
        if(root==NULL)
            return;
       
       solve(root->left,count,k);
       if(k==count) 
       {
           ans=root->val;
            count++;
           return;
          
       }
       else count++;
       solve(root->right,count,k);
       
       
    }
    int kthSmallest(TreeNode* root, int K) {
         ans=-1;
        int count=1;
      solve(root,count,K);
      return ans;
    }
};

