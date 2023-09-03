 #include <bits/stdc++.h> 
using namespace std;
 public:
    // return true/false denoting whether the tree is Symmetric or not
    bool isSymmetric(struct Node* root)
    {
	    // Code here
	    if(root==NULL)return true;
	    queue<Node*> q;
	    q.push(root->left);
	    q.push(root->right);
	    while(!q.empty()){
	        Node *l=q.front();
	        q.pop();
	        Node *r=q.front();
	        q.pop();
	        if(l==NULL && r==NULL)continue;
	        if(l==NULL || r==NULL || l->data!=r->data){
	            return false;
	        }
	        q.push(l->left);
	        q.push(r->right);
	        q.push(l->right);
	        q.push(r->left);
	        
	        
	    }
	    return true;
	    
	    
	    
    }