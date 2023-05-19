#include<iostream>

#include<queue>

using namespace std;

class Node
{
    public:
    
    int data;
    Node* left;
    Node* right;
    
    Node(int d)
    {
      this->data = data;
      this->left =  NULL;
      this->right = NULL;
    }
    
};

void LevelOrderQ( Node* root)
{
    if(root == NULL)  return; 
    
    queue< Node * > q;              //create empty Queue
    
    q.push(root);                   //enqueue root
    
    while(!q.empty())
    {
        // Print front of queue and remove it from queue
        
        Node* node = q.front();
        cout<< node->data << " ";
        q.pop();
        
        //enqueue Left child
        
        if(node->left != NULL)
            q.push(node->left);
        
        //enqueue right child
        
        if(node->right != NULL)
            q.push(node->right);
    }
}

Node* InsertInBst(Node* root,int d)
{
    // base case
    if(root==NULL)
    {
        root =  new Node(d);
        return root;
    }
    
    if(d>root->data)
    {
        // move to righ part in tree 
        root->right =  InsertInBst(root->right,d);
    }
    else
    {
        // move to left part in tree
        root->left = InsertInBst(root->left,d);
    }
    
    return root;
}

void takeInput(Node* &root)
{
    int data;
    cin>>data;
    
    while(data!=-1)
    {
        root = InsertInBst(root,data);
        cin>>data;
    }
}

int main()
{
    
    Node* root = NULL;
    
    cout<<"Enter the elements to create BST :- "<<endl;
    takeInput(root);
    
    cout<<"After Level order traversal elements are :- "<<endl;
    LevelOrderQ(root);
    

    return 0;
}
