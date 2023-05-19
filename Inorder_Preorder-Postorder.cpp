class Solution
{
    
    public static int index = 0;
    
    public static int findposition(int in[] , int ele , int n)
    {
        int i;
        for(i=0;i<n;i++)
        {
            if(in[i] == ele)
                return i;
        }
        
        return -1;
        
    }
    
    public static Node solve(int in[] , int pre[] , int index , int inst , int inend ,int n)
    {
        
        if(index >= n || inst > inend)
        {
            return null;
        }
        
        int element = pre[index++];
        
        Node root = new Node(element);
        
        int position = findposition(in , element , n);
        
        //recursive call
        
        root.left = solve(in , pre , index , inst , position-1 , n);
        root.right = solve(in , pre , index , position+1 , inend , n);
        
        return root;
        
    }
    
    public static Node buildTree(int in[], int pre[], int n)
    {
        // code here 
        
        Node ans = solve(in , pre , index , 0 , n-1 , n);
        
        return ans;
        
    }
}

